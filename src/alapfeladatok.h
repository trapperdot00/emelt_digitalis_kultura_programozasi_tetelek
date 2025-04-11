#ifndef ALAPFELADATOK_H
#define ALAPFELADATOK_H

#include <cstddef>
#include <utility>

namespace csrb {

// Sorozat előállítása az általános képlet alapján
// Paraméterek:
// 	i: kezdő érték, egyesével nő, amíg kisebb mint j
// 	j: utolsó érték
//	dest: kimeneti iterátor, egy lista első írható elemére mutat,
//		minden írásnál nő eggyel az értéke
//	op: egy size_t paraméterrel meghívható funkció, az i-vel
//		meghívott visszatérési értéke kerül be a dest által
//		mutatott helyre
// A memória túlcímezés veszélye fennáll abban az esetben, ha
// j és i különbsége nagyobb, mint a dest által mutatott
// és az utánalévő létező allokált memóriahelyek darabszáma,
// erre nincs kivételkezelés, erre a felhasználónak kell figyelnie
// Visszatérési érték: az utolsó elem utáni memóriacímre mutató
// 	iterátor a dest által mutatott listában
template <class OutputIt, class UnaryOp>
OutputIt sorozatszamitas
(size_t i, size_t j, OutputIt dest, UnaryOp op) {
	while (i < j)
		*dest++ = op(i++);
	return dest;
}

// Sorozat előállítása a rekurziós képlet alapján
// Paraméterek:
// 	i: kezdő érték, egyesével nő, amíg kisebb mint j
// 	j: utolsó érték
// 	dest: kimeneti iterátor, egy lista első írható elemére mutat,
// 		minden írásnál nő eggyel az értéke
// 	first: az első elem értéke a listában
// 	op: egy size_t és egy T típusú paraméterrel meghívható funkció,
// 		az i-vel és a lista jelenlegi utolsó elemével meghívott
// 		visszatérési értéke lesz a lista következő elemének értéke
// A memória túlcímezés veszélye fennáll abban az esetben, ha
// j és i különbsége nagyobb, mint a dest által mutatott
// és az utánalévő létező allokált memóriahelyek darabszáma,
// erre nincs kivételkezelés, erre a felhasználónak kell figyelnie
// Visszatérési érték: az utolsó elem utáni memóriacímre mutató
//	iterátor a dest által mutatott listában
template <class OutputIt, class T, class BinaryOp>
OutputIt rekurziv_sorozat
(size_t i, size_t j, OutputIt dest, const T& first, BinaryOp op) {
	T current = first;
	while (i < j) {
		*dest++ = current;
		current = op(i++, current);
	}
	return dest;
}

// Adatsor elemeinek összeadása
// Paraméterek:
// 	beg: adatsor kezdő elemére mutató iterátor
// 	end: adatsor utolsó utáni elemére mutató iterátor
// 	val: akkumulátor változó kezdeti értéke
// A felhasználónak ügyelnie kell az iterátorszakasz validitására
// Visszatérési érték:
// 	Az adatsor összes elemének összege
template <class InputIt, class T = ptrdiff_t>
T osszegzes
(InputIt beg, InputIt end, T val = 0) {
	while (beg != end)
		val += *beg++;
	return val;
}

// Az adatsor adott tulajdonságú elemeinek összeadása
// Paraméterek:
// 	beg: adatsor kezdő elemére mutató iterátor
// 	end: adatsor utolsó utáni elemére mutató iterátor
// 	val: akkumulátor változó kezdeti értéke
// 	pred: logikai visszatérési értékű funkció,
// 		amely meghívható az adatsor értékeivel
// A felhasználónak ügyelnie kell az iterátorszakasz validitására
// Visszatérési érték:
// 	Az adatsor adott tulajdonságú elemeinek összege
template <class InputIt, class T = ptrdiff_t, class UnaryPred>
T felteteles_osszegzes
(InputIt beg, InputIt end, T val, UnaryPred pred) {
	while (beg != end) {
		if (pred(*beg))
			val += *beg;
		++beg;
	}
	return val;
}

// Annak vizsgálata, hogy egy adatsorban van-e adott tulajdonságú elem
// Paraméterek:
// 	beg: adatsor kezdő elemére mutató iterátor
// 	end: adatsor utolsó utáni elemére mutató iterátor
// 	pred: logikai visszatérési értékű függvény,
// 		amely meghívható az adatsor értékeivel
// A felhasználónak ügyelnie kell az iterátorszakasz validitására
// Visszatérési érték:
// 	Logikai érték, létezik-e legalább egy adott
// 	tulajdonságú elem az adatsorban
template <class InputIt, class UnaryPred>
bool eldontes
(InputIt beg, InputIt end, UnaryPred pred) {
	while (beg != end)
		if (pred(*beg++))
			return true;
	return false;
}

// Adott tulajdonságú elem kiválasztása olyan adatsorból,
// amiben biztosan van ilyen elem
// Paraméterek:
// 	beg: adatsor kezdő elemére mutató iterátor
// 	pred: logikai visszatérési értékű függvény,
// 		amely meghívható az adatsor értékeivel
// A felhasználónak ügyelnie kell, hogy biztosan
// legyen adott tulajdonságú elem az adatsorban,
// különben memória túlcímezés történik
// Visszatérési érték:
// 	Az első adott tulajdonságú elemre mutató iterátor
template <class InputIt, class UnaryPred>
InputIt kivalasztas
(InputIt beg, UnaryPred pred) {
	while (!pred(*beg))
		++beg;
	return beg;
}

// Adott tulajdonságú elemek kiválogatása egy adatsorból
// Paraméterek:
//  beg: adatsor kezdő elemére mutató iterátor
//  end: adatsor utolsó utáni elemére mutató iterátor
//  dest: mutató a cél adatsor első elemére
//  pred: egy paraméteres feltétel, amelyet az adatsor elemeivel
//  	meg lehet hívni, és logikai értéket ad vissza, ezen érték
//  	alapján határozzuk meg a kiválogatandó elemeket
// A felhasználónak ügyelnie kell az iterátorszakasz validitására,
// illetve arra, hogy legyen elegendő hely a cél adatsorban a
// memóriatúlcímezés elkerülése érdekében
// Visszatérési érték:
// 	A céladatsorban írt utolsó elem utánra mutató iterátor
template <class InputIt, class OutputIt, class UnaryPred>
OutputIt kivalogatas
(InputIt beg, InputIt end, OutputIt dest, UnaryPred pred) {
	while (beg != end) {
		if (pred(*beg))
			*dest++ = *beg;
		++beg;
	}
	return dest;
}

// Egy adatsor adott tulajdonságú elemeinek megszámlálása
// Paraméterek:
// 	beg: adatsor kezdő elemére mutató iterátor
// 	end: adatsor utolsó utáni elemére mutató iterátor
// 	pred: egy paraméteres feltétel, amelyet az adatsor elemeivel
// 		meg lehet hívni, és logikai értéket ad vissza, amely
// 		alapján számoljuk a darabszámot
// A felhasználónak ügyelnie kell az iterátorszakasz validitására
// Visszatérési érték:
// 	Az adatsorban található elemek darabszáma,
// 	amelyekre teljesült a feltétel
template <class InputIt, class UnaryPred>
size_t szamlalas
(InputIt beg, InputIt end, UnaryPred pred) {
	size_t cnt = 0;
	while (beg != end)
		if (pred(*beg++))
			++cnt;
	return cnt;
}

// Egy adatsor elemeinek szétválogatása adott tulajdonságuk alapján
// Paraméterek:
// 	beg: bemeneti adatsor kezdő elemére mutató iterátor 
// 	end: bemeneti adatsor utolsó utáni elemére mutató iterátor
// 	dest1: első kimeneti adatsor első írandó elemére mutató iterátor,
// 		amelybe írjuk azon elemeket, amelyekre teljesül a feltétel
// 	dest2: második kimeneti adatsor első írandó elemére mutató iterátor,
// 		amelybe írjuk azon elemeket, amelyekre nem teljesül a feltétel
// 	pred: egy paraméteres feltétel, logikai visszatérésű értékkel,
// 		amely meghívható a bemeneti adatsor elemeivel
// A felhasználónak ügyelnie kell az iterátorszakasz validitására,
// illetve arra, hogy a két kimeneti adatsorban legyen elegendő férőhely
// a memóriatúlcímezés elkerülése érdekében
// Visszatérési érték:
// 	A két céladatsorban írt utolsó elem utánra mutató iterátorok
template <class InputIt, class OutputIt1, class OutputIt2, class UnaryPred>
std::pair<OutputIt1, OutputIt2> szetvalogatas
(InputIt beg, InputIt end, OutputIt1 dest1, OutputIt2 dest2, UnaryPred pred) {
	while (beg != end) {
		if (pred(*beg))
			*dest1++ = *beg++;
		else
			*dest2++ = *beg++;
	}
	return std::make_pair(dest1, dest2);
}

// Két adatsor közös elemeinek kiválogatása, harmadik adatsorba gyűjtése
// Paraméterek:
// 	beg1: első bemeneti adatsor első elemére mutató iterátor
// 	end1: első bemeneti adatsor utolsó utáni elemére mutató iterátor
// 	beg2: második bemeneti adatsor első elemére mutató iterátor
// 	end2: második bemeneti adatsor utolsó utáni elemére mutató iterátor
// 	dest: kimeneti adatsor első írandó elemére mutató iterátor,
// 		amelybe írjuk a közös elemeket
// A felhasználónak ügyelnie kell a két bemeneti iterátorszakasz validitására,
// illetve arra, hogy a kimeneti adatsorban legyen elegendő férőhely a
// memóriatúlcímezés elkerülése érdekében
// Visszatérési érték:
// 	A kimeneti adatsor utoljára írt eleme utánra mutató iterátor
template <class InputIt1, class InputIt2, class OutputIt>
OutputIt metszet
(InputIt1 beg1, InputIt1 end1, InputIt2 beg2, InputIt2 end2, OutputIt dest) {
	for (; beg1 != end1; ++beg1) {
		InputIt2 it = beg2;
		while (it != end2 && *beg1 != *it)
			++it;
		if (it != end2)
			*dest++ = *it;
	}
	return dest;
}

}	// csrb namespace vége

#endif	// ALAPFELADATOK_H

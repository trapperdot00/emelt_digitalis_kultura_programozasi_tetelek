#ifndef ALAPFELADATOK_H
#define ALAPFELADATOK_H

#include <cstddef>

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
			*(dest++) = op(i++);
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
			*(dest++) = current;
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
			val += *(beg++);
		return val;
	}
}	// csrb namespace vége

#endif	// ALAPFELADATOK_H

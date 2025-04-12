#ifndef KERESESEK_H
#define KERESESEK_H

namespace csrb {

// Adott értékű elem keresése és az adatsorban elfoglalt helyének megadása
// Paraméterek:
// 	beg: Az adatsor első elemére mutató iterátor
// 	end: Az adatsor utolsó utáni elemére mutató iterátor
// 	val: A keresett érték
// A felhasználónak ügyelnie kell az iterátorszakasz validitására
// Visszatérési érték:
// 	Az adatsorban megtalált elemre mutató iterátor,
// 	vagy end paraméter (adatsor utolsó utáni elemére mutató iterátor),
// 	ha nem volt találat
template <class InputIt, class T>
InputIt linearis_kereses
(InputIt beg, InputIt end, const T& val) {
	while (beg != end && *beg != val)
		++beg;
	return beg;
}

// Adott értékű elem keresése és a rendezett adatsorban elfoglalt
// helyének megadása
// Paraméterek:
// 	beg: Az adatsor első elemére mutató iterátor
// 	end: Az adatsor utolsó utáni elemére mutató iterátor
// 	val: A keresett érték
// A felhasználónak ügyelnie kell az iterátorszakasz validitására,
// és az adatsor rendezettségére
// Visszatérési érték:
// 	Az adatsorban megtalált elemre mutató iterátor,
// 	vagy end paraméter (adatsor utolsó utáni elemére mutató iterátor),
// 	ha nem volt találat
template <class RandomIt, class T>
RandomIt binaris_kereses
(RandomIt beg, RandomIt end, const T& val) {
	RandomIt last = end;
	RandomIt mid = beg + (last - beg) / 2;
	while (mid != last && *mid != val) {
		if (*mid < val)
			beg = mid + 1;
		else
			last = mid;
		mid = beg + (last - beg) / 2;
	}
	if (mid != end && *mid == val)
		return mid;
	return end;
}

}	// csrb namespace vége

#endif	// KERESESEK_H

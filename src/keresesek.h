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
// 	vagy end paraméter (adatsor utolsó utáni elemre mutató iterátor),
// 	ha nem volt találat
template <class InputIt, class T>
InputIt linearis_kereses
(InputIt beg, InputIt end, const T& val) {
	while (beg != end && *beg != val)
		++beg;
	return beg;
}

}	// csrb namespace vége

#endif	// KERESESEK_H

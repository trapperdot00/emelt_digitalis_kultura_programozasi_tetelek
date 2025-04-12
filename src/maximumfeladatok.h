#ifndef MAXIMUMFELADATOK_H
#define MAXIMUMFELADATOK_H

namespace csrb {

// Az adatsorból kiválasztandó az első legnagyobb elem és annak helye
// Paraméterek:
// 	beg: Az adatsor első elemére mutató iterátor
// 	end: Az adatsor utolsó utáni elemére mutató iterátor
// A felhasználónak ügyelnie kell az iterátorszakasz validitására
// Visszatérési érték:
// 	A legnagyobb értékű elemre mutató iterátor,
// 	vagy az adatsor utolsó utáni elemére mutató iterátor üres adatsor esetén
template <class InputIt>
InputIt maximumkivalasztas
(InputIt beg, InputIt end) {
	if (beg == end)
		return end;
	InputIt max = beg++;
	for (; beg != end; ++beg)
		if (*max < *beg)
			max = beg;
	return max;
}

}	// csrb namespace vége

#endif	// MAXIMUMFELADATOK_H

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

// Az adott feltételnek megfelelő legnagyobb elem helyének
// meghatározása az adatsorban
// Paraméterek:
// 	beg: Az adatsor első elemére mutató iterátor
// 	end: Az adatsor utolsó utáni elemére mutató iterátor
// 	pred: egy paraméteres feltétel, amely meghívható az adatsor elemeivel
// A felhasználónak ügyelnie kell az iterátorszakasz validitására
// Visszatérési érték:
// 	A feltételnek megfelelő legnagyobb értékű elemre mutató,
// 	vagy üres adatsor esetén az adatsor utolsó utáni elemére mutató iterátor
template <class InputIt, class UnaryPred>
InputIt felteteles_maximum
(InputIt beg, InputIt end, UnaryPred pred) {
	while (beg != end && !pred(*beg))
		++beg;
	if (beg == end)
		return end;
	InputIt max = beg;
	for (; beg != end; ++beg)
		if (*max < *beg && pred(*beg))
			max = beg;
	return max;
}

}	// csrb namespace vége

#endif	// MAXIMUMFELADATOK_H

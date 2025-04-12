#ifndef MAXIMUMFELADATOK_H
#define MAXIMUMFELADATOK_H

#include <cstddef>
#include <iterator>
#include <utility>

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

// Az adatsor maximális elemeinek megszámolása
// Paraméterek:
// 	beg: Az adatsor első elemére mutató iterátor
// 	end: Az adatsor utolsó utáni elemére mutató iterátor
// A felhasználónak ügyelnie kell az iterátorszakasz validitására
// Visszatérési érték:
// 	A maximumérték és darabszáma,
// 	üres adatsornál alapérték és 0-s darabszám
template <class InputIt>
std::pair<typename std::iterator_traits<InputIt>::value_type, size_t>
maximumszamlalas
(InputIt beg, InputIt end)
{
	if (beg == end)
		return std::make_pair(
			typename std::iterator_traits<InputIt>::value_type{}, 0
		);
	size_t cnt = 1;
	InputIt max = beg++;
	for (; beg != end; ++beg) {
		if (*max == *beg)
			++cnt;
		else if (*max < *beg) {
			max = beg;
			cnt = 1;
		}
	}
	return std::make_pair(*max, cnt);
}

// Az első olyan elem keresése az adatsorban,
// amely nagyobb mindkét szomszédjánál
// Paraméterek:
// 	beg: Az adatsor első elemére mutató iterátor
// 	end: Az adatsor utolsó utáni elemére mutató iterátor
// A felhasználónak ügyelnie kell az iterátorszakasz validitására
// Visszatérési érték:
// 	Lokális maximumra, vagy az adatsor utolsó utáni elemére mutató iterátor
template <class InputIt>
InputIt lokalis_maximum
(InputIt beg, InputIt end) {
	if (beg == end || beg + 1 == end || beg + 2 == end)
		return end;
	for (InputIt prev = beg++, next = beg+1; next != end; ++prev, ++beg, ++next) {
		if (*prev < *beg && *next < *beg)
			return beg;
	}
	return end;
}

}	// csrb namespace vége

#endif	// MAXIMUMFELADATOK_H

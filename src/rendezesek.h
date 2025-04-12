#ifndef RENDEZESEK_H
#define RENDEZESEK_H

#include <iterator>
#include <algorithm>

namespace csrb {

template <class RandomIt>
void beilleszteses_rendezes
(RandomIt beg, RandomIt end) {
	if (beg == end)
		return;
	for (RandomIt it1 = beg + 1; it1 != end; ++it1) {
		typename std::iterator_traits<RandomIt>::value_type b = *it1;
		RandomIt it2 = it1 - 1;
		while (it2 >= beg && b < *it2) {
			*(it2 + 1) = *it2;
			--it2;
		}
		*(it2 + 1) = b;
	}
}

template <class RandomIt>
void buborekos_rendezes
(RandomIt beg, RandomIt end) {
	if (beg == end)
		return;
	for (RandomIt it1 = end - 1; it1 != beg; --it1) {
		for (RandomIt it2 = beg; it2 != it1; ++it2)
			if (*(it2 + 1) < *it2)
				std::iter_swap(it2 + 1, it2);
	}
}

}	// csrb namespace vége

#endif	// RENDEZESEK_H

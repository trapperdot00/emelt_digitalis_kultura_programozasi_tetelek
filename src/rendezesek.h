#ifndef RENDEZESEK_H
#define RENDEZESEK_H

#include <iterator>

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

}	// csrb namespace vége

#endif	// RENDEZESEK_H

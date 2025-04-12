#include "../src/csrb.h"

#include <iterator>
#include <vector>
#include <iostream>

int main() {
	std::cout << "Lokális maximum\n";

	std::vector<int> lista{0,5,1,3,5,7,22,115,73};
	
	std::cout << "Lista:";
	for (int i : lista)
		std::cout << ' ' << i;
	std::cout << '\n';

	std::vector<int>::const_iterator lokalis_max = csrb::lokalis_maximum(
		lista.cbegin(),
		lista.cend()
	);

	if (lokalis_max == lista.cend())
		std::cout << "Nincs lokális maximum\n";
	else
		std::cout << "Lokális maximum: "
			<< *lokalis_max
			<< " index: "
			<< std::distance(lista.cbegin(), lokalis_max)
			<< '\n';
}

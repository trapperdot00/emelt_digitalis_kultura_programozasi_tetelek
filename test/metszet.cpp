#include "../src/csrb.h"

#include <vector>
#include <iostream>
#include <iterator>

int main() {
	std::cout << "Metszet\n";
	std::vector<int> lista1{0,1,2,3,4,5,6,7,8,9};
	std::vector<int> lista2{5,6,7,8,9,10,11,12,13,14};

	std::cout << "Lista1: ";
	for (int i : lista1)
		std::cout << i << ' ';
	std::cout << '\n';

	std::cout << "Lista2: ";
	for (int i : lista2)
		std::cout << i << ' ';
	std::cout << '\n';

	// Közös elemek kiválogatása
	std::vector<int> kozoslista;
	csrb::metszet(
		lista1.cbegin(),
		lista1.cend(),
		lista2.cbegin(),
		lista2.cend(),
		std::back_inserter(kozoslista)
	);

	std::cout << "Közös elemek: ";
	for (int i : kozoslista)
		std::cout << i << ' ';
	std::cout << '\n';
}

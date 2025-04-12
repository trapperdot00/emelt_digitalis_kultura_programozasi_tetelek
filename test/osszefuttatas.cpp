#include "../src/csrb.h"

#include <vector>
#include <iterator>
#include <iostream>

int main() {
	std::cout << "Összefuttatás\n";

	std::vector<int> lista1{1,3,3,5,7,7,9};
	std::vector<int> lista2{0,2,3,3,5,5,8};

	std::cout << "Lista1:";
	for (int i : lista1)
		std::cout << ' ' << i;
	std::cout << '\n';

	std::cout << "Lista2:";
	for (int i : lista2)
		std::cout << ' ' << i;
	std::cout << '\n';

	// Listák összefuttatása
	std::vector<int> osszefuttatott;
	csrb::osszefuttatas(
		lista1.cbegin(),
		lista1.cend(),
		lista2.cbegin(),
		lista2.cend(),
		std::back_inserter(osszefuttatott)
	);

	std::cout << "Összefuttatott elemek:";
	for (int i : osszefuttatott)
		std::cout << ' ' << i;
	std::cout << '\n';
}

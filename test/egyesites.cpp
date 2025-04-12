#include "../src/csrb.h"

#include <vector>
#include <iterator>
#include <iostream>

int main() {
	std::cout << "Egyesítés\n";

	std::vector<int> lista1{1,1,2,2,5};
	std::vector<int> lista2{0,1,2,3,4};

	std::cout << "Lista1:";
	for (int i : lista1)
		std::cout << ' ' << i;
	std::cout << '\n';

	std::cout << "Lista2:";
	for (int i : lista2)
		std::cout << ' ' << i;
	std::cout << '\n';

	// Listák egyesítése
	std::vector<int> egyesitett;
	csrb::egyesites(
		lista1.cbegin(),
		lista1.cend(),
		lista2.cbegin(),
		lista2.cend(),
		std::back_inserter(egyesitett)
	);

	std::cout << "Egyesített elemek:";
	for (int i : egyesitett)
		std::cout << ' ' << i;
	std::cout << '\n';
}

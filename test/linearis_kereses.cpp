#include "../src/csrb.h"

#include <vector>
#include <iostream>

int main() {
	std::cout << "Lineáris keresés\n";

	std::vector<int> lista1{0,2,4,6,8};
	std::vector<int> lista2{1,3,5,7,9};

	std::cout << "Lista1:";
	for (int i : lista1)
		std::cout << ' ' << i;
	std::cout << '\n';

	std::cout << "Lista2:";
	for (int i : lista2)
		std::cout << ' ' << i;
	std::cout << '\n';

	std::cout << "\n7 keresése Lista1-ben: ";
	if (auto it = csrb::linearis_kereses(lista1.cbegin(), lista1.cend(), 7);
			it != lista1.cend())
		std::cout << "találat "
			<< std::distance(lista1.cbegin(), it)
			<< ". indexnél\n";
	else
		std::cout << "nincs találat\n";

	std::cout << "7 keresése Lista2-ben: ";
	if (auto it = csrb::linearis_kereses(lista2.cbegin(), lista2.cend(), 7);
			it != lista2.cend())
		std::cout << "találat "
			<< std::distance(lista2.cbegin(), it)
			<< ". indexnél\n";
	else
		std::cout << "nincs találat\n";
}

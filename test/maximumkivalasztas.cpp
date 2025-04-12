#include "../src/csrb.h"

#include <vector>
#include <iostream>

int main() {
	std::cout << "Maximumkiválasztás\n";

	std::vector<int> lista{0,5,1,3,5,7,22,115,73,4};
	
	std::cout << "Lista:";
	for (int i : lista)
		std::cout << ' ' << i;
	std::cout << '\n';

	std::vector<int>::const_iterator max = csrb::maximumkivalasztas(
		lista.cbegin(),
		lista.cend()
	);
	if (max != lista.cend())
		std::cout << "Maximum: " << *max << '\n';
}

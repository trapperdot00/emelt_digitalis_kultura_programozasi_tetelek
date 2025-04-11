#include "../src/csrb.h"

#include <vector>
#include <iostream>

int main() {
	std::cout << "Számlálás\n";
	std::vector<int> lista{1,2,3,4,5,6,7,8,9,0};
	
	// Lista kiíratása
	std::cout << "Lista: ";
	for (int i : lista)
		std::cout << i << ' ';
	std::cout << '\n';

	// Adatsor szakasz
	std::vector<int>::const_iterator kezdo = lista.cbegin();
	std::vector<int>::const_iterator vegso = lista.cend();

	auto feltetel = [](int i) { return i % 2 == 0; };

	// Számlálás és számolt érték kiíratása
	size_t darab = csrb::szamlalas(kezdo, vegso, feltetel);
	std::cout << darab
		<< " darab páros elem\n";
}

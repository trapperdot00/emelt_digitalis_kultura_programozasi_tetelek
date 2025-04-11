#include "../src/csrb.h"

#include <deque>
#include <iostream>

int main() {
	std::cout << "Kiválasztás\n";
	std::deque<int> lista{1,2,3,4,5,6,7,8,9,0};

	// Lista kiíratása
	std::cout << "Lista: ";
	for (int i : lista)
		std::cout << i << ' ';
	std::cout << '\n';

	// Lista első elemére iterátor
	auto kezdo = lista.cbegin();

	// Keresési feltétel, 6-os értékű elem
	auto feltetel = [](int i) { return i == 6; };

	// Elem keresése, majd kiírása
	std::deque<int>::const_iterator talalat = csrb::kivalasztas(kezdo, feltetel);
	std::cout << "index: "
		<< std::distance(kezdo, talalat)
		<< " érték: "
		<< *talalat
		<< '\n';
}

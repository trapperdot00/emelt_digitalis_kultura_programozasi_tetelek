#include "../src/csrb.h"

#include <iostream>
#include <forward_list>

int main() {
	std::forward_list<int> lista{0,1,2,3,4,5,6,7,8,9};

	// Lista kiíratása
	std::cout << "Lista: ";
	for (int i : lista)
		std::cout << i << ' ';
	std::cout << '\n';	

	// Adatsor szakasza, teljes lista
	decltype(lista)::const_iterator kezdo = lista.cbegin();
	decltype(kezdo) vegso = lista.cend();

	// Páros elemek
	auto feltetel = [](int i) { return i % 2 == 0; };
	
	// Feltételes összeg kiszámítása
	double osszeg = csrb::felteteles_osszegzes(kezdo, vegso, 0.0, feltetel);

	// Feltételes összeg kiíratása
	std::cout << "Feltételes összeg: " << osszeg << '\n';
}

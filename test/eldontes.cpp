#include "../src/csrb.h"

#include <list>
#include <iostream>

int main() {
	std::cout << "Eldöntés\n";
	std::list<int> lista{1,7,5,2,8,10,105,77,69};
	
	// Lista értékeinek kiíratása
	std::cout << "Lista: ";
	for (int i : lista)
		std::cout << i << ' ';
	std::cout << '\n';

	// Adatsor szakasz
	std::list<int>::const_iterator kezdo = lista.cbegin();
	std::list<int>::const_iterator vegso = lista.cend();

	// Vizsgálandó kondíció
	auto fuggveny = [](int i) { return i > 100; };
	
	if (csrb::eldontes(kezdo, vegso, fuggveny))
		std::cout << "A listában van 100-nál nagyobb elem\n";
	else
		std::cout << "A listában nincs 100-nál nagyobb elem\n";
}

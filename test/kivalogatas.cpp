#include "../src/csrb.h"

#include <algorithm>
#include <vector>
#include <iostream>
#include <iterator>

int main() {
	std::cout << "Kiválogatás\n";
	
	// Forrás-lista
	std::vector<int> lista{0,1,2,3,4,5,6,7,8,9};

	// Lista elemeinek kiíratása
	std::cout << "Lista: ";
	std::for_each(
		lista.cbegin(),
		lista.cend(),
		[](int i) { std::cout << i << ' '; }
	);
	std::cout << '\n';

	// Cél-lista
	std::vector<int> paros_lista;

	// Páros elemek kiválogatása a cél-listába
	csrb::kivalogatas(
		lista.cbegin(),
		lista.cend(),
		std::back_inserter(paros_lista),
		[](int i) { return i % 2 == 0; }
	);

	// Páros lista elemeinek kiíratása
	std::cout << "Párosak: ";
	std::for_each(
		paros_lista.cbegin(),
		paros_lista.cend(),
		[](int i) { std::cout << i << ' '; }
	);
	std::cout << '\n';
}

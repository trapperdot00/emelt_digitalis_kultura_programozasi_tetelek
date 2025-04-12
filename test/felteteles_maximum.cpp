#include "../src/csrb.h"

#include <vector>
#include <iostream>

int main() {
	std::cout << "Feltételes maximum\n";

	std::vector<int> lista{0,5,1,3,5,7,22,115,73,4};
	
	std::cout << "Lista:";
	for (int i : lista)
		std::cout << ' ' << i;
	std::cout << '\n';

	auto feltetel = [](int i) { return i % 2 == 0; };

	std::vector<int>::const_iterator max = csrb::felteteles_maximum(
		lista.cbegin(),
		lista.cend(),
		feltetel
	);
	if (max != lista.cend())
		std::cout << "Páros maximum: " << *max << '\n';
}

#include "../src/csrb.h"

#include <vector>
#include <iostream>

int main() {
	std::cout << "Maximumszámlálás\n";

	std::vector<int> lista{0,5,1,3,5,7,22,115,73,4,79,114,114,115,115};
	
	std::cout << "Lista:";
	for (int i : lista)
		std::cout << ' ' << i;
	std::cout << '\n';

	auto [max, max_db] = csrb::maximumszamlalas(
		lista.cbegin(),
		lista.cend()
	);

	std::cout << "Maximum: "
		<< max_db
		<< " db, értéke: "
		<< max
		<< '\n';
}

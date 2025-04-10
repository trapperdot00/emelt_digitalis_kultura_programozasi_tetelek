#include "../src/csrb.h"

#include <iostream>
#include <iterator>
#include <vector>

int main() {
	std::cout << "Sorozatszámítás\n";
	
	// Üres lista
	std::vector<int> lista;
	size_t kezdo = 0;
	size_t vegso = 10;
	
	// Az új értékeket az üres listába utolsó elemként illesztjük be
	std::back_insert_iterator<std::vector<int>> cel = std::back_inserter(lista);
	
	// A képlet ami alapján számokat generálunk, itt simán megszorozzuk
	// a megadott szám értékét kettővel
	auto keplet = [](size_t i) -> int { return i * 2; };
	
	// A lista feltöltése elemekkel
	csrb::sorozatszamitas(kezdo, vegso, cel, keplet);
	
	// A lista elemeinek kiíratása a terminálra
	for (int i : lista)
		std::cout << i << ' ';
	std::cout << '\n';
}

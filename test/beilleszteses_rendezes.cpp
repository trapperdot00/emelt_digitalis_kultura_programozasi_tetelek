#include "../src/csrb.h"

#include <vector>
#include <iostream>

int main() {
	std::cout << "Beillesztéses rendezés\n";
	std::vector<int> lista{7,1,2,8,4,5,3,0,9,6};
	
	std::cout << "Lista:";
	for (int i : lista)
		std::cout << ' ' << i;
	std::cout << '\n';

	csrb::beilleszteses_rendezes(lista.begin(), lista.end());

	std::cout << "Rendezett:";
	for (int i : lista)
		std::cout << ' ' << i;
	std::cout << '\n';
}

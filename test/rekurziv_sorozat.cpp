#include "../src/csrb.h"

#include <iostream>
#include <array>

int main() {
	std::cout << "Rekurzív sorozat\n";

	constexpr size_t lista_meret = 10;

	// Inicializálatlan lista, hulladék értékekkel
	std::array<int, lista_meret> lista;
	int kezdo = 0;
	int vegso = 10;

	// A lista első elemétől illesszünk be elemeket
	decltype(lista)::iterator cel = lista.begin();
	
	int elso_elem = 100;
	// A rekurzív képlet ami alapján számítjuk ki a lista következő elemét
	// a jelenlegi index és az előző elem alapján,
	// itt simán hozzáadjuk az előző elemhez az indexet és ahhoz még egyet
	auto rekurziv_keplet = [](size_t index, int elozo_elem) -> int {
		return elozo_elem + index + 1;
	};

	// Feltöltjük a listánkat értékekkel a képlet alapján,
	// majd eltároljuk az utolsó beillesztett elem utánra mutató iterátort,
	// hogy tudjuk mennyi elemet generáltunk
	decltype(lista)::iterator utolso =
		csrb::rekurziv_sorozat(kezdo, vegso, cel, elso_elem, rekurziv_keplet);

	// Csak a generált elemeket írjuk ki, a lista többi eleme nem érdekel
	for (decltype(utolso) it = cel; it != utolso; ++it)
		std::cout << *it << ' ';
	std::cout << '\n';
}

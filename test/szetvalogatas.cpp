#include "../src/csrb.h"

#include <array>
#include <iostream>

int main() {
	std::cout << "Szétválogatás\n";
	constexpr size_t lista_meret = 10;

	// Forrás-lista
	std::array<int, lista_meret> lista{0,1,2,3,4,5,6,7,8,9};

	// Lista kiíratása
	std::cout << "Lista: ";
	for (int i : lista)
		std::cout << i << ' ';
	std::cout << '\n';

	// Adatsor szakasz, teljes lista
	std::array<int, lista_meret>::const_iterator kezdo = lista.cbegin();
	std::array<int, lista_meret>::const_iterator vegso = lista.cend();

	// Cél listák
	std::array<int, lista_meret> paros_lista;
	std::array<int, lista_meret> paratlan_lista;

	// Listák beillesztési kezdeti pontjai
	std::array<int, lista_meret>::iterator paros_kezdo = paros_lista.begin();
	std::array<int, lista_meret>::iterator paratlan_kezdo = paratlan_lista.begin();

	auto feltetel = [](int i) { return i % 2 == 0; };

	// Szétválogatás, utolsó elem utáni mutatók eltárolása
	auto [paros_vegso, paratlan_vegso] = csrb::szetvalogatas(
		kezdo, vegso, paros_kezdo, paratlan_kezdo, feltetel
	);

	// Páros elemek kiíratása
	std::cout << "Párosak: ";
	for (auto it = paros_kezdo; it != paros_vegso; ++it)
		std::cout << *it << ' ';
	std::cout << '\n';

	// Páratlan elemek kiíratása
	std::cout << "Páratlanok: ";
	for (auto it = paratlan_kezdo; it != paratlan_vegso; ++it)
		std::cout << *it << ' ';
	std::cout << '\n';
}

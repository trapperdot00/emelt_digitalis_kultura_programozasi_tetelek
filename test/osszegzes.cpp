#include "../src/csrb.h"

#include <iostream>
#include <random>
#include <chrono>

template <class T>
void random_fill(T* p, size_t sz) {
	// Randomszám generáló motor, amelyet a jelenlegi idővel seedelünk
	static std::default_random_engine e(
		std::chrono::system_clock::now().time_since_epoch().count()
	);
	// Egyenletes eloszlás randomszám disztribúció,
	// átalakítja a motor által generált számot a megadott intervallumban
	// lévő számokra, egyenlő eséllyel minden számra
	static std::uniform_int_distribution<T> d{0, 100};
	
	// A megadott lista minden eleme legyen random értékű
	for (size_t i = 0; i < sz; ++i)
		*(p++) = d(e);
}

int main() {
	std::cout << "Összegzés\n";
	constexpr size_t lista_meret = 10;

	// Dinamikusan allokált összefüggő memóriablokk,
	// lista_meret darab int méretű, alkalmazhatunk rajta
	// pointer-aritmetikát
	int* lista = new int[lista_meret];
	
	// Random értékkel kitöltjük a listát
	random_fill(lista, lista_meret);

	// Lista elemeinek kiíratása
	std::cout << "Lista:";
	for (int* p = lista; p != lista + lista_meret; ++p)
		std::cout << ' ' << *p;
	std::cout << '\n';

	// Összeg eltárolása és kiíratása
	int osszeg = csrb::osszegzes(lista, lista + lista_meret, 0);
	std::cout << "Összeg: " << osszeg << '\n';

	// Fontos: a dinamikusan allokált memóriát vissza kell adni
	// az operációs rendszernek a memóriaszivárgások elkerülése érdekében
	delete[] lista;
}

#ifndef ALAPFELADATOK_H
#define ALAPFELADATOK_H

#include <cstddef>

namespace csrb {
	// Sorozat előállítása az általános képlet alapján
	// Paraméterek:
	// 	i: kezdő érték, egyesével nő, amíg kisebb mint j
	// 	j: utolsó érték
	//	dest: kimeneti iterátor, egy lista első elemére mutat,
	//		minden írásnál nő eggyel az értéke
	//	op: egy size_t paraméterrel meghívható funkció, az i-vel
	//		meghívott visszatérési értéke kerül be a dest által
	//		mutatott helyre
	// A memória túlcímezés veszélye fennáll abban az esetben, ha
	// j és i különbsége nagyobb, mint a dest által mutatott
	// és az utánalévő létező allokált memóriahelyek darabszáma,
	// erre nincs kivételkezelés, erre a felhasználónak kell figyelnie
	template <class OutputIt, class UnaryOp>
	OutputIt sorozatszamitas
	(size_t i, size_t j, OutputIt dest, UnaryOp op) {
		while (i < j)
			*(dest++) = op(i++);
		return dest;
	}
}

#endif	// ALAPFELADATOK_H

#ifndef ITER_H
#define ITER_H

#include <cstddef>

template <typename T>
void iter(T* pArr, size_t size, void (*func)(T&)) {
	for (size_t i = 0; i < size; ++i) {
		func(pArr[i]);
	}
}

#endif

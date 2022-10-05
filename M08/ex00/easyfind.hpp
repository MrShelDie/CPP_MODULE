#ifndef EASYFIND_H_
#define EASYFIND_H_

#include <exception>
#include <algorithm>

template <typename T>
typename T::iterator easyfind(T& t, int toFind) {

  typename T::iterator res = find(t.begin(), t.end(), toFind);

	if (res == t.end()) {
		throw std::exception();
	}

	return res;
}

#endif

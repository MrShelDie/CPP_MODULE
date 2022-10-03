#ifndef _ARRAY_H_
#define _ARRAY_H_

#include <string>
#include <sstream>
#include <cstddef>
#include <exception>

template <typename T>
class Array {

public:

	Array();
	Array(unsigned int n);
	Array(const Array& other);
	~Array();

	Array& operator=(const Array& other);
	T& operator[](unsigned int pos);

	size_t size() const;

private:

	T* arrPtr;
	size_t arrSize;

};


template <typename T>
Array<T>::Array() {
	this->arrPtr = NULL;
	this->arrSize = 0;
}

template <typename T>
Array<T>::Array(unsigned int n) {
	this->arrPtr = n ? new T[n]() : NULL;
	this->arrSize = n;
}

template <typename T>
Array<T>::Array(const Array& other) {
	this->arrSize = other.arrSize;
	this->arrPtr = this->arrSize ? new T[this->arrSize]() : NULL;

	for (unsigned int i = 0; i < this->arrSize; ++i) {
		this->arrPtr[i] = other.arrPtr[i];
	}
}

template <typename T>
Array<T>::~Array() {
	delete[] this->arrPtr;
}

template <typename T>
Array<T>& Array<T>::operator=(const Array& other) {
	if (&other == this) {
		return *this;
	}

	if (this->arrSize != other.arrSize) {
		delete[] this->arrPtr;
		this->arrSize = other.arrSize;
		this->arrPtr = new T[this->arrSize]();
	}

	for (unsigned int i = 0; i < this->arrSize; ++i) {
		this->arrPtr[i] = other.arrPtr[i];
	}

	return *this;
}

template <typename T>
T& Array<T>::operator[](unsigned int pos) {
	if (pos >= this->arrSize)
		throw std::exception();	
	return this->arrPtr[pos];
}

template <typename T>
size_t Array<T>::size() const {
	return this->arrSize;
}

#endif

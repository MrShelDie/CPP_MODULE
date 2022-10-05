#include <limits>
#include <algorithm> 

#include "Span.hpp"

Span::Span() : maxSize(0) {

}

Span::Span(unsigned int N)
    : nums(N),
      maxSize(N) {

}

Span::Span(const Span& other)
    : nums(other.nums),
      maxSize(other.maxSize) {

}

Span::~Span() {

}

Span& Span::operator=(const Span& other) {
  if (&other == this) {
    return *this;
  }

  nums = other.nums;
  maxSize = other.maxSize;
  return *this;
}

void Span::addNumber(int num) {
  if (nums.size() == maxSize) {
    throw NoSpaceException();
  }

  std::list<int>::iterator it = std::upper_bound(
      nums.begin(), nums.end(), num);
  nums.insert(it, num);
}

unsigned int Span::shortestSpan() {
  if (nums.size() < 2)
    throw NoSpanCanBeFoundException();

  std::list<int>::iterator it1 = nums.begin();
  std::list<int>::iterator it2 = ++nums.begin(); 
  unsigned int minSpan = *it2 - *it1; 
  ++it1;
  ++it2;

  while (it2 != nums.end()) {
    unsigned int dist = *it2 - *it1;
    if (dist < minSpan) {
      minSpan = dist; 
    }  
    ++it1;
    ++it2;
  }

  return minSpan;
}

unsigned int Span::longestSpan() {
  if (nums.size() < 2)
    throw NoSpanCanBeFoundException();
  return *nums.rbegin() - *nums.begin();
}

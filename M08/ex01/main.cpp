#include <ctime>
#include <vector>
#include <cstdlib>
#include <iostream>

#include "Span.hpp"

//#define INTRA_TEST

int main() {
#ifdef INTRA_TEST
  Span sp = Span(5);

  sp.addNumber(6);
  sp.addNumber(3);
  sp.addNumber(17);
  sp.addNumber(9);
  sp.addNumber(11);

  std::cout << sp.shortestSpan() << std::endl;
  std::cout << sp.longestSpan() << std::endl; 
#else
  try {
    Span sp;
    sp.addNumber(1);
  } catch (Span::NoSpaceException& e) {
    std::cerr << e.what() << "\n";
  }

  try {
    Span sp(1);
    sp.addNumber(1);
    std::cout << "num 1 was added to span\n";
    sp.addNumber(2);
  } catch (Span::NoSpaceException& e) {
    std::cerr << e.what() << "\n";
  }

  try {
    Span sp(1);
    std::vector<int> v(2);
    v.push_back(1);
    v.push_back(2);
    sp.addNumber(v.begin(), v.end());
  } catch (Span::NoSpaceException& e) {
    std::cerr << e.what() << "\n";
  }

  std::srand(std::time(NULL));

  std::cout << "------------------\n";

  { 
    std::vector<int> iv(5);

    for (unsigned int i = 0; i < 5; ++i) {
      iv[i] = std::rand() % 10;
      std::cout << iv[i] << " ";
    }
    std::cout << "\n";

    Span sp(5);
    sp.addNumber(iv.begin(), iv.end());
    
    std::cout << sp.shortestSpan() << "\n";
    std::cout << sp.longestSpan() << "\n"; 
  }

  std::cout << "------------------\n";

  { 
    Span sp(5);
    for (unsigned int i = 0; i < 5; ++i) {
      int rnum = std::rand() % 10;
      sp.addNumber(rnum);
      std::cout << rnum << " ";
    }
    std::cout << "\n";
    
    std::cout << sp.shortestSpan() << "\n";
    std::cout << sp.longestSpan() << "\n"; 
  }

  std::cout << "------------------\n";

  { 
    const unsigned int kMaxSize = 20000;
    std::vector<int> iv(kMaxSize);

    for (unsigned int i = 0; i < kMaxSize; ++i) {
      iv[i] = std::rand() % kMaxSize;
    }

    Span sp(kMaxSize);
    sp.addNumber(iv.begin(), iv.end());
    
    std::cout << sp.shortestSpan() << "\n";
    std::cout << sp.longestSpan() << "\n"; 
  }

  std::cout << "------------------\n";

  {
    Span sp(5);
    for (unsigned int i = 0; i < 5; ++i) {
      int rnum = std::rand() % 10;
      sp.addNumber(rnum);
      std::cout << rnum << " ";
    }
    std::cout << "\n";
    
    std::cout << sp.shortestSpan() << " ";
    std::cout << sp.longestSpan() << "\n"; 
    
    Span sp2(sp);
    std::cout << sp2.shortestSpan() << " ";
    std::cout << sp2.longestSpan() << "\n"; 

    Span sp3;
    sp3 = sp;
    std::cout << sp3.shortestSpan() << " ";
    std::cout << sp3.longestSpan() << "\n"; 
  }
#endif

  return 0;
}

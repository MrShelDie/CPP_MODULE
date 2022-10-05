#ifndef SPAN_H_
#define SPAN_H_

#include <list>

class Span {
 public:
  class NoSpaceException : public std::exception {
   public:
    const char* what() const throw();
  };

  class NoSpanCanBeFoundException : public std::exception {
   public:
    const char* what() const throw();
  };

  Span();
  Span(unsigned int N);
  Span(const Span& other);
  ~Span();

  Span& operator=(const Span& other);

  void addNumber(int num);
  unsigned int shortestSpan();
  unsigned int longestSpan();

 private:
  std::list<int> nums;
  unsigned int maxSize;
};

#endif

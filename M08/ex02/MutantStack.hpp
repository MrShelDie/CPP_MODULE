#ifndef MUTANTSTACK_H_
#define MUTANTSTACK_H_

#include <stack>

template < class T, class Container = std::deque<T> >
class MutantStack : public std::stack<T, Container> {
 public:
  typedef typename Container::iterator iterator;
  typedef typename Container::const_iterator const_iterator;
  typedef typename Container::reverse_iterator reverse_iterator;
  typedef typename Container::const_reverse_iterator const_reverse_iterator;

  MutantStack();
  MutantStack(const MutantStack& other);
  ~MutantStack();
  MutantStack& operator=(const MutantStack& other);

  iterator begin();
  iterator end();
  const_iterator begin() const;
  const_iterator end() const;
  reverse_iterator rbegin();
  reverse_iterator rend();
  const_reverse_iterator rbegin() const;
  const_reverse_iterator rend() const;
};

template <class T, class Container>
MutantStack<T, Container>::MutantStack() : std::stack<T, Container>() {

}

template <class T, class Container>
MutantStack<T, Container>::MutantStack(const MutantStack& other)
    : std::stack<T, Container>(other) {

}

template <class T, class Container>
MutantStack<T, Container>::~MutantStack() {

}

template <class T, class Container>
MutantStack<T, Container>&
    MutantStack<T, Container>::operator=(const MutantStack& other) {
  if (&other != this) {
    static_cast< std::stack<T, Container> >(*this) = other;
  }
  return *this;  
}

template <class T, class Container>
typename MutantStack<T, Container>::iterator
    MutantStack<T, Container>::begin() {
  return this->c.begin();
}

template <class T, class Container>
typename MutantStack<T, Container>::iterator
    MutantStack<T, Container>::end() {
  return this->c.end();
}

template <class T, class Container>
typename MutantStack<T, Container>::const_iterator
    MutantStack<T, Container>::begin() const {
  return this->c.begin();
}

template <class T, class Container>
typename MutantStack<T, Container>::const_iterator
    MutantStack<T, Container>::end() const {
  return this->c.end();
}

template <class T, class Container>
typename MutantStack<T, Container>::reverse_iterator
    MutantStack<T, Container>::rbegin() {
  return this->c.rbegin();
}

template <class T, class Container>
typename MutantStack<T, Container>::reverse_iterator
    MutantStack<T, Container>::rend() {
  return this->c.rend();
}

template <class T, class Container>
typename MutantStack<T, Container>::const_reverse_iterator
    MutantStack<T, Container>::rbegin() const {
  return this->c.rbegin();
}

template <class T, class Container>
typename MutantStack<T, Container>::const_reverse_iterator
    MutantStack<T, Container>::rend() const {
  return this->c.rend();
}

#endif

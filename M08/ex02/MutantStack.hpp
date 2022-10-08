#ifndef MUTANTSTACK_H_
#define MUTANTSTACK_H_

#include <stack>

template <class T, class Container = std::deque<T>>
class MutantStack : std::stack<T, Container> {
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
MutantStack<T, Container>::MutantStack() {

}

template <class T, class Container>
MutantStack<T, Container>::MutantStack(const MutantStack& other) {

}

#endif

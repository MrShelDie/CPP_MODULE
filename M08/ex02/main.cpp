#include <iostream>

#include "MutantStack.hpp"

int main()
{
  MutantStack<int> mstack;

  mstack.push(5);
  mstack.push(17);
 
  std::cout << "Top: " << mstack.top() << std::endl;

  mstack.pop();

  std::cout << "Size: " << mstack.size() << std::endl;

  mstack.push(3);
  mstack.push(5);
  mstack.push(737);
  //[...]
  mstack.push(0);

  MutantStack<int>::iterator it = mstack.begin();
  MutantStack<int>::iterator ite = mstack.end();

  std::cout << "----------" << std::endl;
  ++it;
  --it;
  while (it != ite)
  {
  std::cout << *it << std::endl;
  ++it;
  }

  const MutantStack<int> s(mstack);
  MutantStack<int>::const_iterator kIt = s.begin();
  MutantStack<int>::const_iterator kIte = s.end();

  std::cout << "----------" << std::endl;
  ++kIt;
  --kIt;
  while (kIt != kIte)
  {
  std::cout << *kIt << std::endl;
  ++kIt;
  }

  MutantStack<int>::reverse_iterator rit = mstack.rbegin();
  MutantStack<int>::reverse_iterator rite = mstack.rend();

  std::cout << "----------" << std::endl;
  ++rit;
  --rit;
  while (rit != rite)
  {
  std::cout << *rit << std::endl;
  ++rit;
  }

  MutantStack<int>::const_reverse_iterator krit = s.rbegin();
  MutantStack<int>::const_reverse_iterator krite = s.rend();

  std::cout << "----------" << std::endl;
  ++krit;
  --krit;
  while (krit != krite)
  {
  std::cout << *krit << std::endl;
  ++krit;
  }

  return 0;
}

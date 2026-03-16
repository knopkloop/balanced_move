#ifndef SUBFUNCTIONS_H
#define SUBFUNCTIONS_H
#include <iostream>
#include "balanced_move.h"

template <class T>
void print_vec(const Vec<List<T>*>& v)
{
  for (size_t i = 0; i < v.s; ++i)
  {
    std::cout << " " << i << ": ";
    List<T>* cur = v[i];
    while (cur)
    {
      std::cout << cur->val << " ";
      cur = cur->next;
    }
    std::cout << "\n";
  }
}

template <class T>
void clean(Vec<List<T>*>& v)
{
  for (size_t i = 0; i < v.s; ++i)
  {
    List<T>* cur = v[i];
    while (cur)
    {
      List<T>* temp = cur->next;
      delete cur;
      cur = temp;
    }
  }
}

#endif

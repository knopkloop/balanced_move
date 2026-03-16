#include <iostream>

#include "balanced_move.h"
#include "subfunctions.h"

int main()
{
  Vec<List<int>*> v(5);
  try
  {
    v[0] = new List<int>(1);
    v[0]->next = new List<int>(2);
    v[0]->next->next = new List<int>(3);
    v[0]->next->next->next = new List<int>(4);

    v[1] = new List<int>(5);
    v[1]->next = new List<int>(6);

    v[2] = nullptr;

    v[3] = new List<int>(7);
    v[3]->next = new List<int>(8);
    v[3]->next->next = new List<int>(9);
    v[3]->next->next->next = new List<int>(10);

    v[4] = new List<int>(11);

    print_vec(v);

    Vec<List<int>*> res = balanced_move(std::move(v), 4);

    print_vec(res);

    clean(res);
  }
  catch (...)
  {
    clean(v);
  }
}

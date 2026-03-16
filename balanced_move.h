#ifndef BALANCED_MOVE_H
#define BALANCED_MOVE_H
#include <iostream>
template < class T >
struct List
{
  T val;
  List< T >* next;
};

template < class T >
struct Vec
{
  T* data;
  size_t s;
  size_t cap;

  T& operator[](size_t id)
  {
    return data[id];
  }

  const T& operator[](size_t id) const
  {
    return data[id];
  }
};

template < class T >
Vec< List<T>* > balanced_move(Vec< List<T>* > v, size_t k)
{
  size_t total_s = 0;
  for (size_t i = 0; i < v.s; ++i)
  {
    for (List<T>* cur = v[i]; cur; cur = cur->next)
    {
      ++total_s;
    }
  }

  if (total_s == 0)
  {
    return Vec< List<T>* >();
  }
}


#endif

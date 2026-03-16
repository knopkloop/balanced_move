#ifndef BALANCED_MOVE_H
#define BALANCED_MOVE_H
#include <iostream>
template < class T >
struct List
{
  T val;
  List< T >* next;

  List(const T& value) : val(value), next(nullptr) {}
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
}


#endif

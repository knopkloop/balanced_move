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
};

template < class T >
Vec< List<T>* > balanced_move(Vec< List<T>* > v, size_t k);
#endif

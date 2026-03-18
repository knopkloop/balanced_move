#include <iostream>

template <class T>
struct List
{
  T val;
  List<T>* next;
};

template <class T>
struct Vec
{
  T* data;
  size_t s;
  size_t cap;
};

template <class T>
Vec<List<T>*> balanced_move(Vec< List<T>* > v, size_t k)
{
  if (v.s == 0)
  {
    return v;
  }

  size_t total_s = 0;
  for (size_t i = 0; i < v.s; ++i)
  {
    if (v.data[i])
    {
      List<T>* ptr = v.data[i];
      while(ptr)
      {
        ++total_s;
        ptr = ptr->next;
      }
    }
  }

  size_t kol = (total_s + k - 1) / k;
  List<T>** heads = nullptr;
  List<T>** tails = nullptr;

  Vec< List<T>* > res;
  res.data = nullptr;
  res.s = kol;
  res.cap = kol;

  try
  {
    heads = new List<T>*[kol];
    tails = new List<T>*[kol];

    for(size_t i = 0; i < kol; ++i)
    {
      heads[i] = nullptr;
      tails[i] = nullptr;
    }
  }
  catch (const std::bad_alloc& e)
  {
    delete[] heads;
    delete[] tails;
    throw;
  }

  size_t cnt = 0;
  try
  {
    for(size_t i = 0; i < v.s; ++i)
    {
      List<T>* ptr = v.data[i];
      v.data[i] = nullptr;

      while(ptr)
      {
        List<T>* tmp = ptr->next;
        ptr->next = nullptr;

        size_t idx = cnt / k;

        if (!heads[idx])
        {
          heads[idx] = ptr;
          tails[idx] = ptr;
        }
        else
        {
          tails[idx]->next = ptr;
          tails[idx] = ptr;
        }
        ++cnt;
        ptr = tmp;
      }
    }

    res.data = heads;
    delete[] tails;

    return res;
  }
  catch(...)
  {
    for(size_t i = 0; i < kol; ++i)
    {
      List<T> *ptr = heads[i];
      while(ptr)
      {
        List<T>* tmp = ptr->next;
        delete ptr;
        ptr = tmp;
      }
    }

    delete[] heads;
    delete[] tails;
    throw;
  }
}

int main()
{}

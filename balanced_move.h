#ifndef BALANCED_MOVE_H
#define BALANCED_MOVE_H
#include <cstddef>

template <class T>
struct List
{
  T val;
  List<T>* next;
  List(const T& v = T(), List<T>* n = nullptr) : val(v), next(n) {}
};

template <class T>
struct Vec
{
  T* data;
  size_t s;
  size_t cap;

  Vec() : data(nullptr), s(0), cap(0) {}

  Vec(size_t size) : s(size), cap(size)
  {
    data = new T[size]();
  }

  ~Vec()
  {
    delete[] data;
  }

  Vec(const Vec&) = delete;
  Vec& operator=(const Vec&) = delete;

  Vec(Vec&& other) noexcept : data(other.data), s(other.s), cap(other.cap)
  {
    other.data = nullptr;
    other.s = 0;
    other.cap = 0;
  }

  T& operator[](size_t id)
  {
    return data[id];
  }

  const T& operator[](size_t id) const
  {
    return data[id];
  }
};

template <class T>
Vec<List<T>*> balanced_move(Vec<List<T>*> v, size_t k)
{
  if (k == 0) k = 1;

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
    return Vec<List<T>*>();
  }

  size_t kol = (total_s + k - 1) / k;
  Vec<List<T>*> res(kol);

  try
  {
    size_t pos = 0;
    for (size_t i = 0; i < v.s; ++i)
    {
      List<T>* cur = v[i];
      v[i] = nullptr;

      while (cur)
      {
        List<T>* temp = cur->next;
        cur->next = nullptr;

        size_t idx = pos / k;

        if (!res[idx])
        {
          res[idx] = cur;
        }
        else
        {
          List<T>* tail = res[idx];
          while (tail->next)
          {
            tail = tail->next;
          }
          tail->next = cur;
        }

        ++pos;
        cur = temp;
      }
    }
  }
  catch (...)
  {
    for (size_t i = 0; i < kol; ++i)
    {
      for (List<T>* cur = res[i]; cur; )
      {
        List<T>* temp = cur->next;
        delete cur;
        cur = temp;
      }
    }
    throw;
  }

  return res;
}

#endif

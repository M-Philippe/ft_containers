#ifndef VECTOR_HPP
# define VECTOR_HPP

#include <cstdio>
#include <iostream>
#include "vector_iterator.hpp"

namespace ft
{
  template <class T, class Alloc = std::allocator<T> >
  class vector
  {

  public:
    
    typedef T value_type;
    typedef size_t size_type;
    typedef Alloc allocator_type;
    typedef typename allocator_type::reference reference;
    typedef typename allocator_type::const_reference const_reference;
    
    typedef vector_iterator<T> iterator;

    T *_array;
    size_type _size;
    size_type _capacity;
    allocator_type _alloc;

  public:
    
    /*
    **      CONSTRUCTORS
    */

    explicit vector(const allocator_type &alloc = allocator_type()) : _alloc(alloc) {
      _array = NULL;
      _size = 0;
      _capacity = 0;
    }

    explicit vector(size_type n, const value_type &val = value_type(),
                    const allocator_type &alloc = allocator_type())
                                                  : _alloc(alloc) {
      _capacity = n;
      _array = _alloc.allocate(_capacity);
      for (_size = 0; _size < n; ++_size)
        _alloc.construct(_array + _size, val);
    }

    ~vector() {
      for (size_type i = 0; i < _size; ++i)
        _alloc.destroy(_array + i);
      _alloc.deallocate(_array, _capacity);
    }

    vector& operator= (const vector& rhs) {
      clear();
      if (_capacity >= rhs._size) {
        for (size_type i = 0; i < rhs._size; ++i)
          _alloc.construct(_array + i, rhs._array[i]);
        _size = rhs._size;
      }
      else if (_capacity < rhs._size) {
        _alloc.deallocate(_array, _size);
        _capacity = rhs._size;
        _array = _alloc.allocate(_capacity);
        _size = 0;
        while (_size < rhs._size) {
          _alloc.construct(_array + _size, rhs._array[_size]);
          _size++;
        }
      }
      return (*this);
    }

    /*
    **      ITERATORS
    */

   iterator begin() {
     iterator begin(_array, 0);
     return (begin);
   }

   iterator end() {
     iterator end(_array, _size);
     return (end);
   }

    /*
    **      CAPACITY
    */

    size_type size() const {
      return (_size);
    }

    size_type max_size() const {
      return (_alloc.max_size());
    }
    
    /*  When vector is reduced, iterator must still be valid */
    void  resize(size_type n, value_type val = value_type()) {
      if (n < _size)
        while (_size > n)
          _alloc.destroy(_array + _size--);
      if (n > _size && n < _capacity)
        while (_size < n)
          _alloc.construct(_array + _size++, val);
      if (n > _size && n > _capacity) {
        T* _old_array = _array;
        _capacity = n;
        _array = _alloc.allocate(_capacity);
        for (size_type i = 0; i < _size; ++i)
          _alloc.construct(_array + i, *(_old_array + i));
        _alloc.deallocate(_old_array, _size);
        while (_size < n)
          _alloc.construct(_array + _size++, val);
      }
    }

    size_type capacity() const {
      return (_capacity);
    }

    bool empty() const {
      if (_size == 0)
        return (true);
      else
        return (false);
    }

    /*void reserve (size_type n) {
      // Throw exception if n > max_size
      if (n > _capacity) {

      }
    }*/

    /*
    **      ELEMENT ACCESS
    */

    reference operator[] (size_type n) {
      return (_array[n]);
    }
    
    /* Must add check-bounds */
    reference at(size_type n) {
      return (_array[n]);
    }

    const_reference at(size_type n) const {
      return (_array[n]);
    }

    /*
    **      MODIFIERS
    */

    void assign(size_type n, const value_type &val) {
      for (size_type i = 0; i < n; ++i)
        _alloc.construct(_array + i, val);
    }

    void push_back (const value_type& val) {
      if (_size < _capacity) {
        _array[_size] = val;
        _size++;
      } else {
        T* old_array = _array;
        _capacity == 0 ? _capacity = 1 : _capacity *= 2;
        _array = _alloc.allocate(_capacity);
        for (size_type i = 0; i < _size; ++i)
          _alloc.construct(_array + i, old_array[i]);
        _alloc.construct(_array + _size++, val);
        _alloc.deallocate(old_array, _size);
      }
    }

    /*
    **      ALLOCATOR
    */

    allocator_type get_allocator() const {
      return (_alloc);
    }

  private:

    void clear() {
      for (size_type i = 0; i < _size; ++i)
        _alloc.destroy(_array + i);
    }
    
  }; // class vector

} // namespace ft

#endif
#ifndef VECTOR_HPP
# define VECTOR_HPP

#include <iostream>
#include "vector_exceptions.hpp"
#include "vector_iterator.hpp"
#include "../utils/utils.hpp"

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
    typedef const_iterator<T> const_iterator;

  private:

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

    template <class InputIterator>
    vector (InputIterator first,
            InputIterator last,
            const allocator_type& alloc = allocator_type(),
            typename ft::enable_if<!ft::is_integral<InputIterator>::value, InputIterator>::type* = 0) : _alloc(alloc) {
      InputIterator tmp = first;
      unsigned long count = 0;
      while (tmp++ != last) {
        count++;
      }
      _capacity = count;
      _array = _alloc.allocate(_capacity);
      for (_size = 0; _size < count; ++_size)
        _alloc.construct(_array + _size, *first);
    }

    vector (const vector& x) {
      _size = x._size;
      _capacity = x._capacity;
      _alloc = x._alloc;
      if (_capacity != 0)
        _array = _alloc.allocate(_capacity);
      for (unsigned long i = 0; i < x._size; i++)
        _alloc.construct(_array + i, x._array[i]);
    }

    ~vector() {
      for (size_type i = 0; i < _size; ++i)
        _alloc.destroy(_array + i);
      if (_capacity != 0)
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

   const_iterator begin() const {
     const_iterator begin(_array, 0);
     return (begin);
   }

  const_iterator end() const {
     const_iterator end(_array, _size);
     return (end);
   }

   iterator end() {
     iterator end(_array, _size);
     return (end);
   }

    /*
    **      CAPACITY
    */

    size_type size() const { return (_size); }

    size_type max_size() const { return (_alloc.max_size()); }

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

    size_type capacity() const { return (_capacity); }

    bool empty() const {
      if (_size == 0)
        return (true);
      else
        return (false);
    }

    void reserve (size_type n) {
      if (n > max_size())
        throw (length_error("reserve"));
      else if (n > _capacity) {
        _capacity = n;
        T*  new_array = _alloc.allocate(_capacity);
        size_type tmp_size = _size;
        for (size_type i = 0; i < _size; ++i)
          _alloc.construct(new_array + i, *(_array + i));
        clear();
        _size = tmp_size;
        _alloc.deallocate(_array, _size);
        _array = new_array;
      }
    }

    /*
    **      ELEMENT ACCESS
    */

    reference operator[] (size_type n) { return (_array[n]); }

    reference at(size_type n) {
      if (n >= _size)
        throw (out_of_range(_size, n));
      return (_array[n]);
    }

    const_reference at(size_type n) const {
      if (n >= _size)
        throw (out_of_range(_size, n));
      return (_array[n]);
    }

    reference front() { return (_array[0]); }

    const_reference front() const { return (_array[0]); }

    reference back() { return (_array[_size - 1]); }

    const_reference back() const { return (_array[_size - 1]); }

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

    void pop_back() {
      if (_size > 0)
        _alloc.destroy(&_array[--_size]);
    }

    iterator erase (iterator position) {
      iterator it = position;
      while (it != this->end() - 1) {
        *it = *(it + 1);
        it++;
      }
      _size--;
      return (position);
    }

    /*iterator erase (iterator first, iterator last) {
      iterator ret = first;
      //size_type new_size = first - begin();
      iterator it = last;
      if (it == this->end())
        it--;
      else
        it++;
      iterator ret = first;
          // should keep distance ?
      iterator tmp = this->begin();
      int posStart = 0;
      int posEnd = 0;
      while (tmp++ != first)
        posStart++;
      posEnd = posStart;
      while (tmp++ != last)
        posEnd++;
      while (first != last) {
        _alloc.destroy(_array + posStart++);
        _alloc.construct(_array + posEnd++, *first);
        first++;
        if (it + 1 != this->end())
          it++;
        _size--;
      }
      return (ret);
    }*/

    void swap (vector& x) {
      ft::swap(_size, x._size);
      ft::swap(_capacity, x._capacity);
      ft::swap(_array, x._array);
      ft::swap(_alloc, x._alloc);
    }

    void clear() {
      if (_size == 0)
        return;
      for (size_type i  = 0; i < _size; ++i)
        _alloc.destroy(_array + i);
      _size = 0;
    }

    /*
    **      ALLOCATOR
    */

    allocator_type get_allocator() const { return (_alloc); }

  }; // class vector

} // namespace ft

#endif

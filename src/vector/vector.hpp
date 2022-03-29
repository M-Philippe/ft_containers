#ifndef VECTOR_HPP
#define VECTOR_HPP

#include <iostream>
#include "vector_exceptions.hpp"
#include "../iterator/random_access_iterator.hpp"
#include "../utils/utils.hpp"
#include "../iterator/reverse_iterator.hpp"
#include "../iterator/iterator_traits.hpp"
#include <chrono>
namespace ft
{
  template <class T, class Alloc = std::allocator<T> >
  class vector
  {
  public:
    typedef T value_type;
    typedef Alloc allocator_type;
    typedef typename allocator_type::reference reference;
    typedef typename allocator_type::const_reference const_reference;
    typedef typename allocator_type::pointer pointer;
    typedef typename allocator_type::const_pointer const_pointer;
    typedef typename ft::random_access_iterator<value_type> iterator;
    typedef typename ft::random_access_iterator<const value_type> const_iterator;
    typedef ft::reverse_iterator<iterator> reverse_iterator;
    typedef ft::reverse_iterator<const_iterator> const_reverse_iterator;
    typedef ptrdiff_t difference_type;
    typedef size_t size_type;


  private:
    T *_array;
    size_type _size;
    size_type _capacity;
    allocator_type _alloc;

    size_type calculateCapacity() {  }

  public:
    /*
    **      CONSTRUCTORS
    */

    explicit vector(const allocator_type &alloc = allocator_type()) : _alloc(alloc)
    {
      _array = NULL;
      _size = 0;
      _capacity = 0;
    }

    explicit vector(size_type n, const value_type &val = value_type(),
                    const allocator_type &alloc = allocator_type())
        : _alloc(alloc)
    {
      _capacity = n;
      _array = _alloc.allocate(_capacity);
      for (_size = 0; _size < n; ++_size)
        _alloc.construct(_array + _size, val);
    }

    template <class InputIterator>
    vector(InputIterator first,
           InputIterator last,
           const allocator_type &alloc = allocator_type(),
           typename ft::enable_if<!ft::is_integral<InputIterator>::value, InputIterator>::type = 0) : _alloc(alloc)
    {
      InputIterator tmp = first;
      unsigned long count = 0;
      while (tmp++ != last)
      {
        count++;
      }
      _capacity = count;
      if (_capacity != 0)
        _array = _alloc.allocate(_capacity);
      for (_size = 0; _size < count; ++_size)
        _alloc.construct(_array + _size, *(first++));
    }

    vector(const vector &x)
    {
      _size = x._size;
      _capacity = x._capacity;
      _alloc = x._alloc;
      if (_capacity != 0)
        _array = _alloc.allocate(_capacity);
      for (size_type i = 0; i < x._size; i++)
        _alloc.construct(_array + i, x._array[i]);
    }

    ~vector()
    {
      for (size_type i = 0; i < _size; ++i)
        _alloc.destroy(_array + i);
      if (_capacity != 0)
        _alloc.deallocate(_array, _capacity);
    }

    vector &operator=(const vector &rhs)
    {
      clear();
      if (_capacity >= rhs._size)
      {
        for (size_type i = 0; i < rhs._size; ++i)
          _alloc.construct(_array + i, rhs._array[i]);
        _size = rhs._size;
      }
      else if (_capacity < rhs._size)
      {
        _alloc.deallocate(_array, _size);
        _capacity = rhs._size;
        _array = _alloc.allocate(_capacity);
        while (_size < rhs._size)
        {
          _alloc.construct(_array + _size, rhs._array[_size]);
          _size++;
        }
      }
      return (*this);
    }

    /*
    **      ITERATORS
    */

    iterator begin() { return iterator(_array); }
    const_iterator begin() const { return const_iterator(_array); }
    iterator end() { return iterator(_array + _size); }
    const_iterator end() const { return const_iterator(_array + _size); }
    reverse_iterator rbegin() { return reverse_iterator(_array + _size); }
    const_reverse_iterator rbegin() const { return const_reverse_iterator(_array + _size); }
    reverse_iterator rend() { return reverse_iterator(_array); }
    const_reverse_iterator rend() const {return const_reverse_iterator(_array); }


    /*
    **      CAPACITY
    */

    size_type size() const { return (_size); }

    size_type max_size() const { return (_alloc.max_size()); }

    void resize(size_type n, value_type val = value_type())
    {
      if (n < _size)
        while (_size > n)
          _alloc.destroy(_array + _size--);
      if (n > _size && n < _capacity)
        while (_size < n)
          _alloc.construct(_array + _size++, val);
      if (n > _size && n > _capacity)
      {
        T *_old_array = _array;
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

    bool empty() const
    {
      if (_size == 0)
        return (true);
      else
        return (false);
    }

    void reserve(size_type n)
    {
      if (n > max_size())
        throw(length_error("reserve"));
      else if (n > _capacity)
      {
        _capacity = n;
        T *new_array = _alloc.allocate(_capacity);
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

    reference operator[](size_type n) { return (_array[n]); }
    const_reference operator[](size_type n) const { return (_array[n]); }

    reference at(size_type n)
    {
      if (n >= _size)
        throw(out_of_range(_size, n));
      return (_array[n]);
    }

    const_reference at(size_type n) const
    {
      if (n >= _size)
        throw(out_of_range(_size, n));
      return (_array[n]);
    }

    reference front() { return (_array[0]); }

    const_reference front() const { return (_array[0]); }

    reference back() { return (_array[_size - 1]); }

    const_reference back() const { return (_array[_size - 1]); }

    /*
    **      MODIFIERS
    */

    template <class InputIterator>
    void assign (InputIterator first, InputIterator last, typename ft::enable_if<!ft::is_integral<InputIterator>::value, InputIterator>::type = 0) {
      this->clear();
      *this = vector(first, last);
    }

    void assign(size_type n, const value_type &val)
    {
      if (n > _capacity) {
        for (size_type i = 0; i < _size; ++i)
          _alloc.destroy(_array + i);
        _alloc.deallocate(_array, _size);
        _capacity > n ? _capacity = n * 2 : _capacity = n;
        _array = _alloc.allocate(_capacity);
      }
      for (size_type i = 0; i < n; ++i) {
        _alloc.destroy(_array + i);
        _alloc.construct(_array + i, val);
      }
      _size = n;
    }

    void push_back(const value_type &val)
    {
      if (_size < _capacity)
      {
        _array[_size] = val;
        _size++;
      }
      else
      {
        T *old_array = _array;
        _capacity == 0 ? _capacity = 1 : _capacity *= 2;
        _array = _alloc.allocate(_capacity);
        for (size_type i = 0; i < _size; ++i)
          _alloc.construct(_array + i, old_array[i]);
        _alloc.construct(_array + _size++, val);
        _alloc.deallocate(old_array, _size);
      }
    }

    void pop_back()
    {
      if (!empty()) {
        _alloc.destroy(&_array[--_size]);
      }
    }

    iterator insert (iterator position, const value_type& val) {
      size_type indexPosition = position - begin();
      this->insert(position, 1, val);
      return (iterator(begin() + indexPosition));
    }

    void insert (iterator position, size_type n, const value_type& val) {
      size_type indexPosition = position - begin();
      if (n + _size >= _capacity) {
        ft::vector<value_type> tmp(begin() + indexPosition, end());
        if (_capacity == 0)
          this->reserve(1);
        else if (n + _size > _capacity * 2)
          this->reserve((n + _size) * 2);
        else
          this->reserve(_capacity * 2);
        size_type count = 0;
        for (size_type i = 0; i < n; i++)
          _alloc.construct(_array + indexPosition++, val);
        while (count < tmp.size())
          _alloc.construct(_array + indexPosition++, tmp[count++]);
        _size += n;
      } else {
        ft::vector<value_type> tmp(begin() + indexPosition, end());
        for (size_type i = 0; i < n; i++) {
          _alloc.destroy(this->_array + indexPosition);
          _alloc.construct(this->_array + indexPosition++, val);
        }
        for (size_type i = 0; i < tmp.size(); i++) {
          _alloc.destroy(this->_array + indexPosition);
          _alloc.construct(this->_array + indexPosition++, tmp[i]);
        }
        _size += n;
      }
    }

    template <class InputIterator>
    void insert (iterator position, InputIterator first, InputIterator last,
    typename ft::enable_if<!ft::is_integral<InputIterator>::value, InputIterator>::type = 0) {
      size_type indexPosition = position - begin();
      size_type n = last - first;
      if (n + _size >= _capacity) {
        ft::vector<value_type> tmp(begin() + indexPosition, end());
        if (_capacity == 0)
          this->reserve(1);
        else if (n + _size > _capacity * 2)
          this->reserve((n + _size) * 2);
        else
          this->reserve(_capacity * 2);
        size_type count = 0;
        while (first != last)
          _alloc.construct(this->_array + indexPosition++, *(first++));
        while (count < tmp.size())
          _alloc.construct(this->_array + indexPosition++, tmp[count++]);
        _size += n;
      } else {
        ft::vector<value_type> tmp(begin() + indexPosition, end());
        while (first != last) {
          _alloc.destroy(this->_array + indexPosition);
          _alloc.construct(this->_array + indexPosition++, *(first++));
        }
        for (size_type i = 0; i < tmp.size(); i++) {
          _alloc.destroy(this->_array + indexPosition);
          _alloc.construct(this->_array + indexPosition++, tmp[i]);
        }
        _size += n;
      }
    }

    iterator erase(iterator position)
    {
      iterator it = position;
      while (it != this->end() - 1)
      {
        *it = *(it + 1);
        it++;
      }
      _size--;
      return (position);
    }

    iterator erase (iterator first, iterator last) {
      size_type indexLast = 0;
      iterator start = begin();
      iterator storeFirst = first;
      while (start != last) {
        start++;
        indexLast++;
      }
      ft::vector<T> tmp;
      iterator end = this->end() - 1;
      while (last - 1 != end) {
        tmp.push_back(*end);
        this->pop_back();
        end--;
      }
      while (first != last) {
        this->pop_back();
        first++;
        indexLast--;
      }
      while (tmp.size() > 0) {
        this->push_back(tmp.back());
        tmp.pop_back();
      }
      iterator it = begin();
      size_type i = 0;
      while (i++ != indexLast)
        it++;
      return (it);
    }

    void swap(vector &x)
    {
      ft::swap(_size, x._size);
      ft::swap(_capacity, x._capacity);
      ft::swap(_array, x._array);
      ft::swap(_alloc, x._alloc);
    }

    void clear()
    {
      if (_size == 0)
        return;
      for (size_type i = 0; i < _size; ++i)
        _alloc.destroy(_array + i);
      _size = 0;
    }

    /*
    **      ALLOCATOR
    */

    allocator_type get_allocator() const { return (_alloc); }


    /*
    **      NON-MEMBERS FUNCTIONS
    */

    template <class T_, class Alloc_>
    friend bool operator== (const vector<T_, Alloc_>& lhs, const vector<T_, Alloc_>& rhs);
    template <class T_, class Alloc_>
    friend bool operator!= (const vector<T_, Alloc_>& lhs, const vector<T_, Alloc_>& rhs);
    template <class T_, class Alloc_>
    friend bool operator<  (const vector<T_, Alloc_>& lhs, const vector<T_, Alloc_>& rhs);
    template <class T_, class Alloc_>
    friend bool operator<= (const vector<T_, Alloc_>& lhs, const vector<T_, Alloc_>& rhs);
    template <class T_, class Alloc_>
    friend bool operator>  (const vector<T_, Alloc_>& lhs, const vector<T_, Alloc_>& rhs);
    template <class T_, class Alloc_>
    friend bool operator>= (const vector<T_, Alloc_>& lhs, const vector<T_, Alloc_>& rhs);

    template <class T_, class Alloc_>
    void swap (vector<T_, Alloc_>& x, vector<T_, Alloc_>& y);
  }; // class vector

  template <class T, class Alloc>
  bool operator==(const vector<T, Alloc>& lhs, const vector<T, Alloc>& rhs) {
    if (lhs.size() != rhs.size())
      return (false);
    else
      return (ft::equal(lhs.begin(), lhs.end(), rhs.begin()));
  }

  template <class T, class Alloc>
  bool operator!=(const vector<T, Alloc>& lhs, const vector<T, Alloc>& rhs) { return !(rhs == lhs); }

  template <class T, class Alloc>
  bool operator<(const vector<T, Alloc>& lhs, const vector<T, Alloc>& rhs) {
    return (ft::lexicographical_compare(lhs.begin(), lhs.end(), rhs.begin(), rhs.end()));
  }

  template <class T_, class Alloc_>
  bool operator<= (const vector<T_, Alloc_>& lhs, const vector<T_, Alloc_>& rhs) { return !(rhs < lhs); }
  template <class T_, class Alloc_>
  bool operator>  (const vector<T_, Alloc_>& lhs, const vector<T_, Alloc_>& rhs) { return rhs < lhs; }
  template <class T_, class Alloc_>
  bool operator>= (const vector<T_, Alloc_>& lhs, const vector<T_, Alloc_>& rhs) { return !(lhs < rhs); }

  template <class T, class Alloc>
  void swap(vector<T, Alloc>& lhs, vector<T, Alloc>& rhs) { lhs.swap(rhs); }

} // namespace ft

#endif

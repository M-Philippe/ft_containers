#include <cstdio>
#include <iostream>

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

    /*  Iterator  */
    typedef unsigned int u_int;

    class vector_iterator {
      private:
        value_type*    _link;
        u_int _position;

      public:
        vector_iterator(value_type* link, u_int pos = 0) {
          _link = link;
          _position = pos;
        }

        value_type& operator*() {
          return (*_link);
        }

        vector_iterator& operator++() {
          _link++;
          _position++;
          return (*this);
        }

        vector_iterator operator++(int) {
          vector_iterator it(*this);
          ++(*this);
          return (it);
        }

        vector_iterator& operator--() {
          _link--;
          _position--;
          return (*this);
        }

      }; // class iterator

    typedef vector_iterator iterator;

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
      _array = _alloc.allocate(n);
      _size = n;
      _capacity = 1;
      while (_capacity <= n)
        _capacity = _capacity * (2 * _capacity);
      assign(n, val);
    }

    ~vector() {
      _alloc.deallocate(_array, _size);
    }

    /*
    **      ITERATORS
    */

   iterator begin() {
     iterator begin(&_array[0]);
     return (begin);
   }

    /*
    **      CAPACITY
    */

    size_type size() const {
      return (_size);
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

    /*
    **      ELEMENT ACCESS
    */

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
        _array[i] = val;
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
          _array[i] = old_array[i];
        _array[_size++] = val;
        _alloc.deallocate(old_array, _size);
      }
    }

    /*
    **      ALLOCATOR
    */

    allocator_type get_allocator() const {
      return (_alloc);
    }
  };

} // namespace ft

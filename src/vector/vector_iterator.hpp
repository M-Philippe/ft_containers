#ifndef VECTOR_ITERATOR_HPP
# define VECTOR_ITERATOR_HPP

//#include <iterator>

namespace ft {

  template <class T>
  struct iterator_traits
    {
        typedef ptrdiff_t                       difference_type;
        typedef T                               value_type;
        typedef T*                              pointer;
        typedef T&                              reference;
    };

  template <typename T>
  class const_iterator : public ft::iterator_traits<T> {

    public:
      typedef typename ft::iterator_traits<T>::value_type value_type;
      typedef typename ft::iterator_traits<T>::difference_type difference_type;
      typedef typename ft::iterator_traits<T>::pointer pointer;
      typedef typename ft::iterator_traits<T>::reference reference;

    protected:
      const T*    _link;
      unsigned long _pos;

    public:
      const_iterator() {
        _link = NULL;
        _pos = 0;
      };

      const_iterator(const const_iterator& org) {
        _link = org._link;
        _pos = org._pos;
      }

      const_iterator(pointer link, size_t pos) {
        _link = link + pos;
        _pos = pos;
      }

      ~const_iterator() {};

      bool operator==(const const_iterator& second) {
        return (_link == second._link);
      }

      bool operator!=(const const_iterator& second) {
        return ( !(*this == second));
      }

      const value_type operator*() {
        return (*_link);
      }

      pointer operator->() {
        return (const_cast<pointer>(_link));
      }

      const_iterator& operator++() {
        _link++;
        _pos++;
        return (*this);
      }

      const_iterator operator++(int) {
        const_iterator it(*this);
        ++(*this);
        _pos++;
        return (it);
      }

      const_iterator& operator--() {
        _link--;
        _pos--;
        return (*this);
      }

      const_iterator operator--(int) {
        const_iterator it(*this);
        --(*this);
        --_pos;
        return it;
      }

      // bug here?
      const_iterator operator+(int rhs) {
        const_iterator ret(*this);
        ret._link += rhs;
        ret._pos += rhs;
        return (ret);
      }

      const_iterator operator-(int rhs) {
        const_iterator ret(*this);
        ret->_link -= rhs;
        return (ret);
      }

      friend bool  operator<(const const_iterator& lhs, const const_iterator& rhs) {
        return (lhs._link < rhs._link);
      }

      friend difference_type operator-(const const_iterator& lhs, const const_iterator& rhs){
        return (lhs._pos - rhs._pos);
      }

    }; // class const_iterator

  template <typename T>
  class vector_iterator : public const_iterator<T> {
    public:
      typedef T value_type;

      vector_iterator() {
        this->_link = NULL;
      };

      vector_iterator(value_type* link, size_t pos) {
        this->_link = link + pos;
      }

      ~vector_iterator() {};

      value_type& operator*() {
        return (*(const_cast<T*>(this->_link)));
      }

      vector_iterator operator+(int rhs) {
        vector_iterator ret(*this);
        ret._link += rhs;
        ret._pos += rhs;
        return (ret);
      }

      vector_iterator operator-(int rhs) {
        vector_iterator ret(*this);
        ret._link -= rhs;
        return (ret);
      }
  }; // class iterator

}; // namespace ft

#endif

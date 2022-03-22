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
      typedef typename ft::iterator_traits<const T>::value_type value_type;
      typedef typename ft::iterator_traits<const T>::difference_type difference_type;
      typedef typename ft::iterator_traits<const T>::pointer pointer;
      typedef typename ft::iterator_traits<const T>::reference reference;

    protected:
      pointer    _link;
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

      reference operator*() {
        return (*_link);
      }

      reference operator[](difference_type idx) {
        return (*(_link + idx));
      }

      pointer operator->() {
        return (_link);
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

      const_iterator operator+(int rhs) {
        const_iterator ret(*this);
        ret.operator+=(rhs);
        return (ret);
      }

      const_iterator& operator+=(int rhs) {
        _link += rhs;
        _pos += rhs;
        return (*this);
      }

      const_iterator operator-(int rhs) {
        const_iterator ret(*this);
        ret.operator-=(rhs);
        return (ret);
      }

      difference_type operator-(const const_iterator& b) {
        return (_link - b._link);
      }

      const_iterator& operator-=(int rhs) {
        _link -= rhs;
        _pos -= rhs;
        return (*this);
      }

      bool operator<(const const_iterator& rhs) const { return (_link < rhs._link); }
      bool operator>(const const_iterator& rhs) const { return (_link > rhs._link); }
      bool operator>=(const const_iterator& rhs) const { return (_link >= rhs._link); }
      bool operator<=(const const_iterator& rhs) const { return (_link <= rhs._link); }

      /* friend necessary because operator+ overload can only be unary or binary */
      friend const_iterator operator+(const int& lhs, const const_iterator& rhs) {
        const_iterator ret(rhs);
        ret += lhs;
        return (ret);
      }

    }; // class const_iterator

  template <typename T>
  class vector_iterator : public const_iterator<T> {
    public:
      typedef typename ft::iterator_traits<T>::value_type value_type;
      typedef typename ft::iterator_traits<T>::difference_type difference_type;
      typedef typename ft::iterator_traits<T>::pointer pointer;
      typedef typename ft::iterator_traits<T>::reference reference;

      vector_iterator() {
        this->_link = NULL;
        this->_pos = 0;
      };

      vector_iterator(const vector_iterator& org) {
        this->_link = org._link;
        this->_pos = org._pos;
      }

      vector_iterator(value_type* link, size_t pos) {
        this->_link = link + pos;
        this->_pos = pos;
      }

      ~vector_iterator() {};

      reference operator*() {
        return (const_cast<reference>(*(this->_link)));
      }

      reference operator[](difference_type idx) {
        return (const_cast<reference>(*(this->_link + idx)));
      }

      pointer operator->() {
        return (const_cast<pointer>(this->_link));
      }

      vector_iterator operator+(int rhs) {
        vector_iterator ret(*this);
        ret._link += rhs;
        ret._pos += rhs;
        return (ret);
      }

      vector_iterator operator-(int rhs) {
        vector_iterator ret(*this);
        ret.operator-=(rhs);
        return (ret);
      }

      difference_type operator-(const vector_iterator& b) {
        return (this->_pos - b._pos);
      }
  }; // class iterator

}; // namespace ft

#endif

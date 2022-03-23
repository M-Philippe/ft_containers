#ifndef RANDOM_ACCESS_ITERATOR_HPP
# define RANDOM_ACCESS_ITERATOR_HPP

#include "iterator.hpp"

namespace ft {

template <typename T>
  class random_access_iterator : public ft::iterator<ft::random_access_iterator_tag, T>
  {

  public:
    typedef typename ft::iterator<ft::random_access_iterator_tag, T>::value_type value_type;
    typedef typename ft::iterator<ft::random_access_iterator_tag, T>::difference_type difference_type;
    typedef T *pointer;
    typedef T &reference;
    typedef typename ft::iterator<ft::random_access_iterator_tag, T>::iterator_category iterator_category;

  private:
    pointer _link;

  public:
    random_access_iterator() {  _link = NULL; }

    random_access_iterator(const random_access_iterator &org) {  _link = org._link;  }

    random_access_iterator(pointer link) {  _link = link; }

    random_access_iterator&  operator=(const random_access_iterator& org) {
      _link = org._link;
      return (*this);
    }

    operator random_access_iterator<const T>() {  return (random_access_iterator<const T>(_link));  }

    ~random_access_iterator() {};

    bool operator==(const random_access_iterator &second) { return (_link == second._link); }

    bool operator!=(const random_access_iterator &second) { return (!(*this == second)); }

    reference operator*() { return (*_link);  }

    reference operator[](difference_type idx) { return (*(_link + idx));  }

    pointer operator->() {  return (_link); }

    random_access_iterator &operator++() {
      _link++;
      return (*this);
    }

    random_access_iterator operator++(int) {
      random_access_iterator it(*this);
      ++(*this);
      return (it);
    }

    random_access_iterator &operator--() {
      _link--;
      return (*this);
    }

    random_access_iterator operator--(int) {
      random_access_iterator it(*this);
      --(*this);
      return it;
    }

    random_access_iterator operator+(int rhs) {
      random_access_iterator ret(*this);
      ret.operator+=(rhs);
      return (ret);
    }

    random_access_iterator &operator+=(int rhs) {
      _link += rhs;
      return (*this);
    }

    random_access_iterator operator-(int rhs) {
      random_access_iterator ret(*this);
      ret.operator-=(rhs);
      return (ret);
    }

    difference_type operator-(const random_access_iterator &b) {  return (_link - b._link); }

    random_access_iterator &operator-=(int rhs) {
      _link -= rhs;
      return (*this);
    }

    bool operator<(const random_access_iterator &rhs) const { return (_link < rhs._link); }
    bool operator>(const random_access_iterator &rhs) const { return (_link > rhs._link); }
    bool operator>=(const random_access_iterator &rhs) const { return (_link >= rhs._link); }
    bool operator<=(const random_access_iterator &rhs) const { return (_link <= rhs._link); }

    /* friend necessary because operator+ overload can only be unary or binary */
    friend random_access_iterator operator+(const int &lhs, const random_access_iterator &rhs) {
      random_access_iterator ret(rhs);
      ret += lhs;
      return (ret);
    }

  }; // class random_access_iterator

}; // namespace ft

#endif

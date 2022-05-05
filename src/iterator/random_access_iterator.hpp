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
    const pointer &base() const { return _link; }

    ~random_access_iterator() {};

		friend bool operator==(const random_access_iterator& lhs, const random_access_iterator& rhs) { return (lhs._link == rhs._link); }
		friend bool operator!= (const random_access_iterator& lhs, const random_access_iterator& rhs) { return !(lhs == rhs); }

    reference operator*() const { return (*_link);  }

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

    difference_type operator-(const random_access_iterator &b) const {  return (_link - b._link); }

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

  template<class IterL, class IterR>
  bool operator==(random_access_iterator<IterL> const &lhs, random_access_iterator<IterR> const &rhs) { return lhs.base() == rhs.base(); }
  template<class IterL, class IterR>
  bool operator<(random_access_iterator<IterL> const &lhs, random_access_iterator<IterR> const &rhs) { return lhs.base() < rhs.base(); }
  template<class IterL, class IterR>
	bool operator<=(random_access_iterator<IterL> const &lhs, random_access_iterator<IterR> const &rhs) { return lhs.base() <= rhs.base(); }
	template<class IterL, class IterR>
	bool operator!=(random_access_iterator<IterL> const &lhs, random_access_iterator<IterR> const &rhs) { return lhs.base() != rhs.base(); }
	template<class IterL, class IterR>
	bool operator>(random_access_iterator<IterL> const &lhs, random_access_iterator<IterR> const &rhs) { return lhs.base() > rhs.base(); }
	template<class IterL, class IterR>
	bool operator>=(random_access_iterator<IterL> const &lhs, random_access_iterator<IterR> const &rhs) { return lhs.base() >= rhs.base(); }

	template<class IteratorL, class IteratorR>
	typename random_access_iterator<IteratorL>::difference_type
	operator-(random_access_iterator<IteratorL> const &lhs, random_access_iterator<IteratorR> const &rhs)
	{ return lhs.base() - rhs.base(); }

	template<class Iterator>
	random_access_iterator<Iterator>
	operator+(typename random_access_iterator<Iterator>::difference_type n, random_access_iterator<Iterator> const &i)
	{ return random_access_iterator<Iterator>(i.base() + n); }

}; // namespace ft

#endif

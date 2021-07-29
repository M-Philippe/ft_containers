#ifndef VECTOR_ITERATOR_HPP
# define VECTOR_ITERATOR_HPP

namespace ft {

  template <typename T>
  class const_iterator {

    public:
      typedef const T value_type;

    protected:
      const T*    _link;

    public:
      const_iterator() {
        _link = NULL;
      };

      const_iterator(value_type* link, size_t pos) {
        _link = link + pos;
      }

      ~const_iterator() {};

      bool operator==(const const_iterator& second) {
        return (_link == second._link);
      }

      bool operator!=(const const_iterator& second) {
        return ( !(*this == second));
      }

      virtual value_type& operator*() {
        return (*_link);
      }

      const_iterator& operator++() {
        _link++;
        return (*this);
      }

      const_iterator operator++(int) {
        const_iterator it(*this);
        ++(*this);
        return (it);
      }

      const_iterator& operator--() {
        _link--;
        return (*this);
      }

      const_iterator operator+(int rhs) {
        _link += rhs;
        return (*this);
      }

    }; // class const_iterator

  template <typename T>
  class vector_iterator : public const_iterator<T> {
    public:
      typedef T value_type;

      vector_iterator(value_type* link, size_t pos) {
        this->_link = link + pos;
      }

      ~vector_iterator() {};

      value_type& operator*() {
        return (*(const_cast<T*>(this->_link)));
      }

  }; // class iterator

}; // namespace ft

#endif

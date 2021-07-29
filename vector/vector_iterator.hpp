#ifndef VECTOR_ITERATOR_HPP
# define VECTOR_ITERATOR_HPP

namespace ft {

  template <typename T>
  class vector_iterator {

    public:
      typedef T value_type;

    private:
      value_type*    _link;

    public:
      vector_iterator(value_type* link, size_t pos) {
        _link = link + pos;
      }

      bool operator==(const vector_iterator& second) {
        return (_link == second._link);
      }

      bool operator!=(const vector_iterator& second) {
        return ( !(*this == second));
      }

      value_type& operator*() {
        return (*_link);
      }

      vector_iterator& operator++() {
        _link++;
        return (*this);
      }

      vector_iterator operator++(int) {
        vector_iterator it(*this);
        ++(*this);
        return (it);
      }

      vector_iterator& operator--() {
        _link--;
        return (*this);
      }

      vector_iterator operator+(int rhs) {
        _link += rhs;
        return (*this);
      }

    }; // class iterator

}; // namespace ft

#endif

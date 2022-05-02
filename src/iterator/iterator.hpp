#ifndef ITERATOR_HPP
# define ITERATOR_HPP

#include <cstddef> // ptrdiff_t
#include <iterator>

namespace ft {

  //struct input_iterator_tag {};
  //struct output_iterator_tag {};
  //struct forward_iterator_tag : input_iterator_tag {};
  //struct bidirectional_iterator_tag : forward_iterator_tag {};
  //struct random_access_iterator_tag : bidirectional_iterator_tag {};

  typedef struct std::input_iterator_tag input_iterator_tag;
	typedef struct std::output_iterator_tag output_iterator_tag;
	typedef struct std::forward_iterator_tag forward_iterator_tag;
	typedef struct std::bidirectional_iterator_tag bidirectional_iterator_tag;
	typedef struct std::random_access_iterator_tag random_access_iterator_tag;

  template <
      typename Category,
      typename T,
      typename Distance = std::ptrdiff_t,
      typename Pointer = T *,
      typename Reference = T &>
  struct iterator
  {
    typedef T value_type;
    typedef Distance difference_type;
    typedef Pointer pointer;
    typedef Reference reference;
    typedef Category iterator_category;
  }; // iterator

}; // namespace ft

#endif

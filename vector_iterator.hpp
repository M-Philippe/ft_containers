#ifndef VECTOR_ITERATOR_HPP
# define VECTOR_ITERATOR_HPP

// tmp
#include <unistd.h>

namespace ft {

    /*  Iterator  */
    typedef unsigned int u_int;
    
    template <typename T>
    class vector_iterator {
      public:
        typedef T value_type;
      
      private:
        value_type*    _link;

      public:
        vector_iterator(value_type* link, u_int pos) {
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

      }; // class iterator

}; // namespace ft

#endif
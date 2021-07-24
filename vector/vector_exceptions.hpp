#ifndef VECTOR_EXCEPTIONS_HPP
# define VECTOR_EXCEPTIONS_HPP

#include <string>
#include <cstdio> // sprintf

namespace ft {

  class length_error : public std::exception {
    public:
      const char* what() const throw() { return("vector::reserve"); }
  };

  class out_of_range : public std::exception
  {
    public:
      out_of_range(size_t size, size_t n) {
        _size = size;
        _n = n;
        assemble_error_message();
      }

      void assemble_error_message() {
        ret = "vector::_M_range_check: __n (which is ";
        char s[sizeof(int) * 8 + 1];
        sprintf(s, "%zu", _n);
        ret += s;
        ret += ") >= this->size() (which is ";
        sprintf(s, "%zu", _size);
        ret = ret + s;
        ret += ")";
      }

      const char* what() const throw() { return(ret.c_str()); }

    private:
      size_t _size;
      size_t _n;
      std::string ret;
  };

} // namespace ft

# endif

#ifndef UTILS_HPP
# define UTILS_HPP

#include "../iterator/iterator_traits.hpp"
#include "../iterator/iterator.hpp"

namespace ft {

	template <typename T>
	void swap(T& a, T& b) {
		T tmp(a);
		a = b;
		b = tmp;
	}

	template<class InputIterator>
	typename ft::iterator_traits<InputIterator>::difference_type
		__distance (InputIterator first, InputIterator last, ft::random_access_iterator_tag)
	{return (last - first);}

	template<class InputIterator>
	typename ft::iterator_traits<InputIterator>::difference_type
		__distance (InputIterator first, InputIterator last, ft::input_iterator_tag) {
			typename ft::iterator_traits<InputIterator>::difference_type distance = 0;
			while (first != last) {
				first++;
				distance++;
			}
			return (distance);
		}

	/* If it is a random-access iterator,
	the function uses operator- to calculate this.
	Otherwise, the function uses the increase operator (operator++) repeatedly.
	*/
	template<class InputIterator>
	typename ft::iterator_traits<InputIterator>::difference_type
		distance (InputIterator first, InputIterator last)
	{
		typedef ft::iterator_traits<InputIterator> traits;
		return __distance(first, last, typename traits::iterator_category());
	}

	template<bool Cond, class T = void> struct enable_if {};
  template<class T> struct enable_if<true, T> { typedef T type; };


	template <bool is_integral, typename T>
  struct is_integral_res {
		typedef T type;
		static const bool value = is_integral;
		};

	template <typename>
  struct is_integral_type : public is_integral_res<false, bool> {};

	template <>
  struct is_integral_type<int> : public is_integral_res<true, int> {};

	template <typename T>
        struct is_integral : public is_integral_type<T> { };
} // namespace ft

#endif

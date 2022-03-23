#ifndef UTILS_HPP
# define UTILS_HPP

#include "../iterator/iterator_traits.hpp"

namespace ft {

	template <typename T>
	void swap(T& a, T& b) {
		T tmp(a);
		a = b;
		b = tmp;
	}

	template<class InputIterator>
	typename ft::iterator_traits<InputIterator>::difference_type
		distance (InputIterator first, InputIterator last)
	{
		typename ft::iterator_traits<InputIterator>::difference_type distance = 0;
		while (first != last) {
			first++;
			distance++;
		}
		return (distance);
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

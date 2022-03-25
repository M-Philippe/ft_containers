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
	the function uses operator- to calculate distance.
	Otherwise, the function uses the increase operator (operator++) repeatedly.
	*/
	template<class InputIterator>
	typename ft::iterator_traits<InputIterator>::difference_type
		distance (InputIterator first, InputIterator last)
	{
		typedef ft::iterator_traits<InputIterator> traits;
		return __distance(first, last, typename traits::iterator_category());
	}

	/*
	**	ENABLE_IF
	*/
	template<bool Cond, class T = void> struct enable_if {};
  template<class T> struct enable_if<true, T> { typedef T type; };

	template <bool is_integral, typename T>
  struct is_integral_res {
		typedef T type;
		static const bool value = is_integral;
		};

	/*
	**	IS_INTEGRAL
	*/
	template <typename> struct is_integral_type : public is_integral_res<false, bool> {};

	template <> struct is_integral_type<bool> : public is_integral_res<true, bool> {};
	template <> struct is_integral_type<char> : public is_integral_res<true, char> {};
	template <> struct is_integral_type<char16_t> : public is_integral_res<true, char16_t> {};
	template <> struct is_integral_type<char32_t> : public is_integral_res<true, char32_t> {};
	template <> struct is_integral_type<wchar_t> : public is_integral_res<true, wchar_t> {};
	template <> struct is_integral_type<signed char> : public is_integral_res<true, signed char> {};
	template <> struct is_integral_type<short int> : public is_integral_res<true, short int> {};
	template <> struct is_integral_type<int> : public is_integral_res<true, int> {};
	template <> struct is_integral_type<long int> : public is_integral_res<true, long int> {};
	template <> struct is_integral_type<long long int> : public is_integral_res<true, long long int> {};
	template <> struct is_integral_type<unsigned char> : public is_integral_res<true, unsigned char> {};
	template <> struct is_integral_type<unsigned short int> : public is_integral_res<true, unsigned short int> {};
	template <> struct is_integral_type<unsigned int> : public is_integral_res<true, unsigned int> {};
	template <> struct is_integral_type<unsigned long int> : public is_integral_res<true, unsigned long int> {};
	template <> struct is_integral_type<unsigned long long int> : public is_integral_res<true, unsigned long long int> {};

	template <typename T>
  struct is_integral : public is_integral_type<T> { };
} // namespace ft

#endif

#ifndef UTILS_HPP
# define UTILS_HPP

#include "../iterator/iterator_traits.hpp"
#include "../iterator/iterator.hpp"

namespace ft {

	template <class T1, class T2>
	struct pair {
		typedef T1	first_type;
		typedef T2	second_type;

		pair() : first(first_type()), second(second_type()) {}
		template<class U, class V>
		pair (const pair<U,V>& pr) : first(pr.first), second(pr.second)  {}
		pair (const first_type& a, const second_type& b) : first(a), second(b) {}
		~pair() {}
		pair& operator= (const pair& pr) {
			if (this != &pr) {
				first = pr.first;
				second = pr.second;
			}
			return *this;
		}
		first_type	first;
		second_type	second;
	}; // struct pair

	template <class T1, class T2>
  bool operator== (const pair<T1,T2>& lhs, const pair<T1,T2>& rhs) {
		return lhs.first == rhs.first && lhs.second == rhs.second;
	}
	template <class T1, class T2>
  bool operator!= (const pair<T1,T2>& lhs, const pair<T1,T2>& rhs) {
		return !(lhs == rhs);
	}
	template <class T1, class T2>
  bool operator<  (const pair<T1,T2>& lhs, const pair<T1,T2>& rhs) {
		return lhs.first < rhs.first || (!(rhs.first < lhs.first) && lhs.second < rhs.second);
	}
	template <class T1, class T2>
  bool operator<= (const pair<T1,T2>& lhs, const pair<T1,T2>& rhs) {
		return !(rhs < lhs);
	}
	template <class T1, class T2>
  bool operator>  (const pair<T1,T2>& lhs, const pair<T1,T2>& rhs) {
		return rhs < lhs;
	}
	template <class T1, class T2>
  bool operator>= (const pair<T1,T2>& lhs, const pair<T1,T2>& rhs) {
		return !(lhs < rhs);
	}

	template <class T1, class T2>
  ft::pair<T1, T2> make_pair (T1 x, T2 y) {
		return ft::pair<T1, T2>(x, y);
	}

	template <typename T>
	void swap(T& a, T& b) {
		T tmp(a);
		a = b;
		b = tmp;
	}

	template<class InputIterator>
	typename ft::iterator_traits<InputIterator>::difference_type
		ft_distance (InputIterator first, InputIterator last, ft::random_access_iterator_tag)
	{return (last - first);}

	template<class InputIterator>
	typename ft::iterator_traits<InputIterator>::difference_type
		ft_distance (InputIterator first, InputIterator last, ft::input_iterator_tag) {
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
		return ft_distance(first, last, typename traits::iterator_category());
	}

	template <class InputIterator1, class InputIterator2>
  bool equal (InputIterator1 first1, InputIterator1 last1, InputIterator2 first2) {
		while (first1 != last1) {
			if (*first1 != *first2)
				return (false);
			first1++;
			first2++;
		}
		return (true);
	}

	template <class InputIterator1, class InputIterator2, class BinaryPredicate>
  bool equal (InputIterator1 first1, InputIterator1 last1, InputIterator2 first2, BinaryPredicate pred) {
		while (first1 != last1) {
			if (!pred(*first1, *first2))
				return (false);
			first1++;
			first2++;
		}
		return (true);
	}

	template <class InputIterator1, class InputIterator2>
  bool lexicographical_compare (InputIterator1 first1, InputIterator1 last1, InputIterator2 first2, InputIterator2 last2) {
		while (first1 != last1) {
			if (first2 == last2 || *first1 > *first2)
				return (false);
			else if (*first1 < *first2)
				return (true);
			first1++;
			first2++;
		}
		return (first2 != last2);
	}

	template <class InputIterator1, class InputIterator2, class Compare>
  bool lexicographical_compare (InputIterator1 first1, InputIterator1 last1, InputIterator2 first2, InputIterator2 last2, Compare comp) {
		while (first1 != last1) {
			if (first2 == last2 || comp(*first2, *first1))
				return (false);
			else if (comp(*first1, *first2))
				return (true);
			first1++;
			first2++;
		}
		return (first2 != last2);
	}

	/*
	**	ENABLE_IF
	*/
	template<bool Cond, class T = void> struct enable_if {};
  template<class T> struct enable_if<true, T> { typedef T type; };

	/*
	**	IS_INTEGRAL
	*/
	template <typename T, bool is_integral> struct integral_res {
		typedef T	value_type;
		static const bool value = is_integral;
	};

	template <typename T> struct integral_constant : public integral_res<T, false> {};
	template <> struct integral_constant<bool> : public integral_res<bool, true> {};
	template <> struct integral_constant<char> : public integral_res<char, true> {};
	template <> struct integral_constant<wchar_t> : public integral_res<wchar_t, true> {};
	template <> struct integral_constant<signed char> : public integral_res<signed char, true> {};
	template <> struct integral_constant<short int> : public integral_res<short int, true> {};
	template <> struct integral_constant<int> : public integral_res<int, true> {};
	template <> struct integral_constant<long int> : public integral_res<long int, true> {};
	template <> struct integral_constant<long long int> : public integral_res<long long int, true> {};
	template <> struct integral_constant<unsigned char> : public integral_res<unsigned char, true> {};
	template <> struct integral_constant<unsigned short int> : public integral_res<unsigned short int, true> {};
	template <> struct integral_constant<unsigned int> : public integral_res<unsigned int, true> {};
	template <> struct integral_constant<unsigned long int> : public integral_res<unsigned long int, true> {};
	template <> struct integral_constant<unsigned long long int> : public integral_res<unsigned long long int, true> {};

	template <class T> struct is_integral : public integral_constant<T> {};

} // namespace ft

#endif

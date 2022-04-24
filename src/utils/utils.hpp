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
			first = pr.first;
			second = pr.second;
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

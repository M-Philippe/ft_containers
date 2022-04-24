#ifndef REVERSE_ITERATOR_HPP
# define REVERSE_ITERATOR_HPP

#include "iterator_traits.hpp"

namespace ft {

	template <class Iterator>
	class reverse_iterator {

		public:
			//iterator_type	Iterator	Iterator's type
			typedef Iterator iterator_type;
			//iterator_category	iterator_traits<Iterator>::iterator_category	Preserves Iterator's category
			typedef typename ft::iterator_traits<Iterator>::iterator_category category;
			//value_type	iterator_traits<Iterator>::value_type	Preserves Iterator's value type
			typedef typename ft::iterator_traits<Iterator>::value_type value_type;
			//difference_type	iterator_traits<Iterator>::difference_type	Preserves Iterator's difference type
			typedef typename ft::iterator_traits<Iterator>::difference_type difference_type;
			//pointer	iterator_traits<Iterator>::pointer	Preserves Iterator's pointer type
			typedef typename ft::iterator_traits<Iterator>::pointer pointer;
			//reference	iterator_traits<Iterator>::reference	Preserves Iterator's reference type
			typedef typename ft::iterator_traits<Iterator>::reference reference;

			private:
				iterator_type	_base;

			public:

				/*
				**	CONSTRUCTOR
				*/
				reverse_iterator() {_base = NULL; }
				explicit reverse_iterator(iterator_type it) { _base = --it; }
				template <class Iter> reverse_iterator(const reverse_iterator<Iter>& rev_it) { _base = rev_it.base(); _base--; }
				~reverse_iterator() {};

				iterator_type base() const { return ++(iterator_type(_base)); }

				reference operator*() const { return *_base; }

				reverse_iterator operator+ (difference_type n) const {
					iterator_type newIterator(_base);
					return (reverse_iterator(newIterator - (n - 1)));
				}

				// pre-increment
				reverse_iterator& operator++() {
					_base--;
					return (*this);
				}
				// post-increment
				reverse_iterator  operator++(int) {
					reverse_iterator tmp(*this);
					--(this->_base);
					return (tmp);
				}

				// Only for random_access_iterator
				reverse_iterator& operator+= (difference_type n) {
					_base -= n;
					return (*this);
				}

				reverse_iterator operator-(difference_type n) const {
					reverse_iterator ret(*this);
					ret._base += n;
					return (ret);
				}

				// pre
				reverse_iterator& operator--() {
					_base++;
					return (*this);
				}
				// post
				reverse_iterator  operator--(int) {
					reverse_iterator ret(*this);
					++(this->_base);
					return (ret);
				}

				reverse_iterator& operator-= (difference_type n) {
					_base += n;
					return (*this);
				}

				pointer operator->() const { return (&(_base.operator*())); }

				reference operator[] (difference_type n) const {
					return (base()[-n - 1]);
				}

				template <class I>
					friend bool operator== (const reverse_iterator<I>& lhs, const reverse_iterator<I>& rhs);
				template <class I>
					friend bool operator!= (const reverse_iterator<I>& lhs, const reverse_iterator<I>& rhs);
				template <class I>
					friend bool operator< (const reverse_iterator<I>& lhs, const reverse_iterator<I>& rhs);
				template <class I>
					friend bool operator<= (const reverse_iterator<I>& lhs, const reverse_iterator<I>& rhs);
				template <class I>
					friend bool operator> (const reverse_iterator<I>& lhs, const reverse_iterator<I>& rhs);
				template <class I>
					friend bool operator>= (const reverse_iterator<I>& lhs, const reverse_iterator<I>& rhs);

				template <class I>
  			friend reverse_iterator<I>
					operator+ (typename reverse_iterator<I>::difference_type n,
            const reverse_iterator<I>& rev_it);

				template <class I>
  			friend typename reverse_iterator<I>::difference_type
				operator- (const reverse_iterator<I>& lhs, const reverse_iterator<I>& rhs);
	}; // reverse_iterator

	template <class I>
		bool operator== (const reverse_iterator<I>& lhs, const reverse_iterator<I>& rhs) { return (lhs._base == rhs._base); }
	template <class I>
		bool operator!= (const reverse_iterator<I>& lhs, const reverse_iterator<I>& rhs) { return !(lhs._base == rhs._base); }
	template <class I>
		bool operator< (const reverse_iterator<I>& lhs, const reverse_iterator<I>& rhs) { return (lhs._base > rhs._base); }
	template <class I>
		bool operator<= (const reverse_iterator<I>& lhs, const reverse_iterator<I>& rhs) { return (lhs._base >= rhs._base); }
	template <class I>
		bool operator> (const reverse_iterator<I>& lhs, const reverse_iterator<I>& rhs) { return (lhs._base < rhs._base); }
	template <class I>
		bool operator>= (const reverse_iterator<I>& lhs, const reverse_iterator<I>& rhs) { return (lhs._base <= rhs._base); }

	template <class I>
	reverse_iterator<I> operator+(typename reverse_iterator<I>::difference_type n, const reverse_iterator<I>& rev_it) {
		return (reverse_iterator<I>(rev_it + n));
	}

	template <class Iterator>
	typename reverse_iterator<Iterator>::difference_type
	operator- (const reverse_iterator<Iterator>& lhs, const reverse_iterator<Iterator>& rhs) {
		return (rhs.base() - lhs.base());
	}

	template<class IterL, class IterR>
	bool operator==(reverse_iterator<IterL> const &lhs, reverse_iterator<IterR> const &rhs)
	{ return lhs.base() == rhs.base(); }

	template<class IterL, class IterR>
	bool operator<(reverse_iterator<IterL> const &lhs, reverse_iterator<IterR> const &rhs)
	{ return lhs.base() > rhs.base(); }

	template<class IterL, class IterR>
	bool operator<=(reverse_iterator<IterL> const &lhs, reverse_iterator<IterR> const &rhs)
	{ return lhs.base() >= rhs.base(); }

	template<class IterL, class IterR>
	bool operator!=(reverse_iterator<IterL> const &lhs, reverse_iterator<IterR> const &rhs)
	{ return lhs.base() != rhs.base(); }

	template<class IterL, class IterR>
	bool operator>(reverse_iterator<IterL> const &lhs, reverse_iterator<IterR> const &rhs)
	{ return lhs.base() < rhs.base(); }

	template<class IterL, class IterR>
	bool operator>=(reverse_iterator<IterL> const &lhs, reverse_iterator<IterR> const &rhs)
	{ return lhs.base() <= rhs.base(); }


	// Substract of const or non const reverse_iterator
	template<class IteratorL, class IteratorR>
	typename reverse_iterator<IteratorL>::difference_type
	operator-(reverse_iterator<IteratorL> const &lhs, reverse_iterator<IteratorR> const &rhs)
	{ return rhs.base() - lhs.base(); }

	// [ operators+ for pre addition ex : 5 + rit]
	//template<class Iterator>
	//reverse_iterator<Iterator>
	//operator+(typename reverse_iterator<Iterator>::difference_type n, reverse_iterator<Iterator> const &i)
	//{ return reverse_iterator<Iterator>(i.base() - n); }

}; // namespace ft

#endif

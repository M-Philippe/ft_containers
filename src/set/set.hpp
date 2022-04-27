#ifndef SET_HPP
# define SET_HPP

#include <functional>
#include "../utils/bst_red_black.hpp"
#include <cstddef>

namespace ft {

	template < class T, class Compare = std::less<T>, class Alloc = std::allocator<T> >
	class set {

		public:

			typedef T	key_type;
			typedef T value_type;
			typedef Compare key_compare;
			typedef Compare	value_compare;
			typedef Alloc	allocator_type;
			typedef typename allocator_type::reference reference;
			typedef typename allocator_type::const_reference const_reference;
			typedef typename allocator_type::pointer pointer;
			typedef typename allocator_type::const_pointer const_pointer;
			typedef typename ft::bst_red_black<const value_type, Compare, Alloc, false>::iterator iterator;
			typedef typename ft::bst_red_black<const value_type, Compare, Alloc, false>::const_iterator const_iterator;
			typedef typename ft::bst_red_black<const value_type, Compare, Alloc, false>::reverse_iterator 		reverse_iterator;
			typedef typename ft::bst_red_black<const value_type, Compare, Alloc, false>::const_reverse_iterator 	const_reverse_iterator;
			typedef ptrdiff_t difference_type;
			typedef size_t size_type;

			explicit set (const key_compare& comp = key_compare(), const allocator_type& alloc = allocator_type()) {
				(void)comp;
				(void)alloc;
			}

			template <class InputIterator>
  		set (InputIterator first, InputIterator last, const key_compare& comp = key_compare(), const allocator_type& alloc = allocator_type()) {
				(void)comp;
				(void)alloc;
				bst.insert(first, last);
			}

			set(const set& x) {
				bst.insert(x.begin(), x.end());
			}

			~set() {};

			set& operator=(const set& x) {
				if (this == &x)
					return *this;
				bst = x.bst;
				return *this;
			}

			/*
			**		ITERATORS
			*/
			iterator 				begin() { return bst.begin(); }
			iterator 				end() 	{ return bst.end(); }
			reverse_iterator		rbegin(){ return bst.rbegin(); }
			reverse_iterator		rend() 	{ return bst.rend(); }

			const_iterator 			begin()	 const	{ return bst.begin(); }
			const_iterator 			end()    const	{ return bst.end(); }
			const_reverse_iterator	rbegin() const	{ return bst.rbegin(); }
			const_reverse_iterator	rend()	 const	{ return bst.rend(); }

			/*
			**		CAPACITY
			*/
			size_type	size() const { return bst.size(); }
			bool		empty() const { return bst.size() == 0; }
			size_type	max_size() const { return bst.max_size(); }

			/*
			**		MODIFIERS
			*/
			pair<iterator, bool>	insert(const value_type& val) { return bst.insert(val); }
			iterator				insert(iterator position, const value_type& k) { return bst.insert(position, k); }
			template <class InputIterator>
			void	insert(InputIterator first, InputIterator last) { bst.insert(first, last); }

			void 					erase(iterator first) { bst.erase(first); }
			void 					erase(iterator first, iterator last) { bst.erase(first, last); }
			size_type 				erase(const key_type& k) { return bst.erase(k); }

			void swap (set& x) { bst.swap(x.bst); }
			void clear() {
				if (bst.size() != 0)
					bst.clear();
			}

			/*
			**		OBSERVERS
			*/
			key_compare key_comp() const { return key_compare(); }
			value_compare value_comp() const { return value_compare(); }

			/*
			**		OPERATIONS
			*/
			iterator find (const key_type& k) { return bst.find(k); }
			const_iterator find (const key_type& k) const { return bst.find(k); }
			size_type	count(const key_type& k) const { return bst.count(k); }
			iterator lower_bound (const key_type& k) { return bst.lower_bound(k); }
			const_iterator lower_bound (const key_type& k) const { return bst.lower_bound(k); }
			iterator upper_bound (const key_type& k) { return bst.upper_bound(k); }
			const_iterator upper_bound (const key_type& k) const { return bst.upper_bound(k); }
			ft::pair<iterator,iterator>             equal_range (const key_type& k) { return bst.equal_range(k); }
			ft::pair<const_iterator,const_iterator> equal_range (const key_type& k) const { return bst.equal_range(k); }

			/*
			**		ALLOCATOR
			*/
			allocator_type get_allocator() const { return allocator_type(); }

			/*
			**		RELATIONAL OPERATORS
			*/
			template <class Te, class C, class A> friend bool operator== ( const set<Te,C,A>& lhs, const set<Te,C,A>& rhs);
			template <class Te, class C, class A> friend bool operator!= ( const set<Te,C,A>& lhs, const set<Te,C,A>& rhs);
			template <class Te, class C, class A> friend bool operator<  ( const set<Te,C,A>& lhs, const set<Te,C,A>& rhs);
			template <class Te, class C, class A> friend bool operator<= ( const set<Te, C, A>& lhs, const set<Te, C, A>& rhs );
			template <class Te, class C, class A> friend bool operator>  ( const set<Te,C,A>& lhs, const set<Te,C,A>& rhs );
			template <class Te, class C, class A> friend bool operator>= ( const set<Te,C,A>& lhs, const set<Te,C,A>& rhs );

			template <class Te, class C, class A>
  			void swap (set<Te, C, A>& x, set<Te, C, A>& y);

		private:
			ft::bst_red_black<const value_type, Compare, Alloc, false> bst;

	};

		template <class T, class Compare, class Alloc>
	bool operator==( const set<T,Compare,Alloc>& lhs, const set<T,Compare,Alloc>& rhs) {
		return lhs.size() == rhs.size() && ft::equal(lhs.begin(), lhs.end(), rhs.begin());
	}
	template <class Te, class C, class A>
	bool operator!=( const set<Te,C,A>& lhs, const set<Te,C,A>& rhs) {
		return !(lhs == rhs);
	}
	template <class Te, class C, class A>
	bool operator<( const set<Te,C,A>& lhs, const set<Te,C,A>& rhs) {
		return ft::lexicographical_compare(lhs.begin(), lhs.end(), rhs.begin(), rhs.end());
	}
	template <class Te, class C, class A>
	bool operator<= ( const set<Te, C, A>& lhs, const set<Te, C, A>& rhs ) {
		return !(rhs < lhs);
	}
	template <class Te, class C, class A>
	bool operator>  ( const set<Te,C,A>& lhs, const set<Te,C,A>& rhs ) {
		return rhs < lhs;
	}
	template <class Te, class C, class A>
	bool operator>= ( const set<Te,C,A>& lhs, const set<Te,C,A>& rhs ) {
		return !(lhs < rhs);
	}

	template <class Te, class C, class A>
  void swap (set<Te, C, A>& x, set<Te, C, A>& y) {
		x.swap(y);
	}

}; // namespace ft

#endif

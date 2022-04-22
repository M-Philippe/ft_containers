#ifndef MAP_HPP
# define MAP_HPP

#include <functional>
#include <cstddef> // ptrdiff_t
#include "../iterator/bst_rb_iterator.hpp"
#include "../utils/utils.hpp"
#include "../utils/bst_red_black.hpp"

namespace ft {

	template < class Key /* map::key_type */, class T /* map::mapped_type */, class Compare = std::less<Key> /* map::key_compare */, class Alloc = std::allocator<pair<const Key,T> /* map::allocator_type */> >
	class map {

	public:

		typedef Key										key_type;
		typedef T										mapped_type;
		typedef Compare									key_compare;
		typedef Alloc									allocator_type;
		typedef ptrdiff_t 								difference_type;
		typedef size_t 									size_type;
		typedef ft::pair<const key_type, mapped_type>	value_type;

		typedef typename allocator_type::pointer 												pointer;
		typedef typename allocator_type::reference 												reference;
		typedef typename allocator_type::const_reference 										const_reference;
		typedef typename allocator_type::const_pointer 											const_pointer;
		typedef typename ft::bst_red_black<value_type, Compare, Alloc>::iterator 				iterator;
		typedef typename ft::bst_red_black<value_type, Compare, Alloc>::const_iterator 			const_iterator;
		typedef typename ft::bst_red_black<value_type, Compare, Alloc>::reverse_iterator 		reverse_iterator;
		typedef typename ft::bst_red_black<value_type, Compare, Alloc>::const_reverse_iterator 	const_reverse_iterator;


	public:

		explicit map(const key_compare& comp = key_compare(), const allocator_type& alloc = allocator_type()) {
			(void)comp;
			(void)alloc;
		}

		template <class InputIterator>
  		map (InputIterator first, InputIterator last, const key_compare& comp = key_compare(), const allocator_type& alloc = allocator_type()) {
			(void)comp;
			(void)alloc;
			bst.insert(first, last);
		}

		map (const map& x) {
			bst.insert(x.begin(), x.end());
		}

		~map() {}

		map& operator=(const map& x) {
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
		size_type	size()		const { return bst.size(); }
		size_type	max_size() 	const { return bst.max_size(); }
		bool		empty()		const { return bst.size() == 0; }

		/*
		**		ELEMENT ACCESS
		*/
		mapped_type& operator[] (const key_type& k) {
			ft::pair<key_type, mapped_type> pairToInsert;
			pairToInsert.first = k;
			return bst.insert(pairToInsert).first->second;
		}

		/*
		**		MODIFIERS
		*/
		template <class InputIterator>
		void					insert(InputIterator first, InputIterator last) { bst.insert(first, last); }
		pair<iterator, bool>	insert(const value_type& val) { return bst.insert(val); }
		iterator				insert(iterator position, const value_type& k) { return bst.insert(position, k); }

		void 					erase(iterator first) { bst.erase(first); }
		void 					erase(iterator first, iterator last) { bst.erase(first, last); }
		size_type 				erase(const key_type& k) { return bst.erase(k); }

		void 					swap (map& x) { bst.swap(x.bst); }
		void 					clear() { bst.clear();}

		/*
		**		OBSERVERS
		*/
		key_compare key_comp() const { return key_compare(); }

		template <class K, class Te, class C, class A>
		class v_c
		{
		  friend class map;
			protected:
			  C comp;
			  v_c (C c) : comp(c) {}
			public:
			  bool operator() (const value_type& x, const value_type& y) const { return comp(x.first, y.first); }
		}; // map::value_compare
		typedef map<Key, T, Compare, Alloc>::v_c<Key, T, Compare, Alloc> value_compare;
		value_compare	value_comp() const { return value_compare(key_compare()); }

		/*
		**		OPERATIONS
		*/
		iterator 		find (const key_type& k) { return bst.find(k); }
		const_iterator 	find (const key_type& k) const { return bst.find(k); }
		size_type		count(const key_type& k) const { return bst.count(k); }
		iterator 		lower_bound (const key_type& k) { return bst.lower_bound(k); }
		const_iterator 	lower_bound (const key_type& k) const { return bst.lower_bound(k); }
		iterator 		upper_bound (const key_type& k) { return bst.upper_bound(k); }
		const_iterator 	upper_bound (const key_type& k) const { return bst.upper_bound(k); }
		pair<const_iterator,const_iterator> equal_range (const key_type& k) const { return equal_range(k); }
		pair<iterator,iterator>             equal_range (const key_type& k) { return equal_range(k); }

		/*
		**		ALLOCATOR
		*/
		allocator_type get_allocator() const { return allocator_type(); }

		/*
		**		RELATIONAL OPERATORS
		*/
		template <class K, class Te, class C, class A> friend bool operator==( const map<K,Te,C,A>& lhs, const map<K,Te,C,A>& rhs);
		template <class K, class Te, class C, class A> friend bool operator!=( const map<K,Te,C,A>& lhs, const map<K,Te,C,A>& rhs);
		template <class K, class Te, class C, class A> friend bool operator<( const map<K,Te,C,A>& lhs, const map<K,Te,C,A>& rhs);
		template <class K, class Te, class C, class A> friend bool operator<= ( const map<K, Te, C, A>& lhs, const map<K, Te, C, A>& rhs );
		template <class K, class Te, class C, class A> friend bool operator>  ( const map<K,Te,C,A>& lhs, const map<K,Te,C,A>& rhs );
		template <class K, class Te, class C, class A> friend bool operator>= ( const map<K,Te,C,A>& lhs, const map<K,Te,C,A>& rhs );

		template <class K, class Te, class C, class A>
  		void swap (map<K, Te, C, A>& x, map<K, Te, C, A>& y);

		/*     To Delete     */
		void print() { bst.print(); }

		private:
			bst_red_black<value_type, Compare, Alloc> bst;

	}; // class map

	template <class Key, class T, class Compare, class Alloc>
	bool operator==( const map<Key,T,Compare,Alloc>& lhs, const map<Key,T,Compare,Alloc>& rhs) {
		return lhs.size() == rhs.size() && ft::equal(lhs.begin(), lhs.end(), rhs.begin());
	}
	template <class K, class Te, class C, class A>
	bool operator!=( const map<K,Te,C,A>& lhs, const map<K,Te,C,A>& rhs) {
		return !(lhs == rhs);
	}
	template <class K, class Te, class C, class A>
	bool operator<( const map<K,Te,C,A>& lhs, const map<K,Te,C,A>& rhs) {
		return ft::lexicographical_compare(lhs.begin(), lhs.end(), rhs.begin(), rhs.end());
	}
	template <class K, class Te, class C, class A>
	bool operator<= ( const map<K, Te, C, A>& lhs, const map<K, Te, C, A>& rhs ) {
		return !(rhs < lhs);
	}
	template <class K, class Te, class C, class A>
	bool operator>  ( const map<K,Te,C,A>& lhs, const map<K,Te,C,A>& rhs ) {
		return rhs < lhs;
	}
	template <class K, class Te, class C, class A>
	bool operator>= ( const map<K,Te,C,A>& lhs, const map<K,Te,C,A>& rhs ) {
		return !(lhs < rhs);
	}

	template <class K, class Te, class C, class A>
  void swap (map<K, Te, C, A>& x, map<K, Te, C, A>& y) {
		x.swap(y);
	}

}; // namespace ft

#endif

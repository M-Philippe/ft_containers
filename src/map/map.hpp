#ifndef MAP_HPP
# define MAP_HPP

#include <functional>
#include <cstddef> // ptrdiff_t
#include "map_iterator.hpp"
#include "../utils/utils.hpp"
#include "bst_red_black.hpp"

namespace ft {

	template < class Key /* map::key_type */, class T /* map::mapped_type */, class Compare = std::less<Key> /* map::key_compare */, class Alloc = std::allocator<pair<const Key,T> /* map::allocator_type */> >
	class map {

	public:

		typedef Key	key_type;
		typedef T	mapped_type;
		typedef ft::pair<const key_type, mapped_type>	value_type;
		typedef Compare	key_compare;
		typedef Alloc	allocator_type;
		typedef typename allocator_type::reference reference;
		typedef typename allocator_type::const_reference const_reference;
		typedef typename allocator_type::pointer pointer;
		typedef typename allocator_type::const_pointer const_pointer;
		// iterator	a bidirectional iterator to value_type	convertible to const_iterator
		typedef typename ft::bst_red_black<value_type, Compare, Alloc>::iterator iterator;
		// const_iterator	a bidirectional iterator to const value_type
		// reverse_iterator	reverse_iterator<iterator>
		// const_reverse_iterator	reverse_iterator<const_iterator>
		typedef ptrdiff_t difference_type;
		typedef size_t size_type;

	public:

		map(const key_compare& comp = key_compare(), const allocator_type& alloc = allocator_type()) {
			(void)comp;
			(void)alloc;
		}

		~map() {}

		iterator begin() { return bst.begin(); }
		iterator end() { return bst.end(); }
		// true if created elements or false if already existing elements.
		bool insert (const value_type& val) { return bst.insert(val); }
		void print() { bst.print(); }
		size_type size() const { return bst.size(); }

	private:
		bst_red_black<value_type, Compare, Alloc> bst;

	}; // class map

}; // namespace ft

#endif

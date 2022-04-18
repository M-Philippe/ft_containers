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
		typedef typename ft::bst_red_black<value_type, Compare, Alloc>::iterator iterator;
		typedef typename ft::bst_red_black<value_type, Compare, Alloc>::const_iterator const_iterator;
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

		/*
		**		ITERATORS
		*/
		iterator 		begin() { return bst.begin(); }
		const_iterator 	begin() const { return bst.begin(); }
		iterator 		end() { return bst.end(); }
		const_iterator 	end() const { return bst.end(); }

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

		/*
		**		OPERATIONS
		*/
		iterator find (const key_type& k) { return bst.find(k); }
		const_iterator find (const key_type& k) const { return bst.find(k); }
		size_type	count(const key_type& k) const { return bst.count(k); }
		pair<const_iterator,const_iterator> equal_range (const key_type& k) const { return equal_range(k); }
		pair<iterator,iterator>             equal_range (const key_type& k) { return equal_range(k); }


		/*     To Delete     */
		void print() { bst.print(); }

	private:
		bst_red_black<value_type, Compare, Alloc> bst;

	}; // class map

}; // namespace ft

#endif

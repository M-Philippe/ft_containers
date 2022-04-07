#ifndef MAP_HPP
# define MAP_HPP

#include <functional>
#include <cstddef> // ptrdiff_t
#include <iostream> // std::cout && std::endl

#include "map_iterator.hpp"
#include "../utils/utils.hpp"

#include <stdlib.h> // tmp exit.

#include "bst_red_black.hpp"

namespace ft {

	template < class Key /* map::key_type */, class T /* map::mapped_type */, class Compare = std::less<Key> /* map::key_compare */, class Alloc = std::allocator<pair<const Key,T> /* map::allocator_type */> >
	class map {

	private:
		struct map_node;

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
		//typedef typename ft::map_iterator<T, node_pointer> iterator;
		// iterator	a bidirectional iterator to value_type	convertible to const_iterator
		// const_iterator	a bidirectional iterator to const value_type
		// reverse_iterator	reverse_iterator<iterator>
		// const_reverse_iterator	reverse_iterator<const_iterator>
		typedef ptrdiff_t difference_type;
		typedef size_t size_type;

	private:

		typedef struct map_node {
			map_node* leftChild;
			map_node*	rightChild;
			map_node*	parent;
			bool	black;
			pointer data;
		} node;

		typedef typename Alloc::template rebind<node>::other allocator_node;
		typedef typename allocator_node::pointer node_pointer;

	public:
		//typedef typename ft::map_iterator<T, Key, node_pointer> iterator;
		typedef typename ft::bst_red_black<ft::pair<Key, T>, Compare, Alloc>::iterator iterator;


	public:

		map(const key_compare& comp = key_compare(), const allocator_type& alloc = allocator_type()) {
			_compare = comp;
			_alloc = alloc;
			_head = NULL;
			_alloc_node = allocator_node();
			_size = 0;
		}

		~map() {}

		iterator begin() { return bst.begin(); }
		iterator end() { return bst.end(); }

		// true if created elements or false if already existing elements.
		bool insert (const value_type& val) {
			return bst.insert(val);
		}

		void	printNode(node_pointer node) {
			if (node == NULL)
				return;
			printNodeAndChild(node);
			node_pointer tmp = node;
			node = node->leftChild;
			std::cout << "GOING LEFT" << std::endl;
			while (node != NULL) {
				printNodeAndChild(node);
				node = node->leftChild;
			}
			std::cout << "GOING RIGHT" << std::endl;
			tmp = tmp->rightChild;
			while (tmp != NULL) {
				printNodeAndChild(tmp);
				tmp = tmp->rightChild;
			}
		}

		void	printX(node_pointer node) {
			if (node == NULL)
				return;
			printNodeAndChild(node);
			printX(node->leftChild);
			printX(node->rightChild);
		}

		void	print() {
			node* node = _head;
			std::cout << "STARTING BY HEAD: " << std::endl;
			printNodeAndChild(node);
			printX(node->leftChild);
			printX(node->rightChild);
		}

		size_type size() const { return _size; }

	private:

		node_pointer	_head;
		allocator_type _alloc;
		key_compare _compare;
		allocator_node _alloc_node;
		size_type _size;

		// TMP
		bst_red_black<ft::pair<Key, T>, Compare, Alloc> bst;

	}; // class map

}; // namespace ft

#endif

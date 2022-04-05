#ifndef MAP_HPP
# define MAP_HPP

#include <functional>
#include <cstddef> // ptrdiff_t
#include <iostream> // std::cout && std::endl

#include "map_iterator.hpp"
#include "../utils/utils.hpp"

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
		typedef typename ft::map_iterator<T, Key, node_pointer> iterator;


	public:

		map(const key_compare& comp = key_compare(), const allocator_type& alloc = allocator_type()) {
			_compare = comp;
			_alloc = alloc;
			_head = NULL;
			_alloc_node = allocator_node();
			_size = 0;
		}

		void	recursive_deletion(node_pointer node) {
			if (!node)
				return;
			recursive_deletion(node->leftChild);
			recursive_deletion(node->rightChild);
			_alloc.destroy(node->data);
			_alloc.deallocate(node->data, 1);
			_alloc_node.deallocate(node, 1);
		}

		~map() {
			recursive_deletion(_head->leftChild);
			recursive_deletion(_head->rightChild);
			_alloc.destroy(_head->data);
			_alloc.deallocate(_head->data, 1);
			_alloc_node.deallocate(_head, 1);
		}

		iterator begin() {
			return iterator(_head);
		}

		iterator end() {
			return iterator(_head, true);
		}

		/*
			Process:
				- classic insert.
				-	check rules / fix tree.
		*/

		node_pointer getUncleNode(node_pointer node) {
			if (node->parent == NULL || node->parent->parent == NULL)
				return NULL;
			node_pointer parentNode = node->parent;
			node_pointer grandParentNode = parentNode->parent;
			if (parentNode->data->first < grandParentNode->data->first)
				return grandParentNode->rightChild;
			else
				return grandParentNode->leftChild;
		}

		bool isNodeBlack(node_pointer node) {
			if (node == NULL || node->black == true)
				return true;
			else
				return false;
		}

		bool isInnerGrandchild(node_pointer node, node_pointer parent, node_pointer grandparent) {
			if (parent->data->first < grandparent->data->first && parent->data->first < node->data->first)
				return true;
			else if (parent->data->first > grandparent->data->first && parent->data->first > node->data->first)
				return true;
			return false;
		}

		void	rotateAroundGrandparent(node_pointer node, node_pointer parent, node_pointer grandparent) {
			(void)parent;
			if (grandparent->parent == NULL)
				_head = node;
			else if (grandparent->parent->leftChild == grandparent) {
				grandparent->parent->leftChild = node;
			} else
				grandparent->parent->rightChild = node;
			if (node->data->first < grandparent->data->first) {
				node->rightChild = grandparent;
				grandparent->leftChild = NULL;
			}
			else {
				node->leftChild = grandparent;
				grandparent->rightChild = NULL;
			}
			grandparent->parent = node;
			grandparent->black = false;
			node->black = true;
		}

		void	printNodeAndChild(node_pointer node) {
			std::cout << "NODE: " << node->data->first << (node->black == true ? " | black" : " | white") << std::endl;
			if (node->leftChild != NULL)
					std::cout << "\t\tLEFT_CHILD: " << node->leftChild->data->first << (node->leftChild->black == true ? " | black" : " | white") << std::endl;
			else
					std::cout << "\t\tLEFT_CHILD: NULL" << std::endl;
			if (node->rightChild != NULL)
					std::cout << "\t\tRIGHT_CHILD: " << node->rightChild->data->first << (node->rightChild->black == true ? " | black" : " | white") << std::endl;
			else
					std::cout << "\t\tRIGHT_CHILD: NULL" << std::endl;
		}

		void	rotateAroundParent(node_pointer node, node_pointer parent, node_pointer grandparent) {
			if (node->data->first < parent->data->first) {
				if (grandparent->leftChild == parent) {
					grandparent->leftChild = node;
					node->parent = grandparent;
					parent->parent = node;
					node->rightChild = parent;
				} else {
					grandparent->rightChild = node;
					node->parent = grandparent;
					parent->parent = node;
					node->rightChild = parent;
				}
				parent->leftChild = NULL;
			} else if (node->data->first > parent->data->first) {
					// Bug in ths if;else ?
					if (grandparent->leftChild == parent)
						grandparent->leftChild = node;
					else
						grandparent->rightChild = node;
					node->parent = grandparent;
					parent->parent = node;
					node->leftChild = parent;
					parent->rightChild = NULL;
			}
			rotateAroundGrandparent(node, parent, grandparent);
		}

		/*
			Case 1: Parent and uncle nodes are red
			Case 2: Parent node is red, uncle node is black, inserted node is "inner grandchild"
			Case 3: Parent node is red, uncle node is black, inserted node is "outer grandchild"
		*/
		void	fixTreeProperties(node_pointer node) {
			node_pointer uncle = getUncleNode(node);
			if (node->parent->black == false && !isNodeBlack(uncle)) { /* case 1 */
				node->parent->black = true;
				uncle->black = true;
				if (node->parent->parent != _head)
					node->parent->parent->black = false;
				fixTreeProperties(node->parent->parent);
			} else if (node->parent->black == false && isNodeBlack(uncle) && isInnerGrandchild(node, node->parent, node->parent->parent)) { /* case 2 */
				// rotate around parent, rotate around grandparent and recolor.
				rotateAroundParent(node, node->parent, node->parent->parent);
			}
		}

		bool	insert_in_tree(node_pointer current, const value_type& val) {
			if (current->leftChild == NULL && val.first < current->data->first) {
				node_pointer nodeAdded = _alloc_node.allocate(1);
				nodeAdded->data = _alloc.allocate(1);
				_alloc.construct(nodeAdded->data, val);
				nodeAdded->leftChild = NULL;
				nodeAdded->rightChild = NULL;
				nodeAdded->black = false;
				nodeAdded->parent = current;
				current->leftChild = nodeAdded;
				_size++;
				if (current->black == false)
					fixTreeProperties(nodeAdded);
				return true;
			} else if (current->rightChild == NULL && val.first > current->data->first) {
				node_pointer nodeAdded = _alloc_node.allocate(1);
				nodeAdded->data = _alloc.allocate(1);
				_alloc.construct(nodeAdded->data, val);
				nodeAdded->leftChild = NULL;
				nodeAdded->rightChild = NULL;
				nodeAdded->black = false;
				nodeAdded->parent = current;
				current->rightChild = nodeAdded;
				_size++;
				if (current->black == false)
					fixTreeProperties(nodeAdded);
				return true;
			}
			else {
				if (val.first == current->data->first)
					return false;
				else if (val.first < current->data->first)
					return insert_in_tree(current->leftChild, val);
				else if (val.first > current->data->first)
					return insert_in_tree(current->rightChild, val);
			}
			return false;
		}

		// true if created elements or false if already existing elements.
		bool insert (const value_type& val) {
			if (!_head) {
				_head = _alloc_node.allocate(1);
				value_type t = val;
				_head->leftChild = NULL;
				_head->rightChild = NULL;
				_head->parent = NULL;
				_head->black = true;
				_head->data = _alloc.allocate(1);
				_alloc.construct(_head->data, val);
				_size++;
				return (true);
			}
			node_pointer current = _head;
			return insert_in_tree(current, val);
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

		void	print() {
			node* node = _head;
			printNode(node);
		}

		size_type size() const { return _size; }

	private:

		node_pointer	_head;
		allocator_type _alloc;
		key_compare _compare;
		allocator_node _alloc_node;
		size_type _size;

	}; // class map

}; // namespace ft

#endif

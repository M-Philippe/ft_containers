#ifndef BST_RED_BLACK_HPP
# define BST_RED_BLACK_HPP

#include "map_iterator.hpp"

#include <iostream> // tmp (std::cout, std::endl)

namespace ft {

	template <typename T, class Compare, class Alloc>
	class bst_red_black {

		private:

			typedef T	value_type;
			typedef Alloc allocator_type;
			typedef typename allocator_type::pointer pointer;
			typedef typename allocator_type::reference reference;
			typedef Compare data_compare;
			typedef size_t size_type;

			typedef struct map_node {
				T data;
				map_node* leftChild;
				map_node*	rightChild;
				map_node*	parent;
				bool	black;
				map_node(const T& newData = T()) : data(newData), leftChild(NULL), rightChild(NULL), parent(NULL), black(false) {}
			} node;

		typedef typename Alloc::template rebind<node>::other allocator_node;
		typedef typename allocator_node::pointer node_pointer;

		public:

			typedef typename ft::map_iterator<node_pointer, T, Compare> iterator;
			typedef typename ft::map_iterator<node_pointer, const T, Compare> const_iterator;

			iterator begin() { return iterator(_head); }
			const_iterator begin() const { return const_iterator(_head); }
			iterator end() { return iterator(_head, true); }
			const_iterator end() const { return const_iterator(_head, true); }

			bst_red_black(const data_compare& comp = data_compare(), const allocator_type& alloc = allocator_type()) {
				_data_allocator = alloc;
				_node_allocator = allocator_node();
				_comp = comp;
				_head = NULL;
				_size = 0;
			}

			node_pointer new_node(const T& newData = T()) {
				node_pointer node = _node_allocator.allocate(1);
				_node_allocator.construct(node, newData);
				return node;
			}

			~bst_red_black() {
				if (!_head)
					return;
				if (_head->leftChild)
					recursive_deletion(_head->leftChild);
				if (_head->rightChild)
					recursive_deletion(_head->rightChild);
				_node_allocator.destroy(_head);
				_node_allocator.deallocate(_head, 1);
				_size--;
			}

			// true if created elements or false if already existing elements.
			bool insert (const value_type& val) {
				if (!_head) {
					_head = new_node(val);
					_head->black = true;
					_size++;
					return true;
				}
				node_pointer current = _head;
				return insert_in_tree(current, val);
			}

			void	print() {
				node* node = _head;
				std::cout << "STARTING BY HEAD: " << std::endl;
				printNodeAndChild(node);
				printX(node->leftChild);
				printX(node->rightChild);
			}

		private:

		node_pointer getUncleNode(node_pointer node) {
			if (node->parent == NULL || node->parent->parent == NULL)
				return NULL;
			node_pointer parentNode = node->parent;
			node_pointer grandParentNode = parentNode->parent;
			if (parentNode->data.first < grandParentNode->data.first)
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
			if (parent->data.first < grandparent->data.first && parent->data.first < node->data.first)
				return true;
			else if (parent->data.first > grandparent->data.first && parent->data.first > node->data.first)
				return true;
			return false;
		}

		void	rotateAroundGrandparentOuterchild(node_pointer node) {
			// node don't move.
			node_pointer parent = node->parent;
			node_pointer grandparent = node->parent->parent;
			if (grandparent == _head)
				_head = node;
			if (grandparent->parent->data.first < grandparent->data.first) {
				grandparent->parent->rightChild = parent;
			} else
				grandparent->parent->leftChild = parent;
			if (node == parent->leftChild) {
				grandparent->parent = parent;
				parent->rightChild = grandparent;
			} else {
				grandparent->parent = parent;
				parent->leftChild = grandparent;
			}
			grandparent->leftChild = NULL;
			grandparent->rightChild = NULL;
			parent->black = true;
			grandparent->black = false;
		}


		void	rotateAroundGrandparent(node_pointer node, node_pointer parent, node_pointer grandparent) {
			(void)parent;
			if (grandparent->parent == NULL)
				_head = node;
			else if (grandparent->parent->leftChild == grandparent) {
				grandparent->parent->leftChild = node;
			} else
				grandparent->parent->rightChild = node;
			if (node->data.first < grandparent->data.first) {
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
			std::cout << "NODE: " << node->data.first << (node->black == true ? " | black" : " | red") << std::endl;
			if (node->leftChild != NULL)
					std::cout << "\t\tLEFT_CHILD: " << node->leftChild->data.first << (node->leftChild->black == true ? " | black" : " | red") << std::endl;
			else
					std::cout << "\t\tLEFT_CHILD: NULL" << std::endl;
			if (node->rightChild != NULL)
					std::cout << "\t\tRIGHT_CHILD: " << node->rightChild->data.first << (node->rightChild->black == true ? " | black" : " | red") << std::endl;
			else
					std::cout << "\t\tRIGHT_CHILD: NULL" << std::endl;
		}

		void	rotateAroundParent(node_pointer node, node_pointer parent, node_pointer grandparent) {
			if (node->data.first < parent->data.first) {
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
			} else if (node->data.first > parent->data.first) {
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
			Case X: parent and node are red
			Case 1: Parent and uncle nodes are red
			Case 2: Parent node is red, uncle node is black, inserted node is "inner grandchild"
			Case 3: Parent node is red, uncle node is black, inserted node is "outer grandchild"
		*/
		void	fixTreeProperties(node_pointer node) {
			node_pointer uncle = getUncleNode(node);
			if (node == _head && node->black == true)
				return;
			std::cout << "BEFORE SEGV: " << node->data.first << std::endl;
			std::cout << node->parent << std::endl;
			std::cout << node->parent->data.first << std::endl;
			if (node->parent->black == false && !isNodeBlack(uncle)) { /* case 1 */
				node->parent->black = true;
				uncle->black = true;
				if (node->parent->parent != _head)
					node->parent->parent->black = false;
				// original: fixTreeProperties(node->parent->parent);
				fixTreeProperties(node->parent->parent);
			} else if (node->parent->black == false && isNodeBlack(uncle) && isInnerGrandchild(node, node->parent, node->parent->parent)) {
				/* case 2 */
				// rotate around parent, rotate around grandparent and recolor.
				rotateAroundParent(node, node->parent, node->parent->parent);
				//fixTreeProperties(node->parent);
			} else if (node->parent->black == false && isNodeBlack(uncle) && !isInnerGrandchild(node, node->parent, node->parent->parent)) {
				/* case 3 */
				rotateAroundGrandparentOuterchild(node);
				//fixTreeProperties(node->parent);
			}
		}

		bool	insert_in_tree(node_pointer current, const value_type& val) {
			if (current->leftChild == NULL && val.first < current->data.first) {
				node_pointer nodeAdded = new_node(val);
				current->leftChild = nodeAdded;
				nodeAdded->parent = current;
				_size++;
				if (current->black == false)
					fixTreeProperties(nodeAdded);
				return true;
			} else if (current->rightChild == NULL && val.first > current->data.first) {
				node_pointer nodeAdded = new_node(val);
				current->rightChild = nodeAdded;
				nodeAdded->parent = current;
				_size++;
				if (current->black == false)
					fixTreeProperties(nodeAdded);
				return true;
			}
			else {
				if (val.first == current->data.first)
					return false;
				else if (val.first < current->data.first)
					return insert_in_tree(current->leftChild, val);
				else if (val.first > current->data.first)
					return insert_in_tree(current->rightChild, val);
			}
			return false;
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

		void	recursive_deletion(node_pointer node) {
			if (!node)
				return;
			recursive_deletion(node->leftChild);
			recursive_deletion(node->rightChild);
			_node_allocator.destroy(node);
			_node_allocator.deallocate(node, 1);
			_size--;
		}

			allocator_type	_data_allocator;
			allocator_node	_node_allocator;
			data_compare		_comp;
			node_pointer		_head;
			size_type				_size;


	}; // class bst_red_black

}; // namespace ft

#endif
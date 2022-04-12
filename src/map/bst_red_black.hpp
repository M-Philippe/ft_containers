#ifndef BST_RED_BLACK_HPP
# define BST_RED_BLACK_HPP

#include "map_iterator.hpp"

#include <iostream> // tmp (std::cout, std::endl)

namespace ft {

	template <typename T, class Compare, bool instance>
	class bst_red_black_map {};

	template <typename T, class Compare>
	class bst_red_black_map<T, Compare, true> {
		public:
			typedef Compare data_compare;
			bst_red_black_map() { _comp = data_compare(); }
			~bst_red_black_map() {}
			bool comp_binded(T lhs, T rhs) { return _comp(lhs.first, rhs.first); }

		private:
			data_compare _comp;
	};

	template <typename T, class Compare>
	class bst_red_black_map<T, Compare, false> {
		public:
			typedef Compare data_compare;
			bst_red_black_map() { _comp = data_compare(); }
			~bst_red_black_map() {}
			bool comp_binded(T lhs, T rhs) { return _comp(lhs, rhs); }

		private:
			data_compare _comp;
	};

	template <typename T, class Compare, class Alloc, bool instance_of_map = true>
	class bst_red_black : bst_red_black_map<T, Compare, instance_of_map> {

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
				bool	black; // to remove.
				int color; // 0 -> black ; 1 -> red.
				map_node(const T& newData = T()) : data(newData), leftChild(NULL), rightChild(NULL), parent(NULL), black(false), color(1) {}
			} node;

		typedef typename Alloc::template rebind<node>::other allocator_node;
		typedef typename allocator_node::pointer node_pointer;

		public:

			typedef typename ft::map_iterator<node_pointer, T, Compare> iterator;
			typedef typename ft::map_iterator<node_pointer, const T, Compare> const_iterator;

			iterator begin() { return iterator(_begin->parent); }
			const_iterator begin() const { return const_iterator(_begin->parent); }
			iterator end() { return iterator(_end); }
			const_iterator end() const { return const_iterator(_end); }

			bst_red_black(const data_compare& comp = data_compare(), const allocator_type& alloc = allocator_type()) {
				_data_allocator = alloc;
				_node_allocator = allocator_node();
				_comp = comp;
				_head = NULL;
				_size = 0;
				_begin = new_node();
				_end = new_node();
				_begin->parent = _end;
				_end->parent = _begin;
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

			void	print() {
				node* node = _head;
				std::cout << "STARTING BY HEAD: " << std::endl;
				printNodeAndChild(node);
				printX(node->leftChild);
				printX(node->rightChild);
			}

			void add_node(T data) {
				node_pointer newNode = new_node(data);
				unset_bounds();
				if (!_head) {
					_head = newNode;
					_head->black = true;
					_head->color = 0;
					++_size;
				} else {
					recursive_add(_head, newNode);
				}
				set_bounds();
			}

		private:

			node_pointer new_node(const T& newData = T()) {
				node_pointer node = _node_allocator.allocate(1);
				_node_allocator.construct(node, newData);
				return node;
			}

			void recursive_add(node_pointer parent, node_pointer newNode) {
				if (this->comp_binded(parent->data, newNode->data) > 0) {
					if (!parent->rightChild) {
						newNode->parent = parent;
						parent->rightChild = newNode;
						++_size;
					} else {
						recursive_add(parent->rightChild, newNode);
					}
				} else {
					if (!parent->leftChild) {
						newNode->parent = parent;
						parent->leftChild = newNode;
						++_size;
					} else {
						recursive_add(parent->leftChild, newNode);
					}
				}
				fixInsert(newNode);
			}

			void fixInsert(node_pointer node) {
				node_pointer aunt;
				while (node->parent && node->parent->color == 1) {
					if (node->parent == node->parent->parent->rightChild) {
						aunt = node->parent->parent->leftChild;
						if (aunt && aunt->color == 1) {	// Color Flip
							aunt->color = 0;
							node->parent->color = 0;
							node->parent->parent->color = 1;
							node = node->parent->parent;
						} else {
							if (node == node->parent->leftChild) {
								node = node->parent;
								rightRotation(node);
							}
							node->parent->color = 0;
							node->parent->parent->color = 1;
							leftRotation(node->parent->parent);
						}
					} else {
						aunt = node->parent->parent->rightChild;
						if (aunt && aunt->color == 1) {
							aunt->color = 0;
							node->parent->color = 0;
							node->parent->parent->color = 1;
							node = node->parent->parent;
						} else {
							if (node == node->parent->rightChild) {
								node = node->parent;
								leftRotation(node);
							}
							node->parent->color = 0;
							node->parent->parent->color = 1;
							rightRotation(node->parent->parent);
						}
					}
					if (node == _head)
						break;
				}
				_head->color = 0;
			}

			void leftRotation(node_pointer node) {
				node_pointer tmp = node->rightChild;
				node->rightChild = tmp->leftChild;
				if (tmp->leftChild != NULL)
					tmp->leftChild->parent = node;
				tmp->parent = node->parent;
				if (node->parent == NULL)
					_head = tmp;
				else if (node == node->parent->leftChild)
					node->parent->leftChild = tmp;
				else
					node->parent->rightChild = tmp;
				tmp->leftChild = node;
				node->parent = tmp;
			}

			void rightRotation(node_pointer node) {
				node_pointer tmp = node->leftChild;
				node->leftChild = tmp->rightChild;
				if (tmp->rightChild != NULL)
					tmp->rightChild->parent = node;
				tmp->parent = node->parent;
				if (node->parent == NULL)
					_head = tmp;
				else if (node == node->parent->rightChild)
					node->parent->rightChild = tmp;
				else
					node->parent->leftChild = tmp;
				tmp->rightChild = node;
				node->parent = tmp;
			}

			node_pointer get_min(node_pointer node) {
				while (node->leftChild)
					node = node->leftChild;
				//std::cout << "LAST_MIN: " << node->data.first << std::endl;
				return node;
			}

			node_pointer get_max(node_pointer node) {
				while (node->rightChild)
					node = node->rightChild;
				return node;
			}

			void set_bounds() {
				if (_size) {
					_begin->parent = get_min(_head);
					_end->parent = get_max(_head);
					_begin->parent->leftChild = _begin;
					_end->parent->rightChild = _end;
				} else {
					_begin->parent = _end;
					_end->parent = _begin;
				}
			}

			void unset_bounds() {
				if (_begin->parent && _begin->parent != _end)
					_begin->parent->leftChild = NULL;
				if (_end->parent && _end->parent != _begin)
					_end->parent->rightChild = NULL;
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
			node_pointer		_begin;
			node_pointer		_end;
			size_type				_size;


	}; // class bst_red_black

}; // namespace ft

#endif

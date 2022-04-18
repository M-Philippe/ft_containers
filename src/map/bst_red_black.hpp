#ifndef BST_RED_BLACK_HPP
# define BST_RED_BLACK_HPP

#include "map_iterator.hpp"
#include "../utils/utils.hpp"

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
			// template <typename key_type>
			// bool comp_binded(T lhs, key_type rhs) { return _comp(lhs.first, rhs); }
			template <typename key_type>
			bool comp_binded(T lhs, key_type rhs) const { return _comp(lhs.first, rhs); }

			// template <typename key_type>
			// bool equal_binded(T lhs, key_type rhs) { return lhs.first == rhs; }
			template <typename key_type>
			bool equal_binded(T lhs, key_type rhs) const { return lhs.first == rhs; }
			bool equal_binded(T lhs, T rhs) { return lhs.first == rhs.first; }

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
			template <typename key_type>
			bool comp_binded(T lhs, key_type rhs) const { return _comp(lhs, rhs); }

			template <typename key_type>
			bool equal_binded(T lhs, key_type rhs) const { return lhs == rhs; }
			bool equal_binded(T lhs, T rhs) { return lhs == rhs; }

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

			typedef struct	map_node {
				map_node*	leftChild;
				map_node*	rightChild;
				map_node*	parent;
				T 			data;
				int 		color; 			/* 0 -> black ; 1 -> red */

				map_node(const T& newData = T()) : leftChild(NULL), rightChild(NULL), parent(NULL), data(newData),  color(1) {}
			} 				node;

		typedef typename Alloc::template rebind<node>::other allocator_node;
		typedef typename allocator_node::pointer node_pointer;

		public:

			typedef typename ft::map_iterator<node_pointer, T, Compare> iterator;
			typedef typename ft::map_iterator<node_pointer, const T, Compare> const_iterator;

			/*
			**		CONSTRUCTORS / DESTRUCTOR
			*/

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
				clear();
				_node_allocator.destroy(_begin);
				_node_allocator.deallocate(_begin, 1);
				_node_allocator.destroy(_end);
				_node_allocator.deallocate(_end, 1);
			}

			bst_red_black& operator=(const bst_red_black& x) {
				clear();
				_head = NULL;
				insert(x.begin(), x.end());
				return *this;
			}

			/*
			**		ITERATORS
			*/
			iterator 		begin() { return iterator(_begin->parent); }
			iterator 		end() { return iterator(_end); }
			const_iterator 	begin() const { return const_iterator(_begin->parent); }
			const_iterator 	end() const { return const_iterator(_end); }

			/*
			**		CAPACITY
			*/
			size_type	size() const { return _size; }
			size_type max_size() const { return _node_allocator.max_size(); }

			/*
			**		MODIFIERS
			*/
			pair<iterator, bool>  insert(const value_type& val) { return add_node(val); }

			iterator insert(iterator position, const value_type& val) {
				(void) position;
				return add_node(val).first;
			}

			template <class InputIterator>
			void	insert(InputIterator first, InputIterator last) {
				while (first != last)
					add_node(*(first++));
			}

			template <typename key_type>
			size_t erase(const key_type& key) {
				node_pointer node = _head;
				node_pointer toDelete = NULL;

				unset_bounds();
				while (node != NULL) {
					if (this->equal_binded(node->data, key)) {
						toDelete = node;
						break;
					}
					else if (this->comp_binded(node->data, key) > 0)
						node = node->rightChild;
					else
						node = node->leftChild;
				}
				set_bounds();
				if (!toDelete) {
					return 0;
				} else {
					return deleteNode(toDelete);
				}
			}

			void erase(iterator position) {
				if (*position)
					deleteNode(*position);
			}

			void erase (iterator first, iterator  last) {
				if (first == last)
					return;
				for (iterator next = first; first != last; first = next) {
					++next;
					deleteNode(*first);
				}
			}

			void	clear() {
				unset_bounds();
				if (!_head) {
					set_bounds();
					return;
				}
				if (_head->leftChild)
					recursive_deletion(_head->leftChild);
				if (_head->rightChild)
					recursive_deletion(_head->rightChild);
				_node_allocator.destroy(_head);
				_node_allocator.deallocate(_head, 1);
				_head = NULL;
				_size = 0;
				set_bounds();
			}

			/*
			**		OPERATIONS
			*/
			template <typename key_type>
			const_iterator find(const key_type& k) const {
				iterator ret = iterator(_end);
				unset_bounds();
				for (node_pointer node = _head; node != NULL; node = this->comp_binded(node->data, k) > 0 ? node->rightChild : node->leftChild)
					if (this->equal_binded(node->data, k))
						ret = iterator(node);
				set_bounds();
				return ret;
			}

			template <typename key_type>
			iterator find(const key_type& k) {
				iterator ret = iterator(_end);
				unset_bounds();
				for (node_pointer node = _head; node != NULL; node = this->comp_binded(node->data, k) > 0 ? node->rightChild : node->leftChild)
					if (this->equal_binded(node->data, k))
						ret = iterator(node);
				set_bounds();
				return ret;
			}

			template <typename key_type>
			size_type	count(const key_type& key) const {
				return (find(key) == _end) ? 0 : 1;
			}

			template <typename key_type>
			pair<iterator, iterator> equal_range(const key_type& k) {
				pair<iterator, iterator> ret;
				iterator first = find(k);
				iterator second = first;
				if (*first != _end) {
					++second;
					return ret = make_pair(first, second);
				}
				unset_bounds();
				node_pointer y;
				for (node_pointer x = _head; x != NULL; y = x) {
					if (this->comp_binded(x->data, k) > 0)
						x = x->rightChild;
					else
						x = x->leftChild;
				}
				set_bounds();
				first = iterator(y);
				++first;
				second = first;
				return make_pair(first, second);
			}


		/*
		**		TO_DELETE
		*/
		void	print() {
			node* node = _head;
			std::cout << "STARTING BY HEAD: " << std::endl;
			printNodeAndChild(node);
			printX(node->leftChild);
			printX(node->rightChild);
			}

		private:
			allocator_type		_data_allocator;
			allocator_node		_node_allocator;
			data_compare		_comp;
			node_pointer		_head;
			node_pointer		_begin;
			node_pointer		_end;
			size_type			_size;

			/*		Insertion		*/
			node_pointer new_node(const T& newData = T()) {
				node_pointer node = _node_allocator.allocate(1);
				_node_allocator.construct(node, newData);
				return node;
			}

			pair<iterator, bool> add_node(T data) {
				node_pointer newNode = new_node(data);
				pair<iterator, bool> ret;
				ret = ft::make_pair(iterator(newNode), true);
				unset_bounds();
				if (!_head) {
					_head = newNode;
					_head->color = 0;
					++_size;
				} else {
					node_pointer x = _head;
					node_pointer y =  x;
					while (x != NULL) {
						y = x;
						if (this->equal_binded(newNode->data, x->data)) {
							ret.first = iterator(x);
							ret.second = false;
							break;
						}
						if (this->comp_binded(x->data, newNode->data) > 0)
							x = x->rightChild;
						else
							x = x->leftChild;
					}
					if (ret.second) {
						if (this->comp_binded(y->data, newNode->data) > 0)
							y->rightChild = newNode;
						else
							y->leftChild = newNode;
						newNode->parent = y;
						++_size;
						fixInsert(newNode);
					}
				}
				if (!ret.second) {
          _node_allocator.destroy(newNode);
          _node_allocator.deallocate(newNode, 1);
				}
				set_bounds();
				return ret;
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

			/*		Rotation	  */
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

			/* 		Deletion 	   */
			size_t deleteNode(node_pointer toDelete) {
				node_pointer x, y;
				// checkTreeProperties(_head);
				unset_bounds();
				y = toDelete;
				int y_original_color = y->color;
				if (toDelete->leftChild == NULL) {
					x = toDelete->rightChild;
					rbTransplant(toDelete, toDelete->rightChild);
				} else if (toDelete->rightChild == NULL) {
					x = toDelete->leftChild;
					rbTransplant(toDelete, toDelete->leftChild);
				} else {
					y = get_min(toDelete->rightChild);
					y_original_color = y->color;
					x = y->rightChild;
					if (y->parent == toDelete) {
						x->parent = y;
					} else {
						rbTransplant(y, y->rightChild);
						y->rightChild = toDelete->rightChild;
						y->rightChild->parent = y;
					}
					rbTransplant(toDelete, y);
					y->leftChild = toDelete->leftChild;
					y->leftChild->parent = y;
					y->color = toDelete->color;
				}
				delete(toDelete);
				if (y_original_color == 0 && x)
					fixDelete(x);
				set_bounds();
				return 1;
			}

			void fixDelete(node_pointer node) {
				node_pointer sibling;
				while (node != _head && node->color == 0) {
					if (node == node->parent->leftChild) {		// Left Child
						sibling = node->parent->rightChild;
						if (sibling->color == 1) {
							sibling->color = 0;
							node->parent->color = 1;
							leftRotation(node->parent);
							sibling = node->parent->rightChild;
						}
						if (sibling->leftChild->color == 0 && sibling->rightChild->color == 0) {
							sibling->color = 1;
							node = node->parent;
						} else {
							if (sibling->rightChild->color == 0) {
								sibling->leftChild->color = 0;
								sibling->color = 1;
								rightRotation(sibling);
								sibling = node->parent->rightChild;
							}
							sibling->color = node->parent->color;
							node->parent->color = 0;
							sibling->rightChild->color = 0;
							leftRotation(node->parent);
							node = _head;
						}
					} else {									// Right Child
						sibling = node->parent->leftChild;
						if (sibling->color == 1) {
							sibling->color = 0;
							node->parent->color = 1;
							rightRotation(node->parent);
							sibling = node->parent->leftChild;
						}
						if (sibling->leftChild->color == 0 && sibling->rightChild->color == 0) {
							sibling->color = 1;
							node = node->parent;
						} else {
							if (sibling->leftChild->color == 0) {
								sibling->rightChild->color = 0;
								sibling->color = 1;
								leftRotation(sibling);
								sibling = node->parent->leftChild;
							}
							sibling->color = node->parent->color;
							node->parent->color = 0;
							sibling->leftChild->color = 0;
							rightRotation(node->parent);
							node = _head;
						}
					}
				}
				node->color = 0;
			}

			void rbTransplant(node_pointer a, node_pointer b) {
				if (a->parent == NULL)
					_head = b;
				else if (a == a->parent->leftChild)
					a->parent->leftChild = b;
				else
					a->parent->rightChild = b;
				if (b)
					b->parent = a->parent;
			}

			/* 		Utils		*/
			node_pointer get_min(node_pointer node) const {
				while (node->leftChild)
					node = node->leftChild;
				return node;
			}

			node_pointer get_max(node_pointer node) const {
				while (node->rightChild)
					node = node->rightChild;
				return node;
			}

			void set_bounds() const {
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

			void unset_bounds() const {
				if (_begin->parent && _begin->parent != _end)
					_begin->parent->leftChild = NULL;
				if (_end->parent && _end->parent != _begin)
					_end->parent->rightChild = NULL;
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

			void	checkTreeProperties(node_pointer head) {
				unset_bounds();
				if (_head->color != 0)
					std::cout << " Bad head color." << std::endl;
				if (!checkTwoConsecutivesRed(head))
					std::cout << " Two consecutives red nodes." << std::endl;
				blackNodes(head);
				print();
				set_bounds();
			}

			int blackNodes(node_pointer node) {
				if (node == NULL)
					return 1;
				int rightBlackNodes = blackNodes(node->rightChild);
				int leftBlackNodes = blackNodes(node->leftChild);
				if (rightBlackNodes != leftBlackNodes)
					std::cout << "bad Number Black Nodes" << std::endl;
				if (node->color == 0)
					++leftBlackNodes;
				return leftBlackNodes;
			}

			bool	checkTwoConsecutivesRed(node_pointer node) {
				bool ret = true;
				if (!node)
					return true;
				if (node->color == 1 && node->parent->color == 1)
					return false;
				ret *= checkTwoConsecutivesRed(node->leftChild);
				ret *= checkTwoConsecutivesRed(node->rightChild);
				return ret;
			}

			/*		TO DELETE		*/
			void	printNodeAndChild(node_pointer node) {
				std::cout << "NODE: " << node->data.first << (node->color == 0 ? " | black" : " | red") << std::endl;
				if (node->leftChild != NULL)
						std::cout << "\t\tLEFT_CHILD: " << node->leftChild->data.first << (node->leftChild->color == 0 ? " | black" : " | red") << std::endl;
				else
						std::cout << "\t\tLEFT_CHILD: NULL" << std::endl;
				if (node->rightChild != NULL)
						std::cout << "\t\tRIGHT_CHILD: " << node->rightChild->data.first << (node->rightChild->color == 0 ? " | black" : " | red") << std::endl;
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

	}; // class bst_red_black

}; // namespace ft

#endif

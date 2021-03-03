#pragma once

#include <memory>
#include <iostream>
#include "node.hpp"
#include "iterator.hpp"

namespace ft {

	template <class T, class Allocator = std::allocator<T> >
	class list
	{
		public:

			typedef T										value_type;
			typedef Allocator								allocator_type;
			typedef typename Allocator::reference			reference;
			typedef typename Allocator::const_reference		const_reference;
			typedef typename Allocator::pointer				pointer;
			typedef typename Allocator::const_pointer		const_pointer;
			typedef size_t									size_type;

			typedef Node<value_type>		Node;
			typedef typename Allocator::template rebind<Node>::other allocatorNode;

			typedef ft::iterator<T>	iterator;
		
		private:

			allocator_type		_allocator;
			allocatorNode		_allocatorNode;
			Node*				_node;
			//		BufferLink	(Data member undefined)
			Node*				_head;
			Node*				_tail;
			size_type			_size;

			Node* newNode() {
				Node*		ret;
				Node		usl;

				ret = _allocatorNode.allocate(1);
				_allocatorNode.construct(ret, usl);
				return (ret);
			}

		public:

			explicit list(const allocator_type& alloc = allocator_type()) {
				_size = 0;
				_allocator = alloc;
				_node = NULL;
				_head = newNode();
				_tail = newNode();
				_head->_next = _tail;
				_tail->_prev = _head;
			}

			explicit list(size_type n, const value_type& val = value_type(), const allocator_type& alloc = allocator_type()) {
				_allocator = alloc;
				_size = 0;
				_node = NULL;
				_head = newNode();
				_tail = newNode();
				_head->_next = _tail;
				_tail->_prev = _head;
				if (n != 0) {
					for (size_type i = 0; i < n; ++i) {
						push_back(val + i);
					}
				}
			}

			~list() {
				Node*	tmp = NULL;
				while (_head != _tail) {
					tmp = _head;
					_head = _head->_next;
					_allocatorNode.deallocate(tmp, 1);
				}
				_allocatorNode.deallocate(_tail, 1);
			}

			/*				Iterators		*/

			iterator		begin() {
				iterator	lnk;
				if (_size != 0)
					lnk.setLink(_head->_next);
				return (lnk);
			}

			iterator		end() {
				iterator	lnk;
				if (_size != 0)
					lnk.setLink(_tail->_prev);
				return (lnk);
			}

			/* 				CAPACITY		*/

			bool			empty() const {
				if (_size == 0)
					return (true);
				return (false);
			}

			size_type		size() const {
				return (_size);
			}

			size_type		max_size() const {
				/*	TODO */
				return (0);
			}

			/*				MODIFIERS		*/

			void	push_back(const value_type& val) {
				if (!_node) {
					_node = newNode();
					_node->_data = val;
					_node->_prev = _head;
					_head->_next = _node;
					_node->_next = _tail;
					_head->_prev = _node;
				}
				else {
					Node*	tmp = NULL;
					tmp = newNode();
					tmp->_data = val;
					tmp->_prev = _node;
					tmp->_next = _tail;
					_tail->_prev = tmp;
					_node->_next = tmp;
					_node = tmp;
				}
				_size++;
			}

			/*				TMP		*/

			void TMP_Display() {
				if (_size == 0)
					return;
				Node*	tmp = _head->_next;
				while (tmp != _tail) {
					std::cout << tmp->_data << std::endl;
					tmp = tmp->_next;
				}
			}
	
	};// Class List
}	// Namespace FT

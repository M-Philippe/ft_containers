#ifndef MAP_ITERATOR_HPP
# define MAP_ITERATOR_HPP

#include "../iterator/iterator.hpp"
#include "../utils/utils.hpp"

#include <stdlib.h> // tmp
#include <iostream> // tmp std::cout std::endl

namespace ft {
	template <typename N /* node_pointer */, typename T /* node_pointer->data */, class Compare>
	class bst_rb_iterator : public ft::iterator<ft::bidirectional_iterator_tag, T>
	{

		public:
			typedef typename ft::iterator<ft::bidirectional_iterator_tag, T>::value_type value_type;
			typedef typename ft::iterator<ft::bidirectional_iterator_tag, T>::difference_type difference_type;
			typedef T* pointer;
			typedef T& reference;
			typedef typename ft::iterator<ft::bidirectional_iterator_tag, T>::iterator_category iterator_category;
			typedef N node_pointer;
			typedef Compare data_compare;

		private:
			typedef bst_rb_iterator<N, T, Compare> self_type;

		protected:
			node_pointer _node;
			data_compare _comp;

		public:
			bst_rb_iterator() {
				_node = NULL;
				_comp = data_compare();
			}
			bst_rb_iterator(N node) {
				_comp = data_compare();
				_node = node;
			}
			bst_rb_iterator(const bst_rb_iterator& org) {
				_comp = org._comp;
				_node = org._node;
			}
			~bst_rb_iterator() {}

			operator bst_rb_iterator<N, const T, Compare>() {
				return (bst_rb_iterator<N, const T, Compare>(_node));
			}

			reference operator*() { return _node->data; }
			pointer operator->() { return &_node->data; }

			void	moveToLeftmostNode() {
				while (_node->leftChild != NULL)
					_node = _node->leftChild;
			}

			/* pre-increment */
			self_type operator++() {
				if (_node->rightChild) {
					for (_node = _node->rightChild; _node->leftChild; _node = _node->leftChild);
				}
				else if (_node == _node->parent->leftChild)
					_node = _node->parent;
				else {
					for (_node = _node->parent; _node == _node->parent->rightChild; _node = _node->parent);
					_node = _node->parent;
				}
				return *this;
			}

			self_type operator--() {
				if (_node->leftChild) {
					for (_node = _node->leftChild; _node->rightChild; _node = _node->rightChild);
				} else if (_node == _node->parent->rightChild) {
					_node = _node->parent;
				} else {
					for (_node = _node->parent; _node == _node->parent->leftChild; _node = _node->parent);
					_node = _node->parent;
				}
				return *this;
			}
			/* post-increment */
			self_type operator++(int) {
				self_type it(*this);
				++(*this);
				return it;
			}

			self_type operator--(int) {
				self_type it(*this);
				--(*this);
				return it;
			}

		friend bool operator==(const self_type& lhs, const self_type& rhs) { return lhs._node == rhs._node; }
		friend bool operator!= (const self_type& lhs, const self_type& rhs) { return !(lhs == rhs); }

	}; // bst_rb_iterator

	template <typename N /* node_pointer */, typename T /* node_pointer->data */, class Compare>
	class reverse_bst_rb_iterator : public bst_rb_iterator<N, T, Compare>
	{
		public:
			typedef reverse_bst_rb_iterator<N, T, Compare> self_type;

		public:
			reverse_bst_rb_iterator() {
				this->_node = NULL;
				this->_comp = Compare();
			}
			reverse_bst_rb_iterator(N node) {
				this->_comp = Compare();
				this->_node = node;
			}
			reverse_bst_rb_iterator(const reverse_bst_rb_iterator& org) {
				this->_comp = org._comp;
				this->_node = org._node;
			}
			~reverse_bst_rb_iterator() {}

			operator reverse_bst_rb_iterator<N, const T, Compare>() {
				return (reverse_bst_rb_iterator<N, const T, Compare>(this->_node));
			}

			self_type operator++() {
				if (this->_node->leftChild) {
					for (this->_node = this->_node->leftChild; this->_node->rightChild; this->_node = this->_node->rightChild);
				} else if (this->_node == this->_node->parent->rightChild) {
					this->_node = this->_node->parent;
				} else {
					for (this->_node = this->_node->parent; this->_node == this->_node->parent->leftChild; this->_node = this->_node->parent);
					this->_node = this->_node->parent;
				}
				return *this;
			}

			self_type operator++(int) {
				reverse_bst_rb_iterator it(*this);
				++(*this);
				return it;
			}

			self_type operator--() {
				if (this->_node->rightChild) {
					for (this->_node = this->_node->rightChild; this->_node->leftChild; this->_node = this->_node->leftChild);
				}
				else if (this->_node == this->_node->parent->leftChild)
					this->_node = this->_node->parent;
				else {
					for (this->_node = this->_node->parent; this->_node == this->_node->parent->rightChild; this->_node = this->_node->parent);
					this->_node = this->_node->parent;
				}
				return *this;
			}

			self_type operator--(int) {
				reverse_bst_rb_iterator it(*this);
				--(*this);
				return it;
			}
	};
}; // namespace ft

#endif

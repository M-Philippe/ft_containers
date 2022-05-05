#ifndef MAP_ITERATOR_HPP
# define MAP_ITERATOR_HPP

#include "../iterator/iterator.hpp"
#include "../utils/utils.hpp"

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

			bst_rb_iterator& operator=(const bst_rb_iterator& org) {
				if (this != &org) {
					this->_node = org._node;
					this->_comp = org._comp;
				}
				return *this;
			}

			operator bst_rb_iterator<N, const T, Compare>() const {
				return (bst_rb_iterator<N, const T, Compare>(_node));
			}

			reference	operator*() const { return _node->data; }
			pointer 	operator->() const { return &_node->data; }

			self_type& operator++() {
				if (!_node->rightChild->is_null) {
					for (_node = _node->rightChild; !_node->leftChild->is_null; _node = _node->leftChild);
				} else if (_node == _node->parent->leftChild) {
					_node = _node->parent;
				} else {
					for (_node = _node->parent; _node == _node->parent->rightChild; _node = _node->parent);
					_node = _node->parent;
				}
				return *this;
			}

			/* pre-increment */
			self_type& operator--() {
				if (!_node->leftChild->is_null) {
					for (_node = _node->leftChild; !_node->rightChild->is_null; _node = _node->rightChild);
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
}; // namespace ft

#endif

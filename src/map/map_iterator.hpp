#ifndef MAP_ITERATOR_HPP
# define MAP_ITERATOR_HPP

#include "../iterator/iterator.hpp"
#include "../utils/utils.hpp"

#include <stdlib.h> // tmp
#include <iostream> // tmp std::cout std::endl

namespace ft {
	template <typename N /* node_pointer */, typename T /* node_pointer->data */, class Compare>
	class map_iterator : public ft::iterator<ft::bidirectional_iterator_tag, T>
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
			node_pointer _node;
			data_compare _comp;

		public:
			map_iterator() {
				_node = NULL;
				_comp = data_compare();
			}
			map_iterator(N node) {
				_comp = data_compare();
				if (node == NULL) {
					_node = NULL;
					return;
				}
				while (node->leftChild != NULL)
					node = node->leftChild;
				_node = node;
			}
			map_iterator(N node, bool goRight) {
				(void)goRight;
				_comp = data_compare();
				while (node->rightChild != NULL)
					node = node->rightChild;
				_node = node->rightChild;
			}
			map_iterator(const map_iterator& org) {
				_comp = org._comp;
				_node = org._node;
			}
			~map_iterator() {}

			operator map_iterator<N, const T, Compare>() {
				return (map_iterator<N, const T, Compare>(_node));
			}

			reference operator*() { return *_node->data; }
			pointer operator->() { return &_node->data; }

			void	moveToLeftmostNode() {
				while (_node->leftChild != NULL)
					_node = _node->leftChild;
			}

			/* pre-increment */
			map_iterator operator++() {
				node_pointer current = _node;
				if (_node->rightChild != NULL) {
					_node = _node->rightChild;
					moveToLeftmostNode();
					return *this;
				} else if (_node->parent != NULL && !_comp(_node->parent->data.first, current->data.first)) {
					/*_node->parent->data->first > current->data->first*/
					_node = _node->parent;
					return *this;
				} else {
					// might check here.
					_node = _node->rightChild;
					return *this;
				}
				return *this;
				//node_pointer parent = _node->parent;
				//if (_node->rightChild) {
				//	for (_node = _node->rightChild; _node->leftChild; _node = _node->leftChild);
				//}
				//else if (_node == parent->leftChild)
				//	_node = parent;
				//else
				//	for (_node = _node->parent; _node == _node->parent->rightChild; _node = _node->parent);
				//return *this;
			}

			/* post-increment */
			map_iterator operator++(int) {
				map_iterator it(*this);
				++(*this);
				return it;
			}

		friend bool operator==(const map_iterator& lhs, const map_iterator& rhs) { return lhs._node == rhs._node; }
		friend bool operator!= (const map_iterator& lhs, const map_iterator& rhs) { return !(lhs == rhs); }

	}; // map_iterator

}; // namespace ft

#endif

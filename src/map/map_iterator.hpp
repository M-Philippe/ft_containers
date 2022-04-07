#ifndef MAP_ITERATOR_HPP
# define MAP_ITERATOR_HPP

#include "../iterator/iterator.hpp"
#include "../utils/utils.hpp"

#include <stdlib.h> // tmp

namespace ft {
	template <typename N /* node_pointer */, typename T /* node_pointer->data */>
	class map_iterator : public ft::iterator<ft::bidirectional_iterator_tag, T>
	{

		public:
			typedef typename ft::iterator<ft::bidirectional_iterator_tag, T>::value_type value_type;
			typedef typename ft::iterator<ft::bidirectional_iterator_tag, T>::difference_type difference_type;
			typedef T* pointer;
			typedef T& reference;
			typedef typename ft::iterator<ft::bidirectional_iterator_tag, T>::iterator_category iterator_category;
			typedef N node_pointer;

		private:
			node_pointer _node;

		public:
			map_iterator() { _node = NULL; }
			map_iterator(N node) {
				while (node->leftChild != NULL)
					node = node->leftChild;
				_node = node;
			}
			map_iterator(N node, bool goRight) {
				(void)goRight;
				while (node->rightChild != NULL)
					node = node->rightChild;
				_node = node->rightChild;
			}
			map_iterator(const map_iterator& org) { _node = org._node; }
			~map_iterator() {}

			reference operator*() { return *_node->data; }
			pointer operator->() { return _node->data; }

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
				} else if (_node->parent != NULL && _node->parent->data->first > current->data->first) {
					_node = _node->parent;
					return *this;
				} else {
					// might check here.
					_node = _node->rightChild;
					return *this;
				}
				return *this;
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

#ifndef MAP_HPP
# define MAP_HPP

#include <functional>
#include <cstddef> // ptrdiff_t
#include <iostream> // std::cout && std::endl

namespace ft {

/*template <typename T>
	class map_iterator : public ft::iterator<ft::bidirectional_iterator_tag, T>
	{

		public:
			typedef typename ft::iterator<ft::bidirectional_iterator_tag, T>::value_type value_type;
			typedef typename ft::iterator<ft::bidirectional_iterator_tag, T>::difference_type difference_type;
			typedef T* pointer;
			typedef T& reference;
			typedef typename ft::iterator<ft::bidirectional_iterator_tag, T>::iterator_category iterator_category;

		private:
			pointer _link;

		public:
			map_iterator() { _link = NULL; }
			~map_iterator() {}

	}; // map_iterator*/

	template <class T1, class T2>
	struct pair {
		typedef T1	first_type;
		typedef T2	second_type;

		pair() {
			first = first_type();
			second = second_type();
		}
		template<class U, class V>
		pair (const pair<U,V>& pr) : first(pr.first), second(pr.second)  {}
		pair (const first_type& a, const second_type& b) {
			first = a;
			second = b;
		}
		~pair() {}

		first_type	first;
		second_type	second;

	}; // struct pair

	template <class T1, class T2>
  ft::pair<T1, T2> make_pair (T1 x, T2 y) {
		return ft::pair<T1, T2>(x, y);
	}

	template < class Key /* map::key_type */, class T /* map::mapped_type */, class Compare = std::less<Key> /* map::key_compare */, class Alloc = std::allocator<pair<const Key,T> /* map::allocator_type */> >
	class map {

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
		//typedef typename ft::map_iterator<T> iterator;
		// iterator	a bidirectional iterator to value_type	convertible to const_iterator
		// const_iterator	a bidirectional iterator to const value_type
		// reverse_iterator	reverse_iterator<iterator>
		// const_reverse_iterator	reverse_iterator<const_iterator>
		typedef ptrdiff_t difference_type;
		typedef size_t size_type;

	private:

		// color -> true: red, false: black.
		typedef struct map_node {
			map_node* leftChild;
			map_node*	rightChild;
			map_node*	parent;
			bool	color;
			pointer data;
		} node;

		typedef typename Alloc::template rebind<node>::other allocator_node;
		typedef typename allocator_node::pointer node_pointer;

	public:

		map(const key_compare& comp = key_compare(), const allocator_type& alloc = allocator_type()) {
			_compare = comp;
			_alloc = alloc;
			_head = NULL;
			_alloc_node = allocator_node();
			_size = 0;
		}
		~map() {
			_alloc.destroy(_head->data);
			_alloc.deallocate(_head->data, 1);
			_alloc_node.deallocate(_head, 1);
		}

		/*
			Process:
				- classic insert.
				-	check rules / fix tree.
		*/

		bool	insert_branch_left(node_pointer current, const value_type& val) {
			if (current->leftChild == NULL) {
				node_pointer nodeAdded = _alloc_node.allocate(1);
				nodeAdded->data = _alloc.allocate(1);
				_alloc.construct(nodeAdded->data, val);
				nodeAdded->leftChild = NULL;
				nodeAdded->rightChild = NULL;
				nodeAdded->color = false;
				current->leftChild = nodeAdded;
				_size++;
				//balance_tree();
				return true;
			} else {
				current = current->leftChild;
				if (val.first == current->data->first)
					return false;
				else if (val.first < current->data->first)
					return insert_branch_left(current, val);
				else if (val.first > current->data->first)
					return insert_branch_right(current, val);
			}
			return (false);
		}

		bool	insert_branch_right(node_pointer current, const value_type& val) {
			if (current->rightChild == NULL) {
				node_pointer nodeAdded = _alloc_node.allocate(1);
				nodeAdded->data = _alloc.allocate(1);
				_alloc.construct(nodeAdded->data, val);
				nodeAdded->leftChild = NULL;
				nodeAdded->rightChild = NULL;
				nodeAdded->color = false;
				current->rightChild = nodeAdded;
				_size++;
				return true;
			} else {
				current = current->rightChild;
				if (val.first == current->data->first)
					return false;
				else if (val.first < current->data->first)
					return insert_branch_left(current, val);
				else if (val.first > current->data->first)
					return insert_branch_right(current, val);
			}
			return (false);
		}

		// true if created elements or false if already existing elements.
		bool insert (const value_type& val) {
			if (!_head) {
				_head = _alloc_node.allocate(1);
				value_type t = val;
				_head->leftChild = NULL;
				_head->rightChild = NULL;
				_head->parent = NULL;
				_head->color = true;
				_head->data = _alloc.allocate(1);
				_alloc.construct(_head->data, val);
				_size++;
				return (true);
			} else {
				node_pointer current = _head;
				if (current->data->first == val.first)
					return (false);
				else if (val.first < current->data->first) {
					return insert_branch_left(current, val);
				}
				else if (val.first > current->data->first) {
					return insert_branch_right(current, val);
				}
			}
			return (false);
		}

		void	printNode(node_pointer node) {
			if (node == NULL)
				return;
			std::cout << "[" << node->data->first << "] : " << node->data->second << (node->color == false ? " red" : " black") << std::endl;
			printNode(node->leftChild);
			printNode(node->rightChild);
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

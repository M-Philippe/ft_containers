#ifndef SET_HPP
# define SET_HPP

#include <functional>
#include "../map/bst_red_black.hpp"
#include <cstddef>

namespace ft {

	template < class T, class Compare = std::less<T>, class Alloc = std::allocator<T> >
	class set {

		public:

			typedef T	key_type;
			typedef T value_type;
			typedef Compare key_compare;
			typedef Compare	value_compare;
			typedef Alloc	allocator_type;
			typedef typename allocator_type::reference reference;
			typedef typename allocator_type::const_reference const_reference;
			typedef typename allocator_type::pointer pointer;
			typedef typename allocator_type::const_pointer const_pointer;
			typedef typename ft::bst_red_black<value_type, Compare, Alloc, false>::iterator iterator;
			typedef typename ft::bst_red_black<value_type, Compare, Alloc, false>::const_iterator const_iterator;
			//reverse_iterator	reverse_iterator<iterator>
			//const_reverse_iterator	reverse_iterator<const_iterator>
			typedef ptrdiff_t difference_type;
			typedef size_t size_type;

			explicit set (const key_compare& comp = key_compare(), const allocator_type& alloc = allocator_type()) {
				(void)comp;
				(void)alloc;
			}

			~set() {};

			/*
			**		ITERATORS
			*/
			iterator 		begin() { return bst.begin(); }
			const_iterator 	begin() const { return bst.begin(); }
			iterator 		end() { return bst.end(); }
			const_iterator 	end() const { return bst.end(); }

			/*
			**		CAPACITY
			*/
			size_type	size() const { return bst.size(); }
			bool		empty() const { return bst.size() == 0; }
			size_type	max_size() const { return bst.max_size(); }

			/*
			**		MODIFIERS
			*/
			pair<iterator, bool>	insert(const value_type& val) { return bst.insert(val); }
			iterator				insert(iterator position, const value_type& k) { return bst.insert(position, k); }
			template <class InputIterator>
			void	insert(InputIterator first, InputIterator last) { bst.insert(first, last); }

			void 					erase(iterator first) { bst.erase(first); }
			void 					erase(iterator first, iterator last) { bst.erase(first, last); }
			size_type 				erase(const key_type& k) { return bst.erase(k); }

			void swap (set& x) { bst.swap(x.bst); }
			void clear() {
				if (bst.size() != 0)
					bst.clear();
			}

			/*
			**		OBSERVERS
			*/
			key_compare key_comp() const { return key_compare(); }
			value_compare value_comp() const { return value_compare(); }

			/*
			**		OPERATIONS
			*/
			iterator find (const key_type& k) { return bst.find(k); }
			const_iterator find (const key_type& k) const { return bst.find(k); }
			size_type	count(const key_type& k) const { return bst.count(k); }
			iterator lower_bound (const key_type& k) { return bst.lower_bound(k); }
			const_iterator lower_bound (const key_type& k) const { return bst.lower_bound(k); }
			iterator upper_bound (const key_type& k) { return bst.upper_bound(k); }
			const_iterator upper_bound (const key_type& k) const { return bst.upper_bound(k); }
			pair<iterator,iterator>             equal_range (const key_type& k) { return equal_range(k); }

			/*
			**		ALLOCATOR
			*/
			allocator_type get_allocator() const { return allocator_type(); }

		private:
			ft::bst_red_black<value_type, Compare, Alloc, false> bst;

	};

}; // namespace ft

#endif

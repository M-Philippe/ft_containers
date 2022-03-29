#ifndef STACK_HPP
# define STACK_HPP

#include "../vector/vector.hpp"

namespace ft {

	template <class T, class Container = ft::vector<T> >
	class stack {

		public:
			//value_type	The first template parameter (T)	Type of the elements
			//container_type	The second template parameter (Container)	Type of the underlying container
			//size_type	an unsigned integral type	usually the same as size_t
			typedef T	value_type;
			typedef Container	container_type;
			typedef size_t	size_typ;

			explicit stack (const container_type& ctnr = container_type()) {
				_underlying = ctnr;
			}
			~stack() {};

			bool empty() const { return _underlying.empty(); }

			value_type& top() { return _underlying.back(); }
			const value_type& top() const { return _underlying.back(); }
			void push (const value_type& val) { _underlying.push_back(val); }
			void pop() { _underlying.pop_back(); }

		private:
			container_type _underlying;

	}; // class stack

}; // namespace ft

#endif

#ifndef STACK_HPP
# define STACK_HPP

#include "../vector/vector.hpp"

namespace ft {

	template <class T, class Container = ft::vector<T> >
	class stack {

		public:
			typedef T	value_type;
			typedef Container	container_type;
			typedef size_t	size_type;

			explicit stack (const container_type& ctnr = container_type()) {
				_underlying = ctnr;
			}
			~stack() {};

			bool empty() const { return _underlying.empty(); }
			size_type size() const { return _underlying.size(); }
			value_type& top() { return _underlying.back(); }
			const value_type& top() const { return _underlying.back(); }
			void push (const value_type& val) { _underlying.push_back(val); }
			void pop() { _underlying.pop_back(); }

			template <class T_, class Container_>
				friend bool operator== (const stack<T_ ,Container_>& lhs, const stack<T_, Container_>& rhs);
			template <class T_, class Container_>
				friend bool operator!= (const stack<T_, Container_>& lhs, const stack<T_, Container_>& rhs);
			template <class T_, class Container_>
				friend bool operator<  (const stack<T_, Container_>& lhs, const stack<T_, Container_>& rhs);
			template <class T_, class Container_>
				friend bool operator<= (const stack<T_, Container_>& lhs, const stack<T_, Container_>& rhs);
			template <class T_, class Container_>
				friend bool operator>  (const stack<T_, Container_>& lhs, const stack<T_, Container_>& rhs);
			template <class T_, class Container_>
				friend bool operator>= (const stack<T_, Container_>& lhs, const stack<T_, Container_>& rhs);

		private:
			container_type _underlying;

	}; // class stack

	template <class T_, class Container_>
		bool operator== (const stack<T_, Container_>& lhs, const stack<T_, Container_>& rhs) { return lhs._underlying == rhs._underlying; }
	template <class T_, class Container_>
		bool operator!= (const stack<T_, Container_>& lhs, const stack<T_, Container_>& rhs) { return lhs._underlying != rhs._underlying; }
	template <class T_, class Container_>
		bool operator<  (const stack<T_, Container_>& lhs, const stack<T_, Container_>& rhs) { return lhs._underlying < rhs._underlying; }
	template <class T_, class Container_>
		bool operator<= (const stack<T_, Container_>& lhs, const stack<T_, Container_>& rhs) { return lhs._underlying <= rhs._underlying; }
	template <class T_, class Container_>
		bool operator>  (const stack<T_, Container_>& lhs, const stack<T_, Container_>& rhs) { return lhs._underlying > rhs._underlying; }
	template <class T_, class Container_>
		bool operator>= (const stack<T_, Container_>& lhs, const stack<T_, Container_>& rhs) { return lhs._underlying >= rhs._underlying; }

}; // namespace ft

#endif

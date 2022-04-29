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
				c = ctnr;
			}
			~stack() {};

			bool empty() const { return c.empty(); }
			size_type size() const { return c.size(); }
			value_type& top() { return c.back(); }
			const value_type& top() const { return c.back(); }
			void push (const value_type& val) { c.push_back(val); }
			void pop() { c.pop_back(); }

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

		protected:
			container_type c;

	}; // class stack

	template <class T_, class Container_>
		bool operator== (const stack<T_, Container_>& lhs, const stack<T_, Container_>& rhs) { return lhs.c == rhs.c; }
	template <class T_, class Container_>
		bool operator!= (const stack<T_, Container_>& lhs, const stack<T_, Container_>& rhs) { return lhs.c != rhs.c; }
	template <class T_, class Container_>
		bool operator<  (const stack<T_, Container_>& lhs, const stack<T_, Container_>& rhs) { return lhs.c < rhs.c; }
	template <class T_, class Container_>
		bool operator<= (const stack<T_, Container_>& lhs, const stack<T_, Container_>& rhs) { return lhs.c <= rhs.c; }
	template <class T_, class Container_>
		bool operator>  (const stack<T_, Container_>& lhs, const stack<T_, Container_>& rhs) { return lhs.c > rhs.c; }
	template <class T_, class Container_>
		bool operator>= (const stack<T_, Container_>& lhs, const stack<T_, Container_>& rhs) { return lhs.c >= rhs.c; }

}; // namespace ft

#endif

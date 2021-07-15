#include <cstdio>
#include <iostream>

namespace ft {

	template <class T, class Alloc = std::allocator<T> > class vector
	{

        public:

            typedef T           value_type;
            typedef size_t      size_type;
            typedef Alloc       allocator_type;
			typedef typename    allocator_type::reference			    reference;
			typedef typename    allocator_type::const_reference		    const_reference;

        private:
            T*              _array;
            size_type       _size;
            size_type       _capacity;
            allocator_type  _alloc;

		public:
            
            /*
             *      CONSTRUCTORS
            */

            explicit vector(size_type n, const value_type& val = value_type(), const allocator_type& alloc = allocator_type()) : _alloc(alloc) {
                _array = _alloc.allocate(n);
                _size = n;
                _capacity = n;
                assign(n, val);
            }

            ~vector() {
                _alloc.deallocate(_array, _size);
            }

            /*
            **      ITERATORS
            */

            /*
            **      CAPACITY
            */
            
            size_type   size() const {
                return (_size);
            }

            size_type   capacity() const {
                return (_capacity);
            }

            bool        empty() const {
                if (_size == 0)
                    return (true);
                else
                    return (false);
            }

            /*
            **      ELEMENT ACCESS
            */

            reference   at(size_type n) {
                return (_array[n]);
            }

            const_reference   at(size_type n) const {
                return (_array[n]);
            }

            /*
            **      MODIFIERS
            */
            
            void    assign(size_type n, const value_type& val) {
                if (n > _capacity)
                    return;
                for (size_type i = 0; i < _capacity; ++i) {
                    _array[i] = val;
                }
            }

            /*
            **      ALLOCATOR
            */

            allocator_type  get_allocator() const {
                return (_alloc);
            }
	};

} // namespace ft

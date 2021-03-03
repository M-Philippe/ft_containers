#pragma once

#include <iostream>
#include "node.hpp"

namespace ft {
	template <typename T>
	class iterator {
		public:
			typedef Node<T>*		nodePointer;

			iterator() {}
			~iterator() {}
	
			void setLink(const nodePointer inputLink) {
				_link = inputLink;
			}
	
			T&	operator*() {return (_link->_data);}
	
		private:
			nodePointer	_link;
	
	}; //	Class iterator
} //	Namespace ft
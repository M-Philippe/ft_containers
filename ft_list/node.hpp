#pragma once

namespace ft{
	template <typename T>
	struct Node {
		struct Node*	_prev;
		struct Node*	_next;
		T				_data;

		Node() {
			_prev = NULL;
			_next = NULL;
		}

		Node(const Node& org) {
			(void)org;
			_prev = NULL;
			_next = NULL;
			_data = 0;
		}

	};//	class Node
}//	Namespace FT

namespace ft{
	template <typename T>
	struct Node {
		struct Node*	_prev;
		struct Node*	_next;
		T				_data;
		Node() {
			//std::cout << "constructor of node called" << std::endl;
			_prev = NULL;
			_next = NULL;
		}
		Node(const Node& org) {
			//std::cout << "constructor copy" << std::endl;
			(void)org;
			_prev = NULL;
			_next = NULL;
			_data = 0;
		}
	};//	class Node
}//	Namespace FT
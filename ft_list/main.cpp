#include <iostream>
#include <list>
#include "ft_list.hpp"

int main() {

	ft::list<int> a(5, 10);
	std::cout << "size " << a.size() << std::endl;
	ft::list<int>::iterator it = a.begin();
	*it = 1576;
	ft::list<int>::iterator itE = a.end();
	*itE = 345;
	a.TMP_Display();
}

	// std::list<int> lst(25, 10);
	// for (int i = 0; i < 30; i++) {
	// 	lst.push_back(i);
	// }
	// std::list<int>::iterator it = lst.begin();
	// while (it != lst.end())
	// 	std::cout << *it++ << std::endl;

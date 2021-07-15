#include <iostream>
#include "ft_vector.hpp"

#include <vector>

int main() {
	ft::vector<int> vct(10, 8);
	std::cout << vct.at(5) << std::endl;

	std::vector<int> v(1000, 8);
	std::cout << "size: " << v.size() << std::endl;
	std::cout << "capacity: " << v.capacity() << std::endl;
	
	/*std::vector<int> x;
	int cap = x.capacity();
	for (int i = 0; i < 10000000; ++i) {
		if (cap != x.capacity()) {
			cap = x.capacity();
			std::cout << "size: " << x.size() << std::endl;
			std::cout << "capacity: " << x.capacity() << std::endl;
		}
		x.push_back(i);
	}*/
	//std::cout << 16777216 % 2 << std::endl;
	return (0);
}
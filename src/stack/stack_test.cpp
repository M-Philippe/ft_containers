#include "stack.hpp"
#include "stack_test.hpp"
#include <stack>
#include <vector>

void	stack_test() {
	std::cout << "STACK TEST" << std::endl;
	NAMESPACE::stack<int, NAMESPACE::vector<int>> s;
	for (int i = 0; i < 5; i++)
		s.push((i + 1) * 2);
	while (!s.empty()) {
		std::cout << s.top() << std::endl;
		s.pop();
	}
	std::cout << "===" << std::endl;
}

#include "stack.hpp"
#include "stack_test.hpp"
#include <stack>
#include <vector>
#include <deque>

void	stack_test() {
	std::cout << "STACK TEST" << std::endl;
	NAMESPACE::stack<int, NAMESPACE::vector<int> > s;
	for (int i = 0; i < 1000000; i++)
		s.push((i + 1) * 2);
	while (!s.empty()) {
		std::cout << s.top() << " ";
		s.pop();
	}
	std::cout << std::endl;
	std::cout << "===" << std::endl;
	NAMESPACE::stack<int, std::deque<int> > s2;
	for (int i = 0; i < 1000000; i++)
		s.push((i + 1) * 2);
	while (!s.empty()) {
		std::cout << s.top() << " ";
		s.pop();
	}
	std::cout << std::endl;
	std::cout << "===" << std::endl;
	s.push(42);
	std::cout << std::boolalpha;
	NAMESPACE::stack<int, NAMESPACE::vector<int> > s3;
	std::cout << (s == s3) << std::endl;
	std::cout << (s != s3) << std::endl;
	std::cout << (s < s3) << std::endl;
	std::cout << (s <= s3) << std::endl;
	std::cout << (s > s3) << std::endl;
	std::cout << (s >= s3) << std::endl;
	std::cout << std::noboolalpha;
}

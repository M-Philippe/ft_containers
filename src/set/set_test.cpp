#include "set_test.hpp"
#include <set>
#include "set.hpp"

#define SET_BIG_N	10000

void	print_after_insert(NAMESPACE::set<int>::iterator returnedIterator, NAMESPACE::set<int>::iterator begin, NAMESPACE::set<int>::iterator end) {
	std::cout << "From returned iterator" << std::endl;
	while (returnedIterator != end)
		std::cout << *(returnedIterator++) << " ";
	std::cout << std::endl;
	std::cout << "From begin" << std::endl;
	while (begin != end)
		std::cout << *(begin++) << " ";
	std::cout << std::endl;
}

void	set_insert_1() {
	std::cout << "set Insert (first proto)" << std::endl;
	{
		std::cout << "\t=== Case_1 ===" << std::endl;
		NAMESPACE::set<int> set;
		NAMESPACE::pair<NAMESPACE::set<int>::iterator, bool> ret;
		NAMESPACE::set<int>::iterator begin = set.begin();
		NAMESPACE::set<int>::iterator end = set.end();
		ret = set.insert(42);
		std::cout << std::boolalpha;
		std::cout << "BOOL: " << ret.second << std::endl;
		print_after_insert(ret.first, begin, end);
		ret = set.insert(2);
		std::cout << "BOOL: " << ret.second << std::endl;
		print_after_insert(ret.first, begin, end);
		ret = set.insert(9);
		std::cout << "BOOL: " << ret.second << std::endl;
		print_after_insert(ret.first, begin, end);
		ret = set.insert(1);
		std::cout << "BOOL: " << ret.second << std::endl;
		print_after_insert(ret.first, begin, end);
		ret = set.insert(78);
		std::cout << "BOOL: " << ret.second << std::endl;
		print_after_insert(ret.first, begin, end);
		std::cout << "\t===" << std::endl;
	}
	{
		std::cout << "\t=== Case_2 ===" << std::endl;
		NAMESPACE::set<int> set;
		NAMESPACE::pair<NAMESPACE::set<int>::iterator, bool> ret;
		NAMESPACE::set<int>::iterator begin = set.begin();
		NAMESPACE::set<int>::iterator end = set.end();
		ret = set.insert(17);
		std::cout << "BOOL: " << ret.second << std::endl;
		print_after_insert(ret.first, begin, end);
		ret = set.insert(9);
		std::cout << "BOOL: " << ret.second << std::endl;
		print_after_insert(ret.first, begin, end);
		ret = set.insert(19);
		std::cout << "BOOL: " << ret.second << std::endl;
		print_after_insert(ret.first, begin, end);
		ret = set.insert(75);
		std::cout << "BOOL: " << ret.second << std::endl;
		print_after_insert(ret.first, begin, end);
		ret = set.insert(81);
		std::cout << "BOOL: " << ret.second << std::endl;
		print_after_insert(ret.first, begin, end);
		std::cout << "\t===" << std::endl;
	}
	{
		std::cout << "\t=== Case_3 ===" << std::endl;
		NAMESPACE::set<int> set;
		NAMESPACE::pair<NAMESPACE::set<int>::iterator, bool> ret;
		NAMESPACE::set<int>::iterator begin = set.begin();
		NAMESPACE::set<int>::iterator end = set.end();
		ret = set.insert(17);
		std::cout << "BOOL: " << ret.second << std::endl;
		print_after_insert(ret.first, begin, end);
		ret = set.insert(9);
		std::cout << "BOOL: " << ret.second << std::endl;
		print_after_insert(ret.first, begin, end);
		ret = set.insert(19);
		std::cout << "BOOL: " << ret.second << std::endl;
		print_after_insert(ret.first, begin, end);
		ret = set.insert(75);
		std::cout << "BOOL: " << ret.second << std::endl;
		print_after_insert(ret.first, begin, end);
		ret = set.insert(8);
		std::cout << "BOOL: " << ret.second << std::endl;
		print_after_insert(ret.first, begin, end);
		ret = set.insert(10);
		std::cout << "BOOL: " << ret.second << std::endl;
		print_after_insert(ret.first, begin, end);
		ret = set.insert(34);
		std::cout << "BOOL: " << ret.second << std::endl;
		print_after_insert(ret.first, begin, end);
		ret = set.insert(67);
		std::cout << "BOOL: " << ret.second << std::endl;
		print_after_insert(ret.first, begin, end);
		ret = set.insert(46);
		std::cout << "BOOL: " << ret.second << std::endl;
		print_after_insert(ret.first, begin, end);
		ret = set.insert(98);
		std::cout << "BOOL: " << ret.second << std::endl;
		print_after_insert(ret.first, begin, end);
		ret = set.insert(89);
		std::cout << "BOOL: " << ret.second << std::endl;
		print_after_insert(ret.first, begin, end);
		ret = set.insert(1);
		std::cout << "BOOL: " << ret.second << std::endl;
		print_after_insert(ret.first, begin, end);
		ret = set.insert(3);
		std::cout << "BOOL: " << ret.second << std::endl;
		print_after_insert(ret.first, begin, end);
		ret = set.insert(80);
		std::cout << "BOOL: " << ret.second << std::endl;
		print_after_insert(ret.first, begin, end);
	}
	{
		std::cout << "\t=== Case_4 ===" << std::endl;
		NAMESPACE::set<int> set;
		NAMESPACE::pair<NAMESPACE::set<int>::iterator, bool> ret;
		NAMESPACE::set<int>::iterator begin = set.begin();
		NAMESPACE::set<int>::iterator end = set.end();
		ret = set.insert(0);
		std::cout << "BOOL: " << ret.second << std::endl;
		print_after_insert(ret.first, begin, end);
		ret = set.insert(9);
		std::cout << "BOOL: " << ret.second << std::endl;
		print_after_insert(ret.first, begin, end);
		ret = set.insert(-1);
		std::cout << "BOOL: " << ret.second << std::endl;
		print_after_insert(ret.first, begin, end);
		ret = set.insert(-2);
		std::cout << "BOOL: " << ret.second << std::endl;
		print_after_insert(ret.first, begin, end);
		ret = set.insert(-1);
		std::cout << "BOOL: " << ret.second << std::endl;
		print_after_insert(ret.first, begin, end);
		ret = set.insert(-5);
		std::cout << "BOOL: " << ret.second << std::endl;
		print_after_insert(ret.first, begin, end);
		ret = set.insert(10);
		std::cout << "BOOL: " << ret.second << std::endl;
		print_after_insert(ret.first, begin, end);
		ret = set.insert(8);
		std::cout << "BOOL: " << ret.second << std::endl;
		print_after_insert(ret.first, begin, end);
		ret = set.insert(6);
		std::cout << "BOOL: " << ret.second << std::endl;
		print_after_insert(ret.first, begin, end);
		ret = set.insert(7);
		std::cout << "BOOL: " << ret.second << std::endl;
		print_after_insert(ret.first, begin, end);
		ret = set.insert(9);
		std::cout << "BOOL: " << ret.second << std::endl;
		print_after_insert(ret.first, begin, end);
	}
	{
		std::cout << "\t=== Big Insert ===" << std::endl;
		NAMESPACE::set<int> set;
		NAMESPACE::pair<NAMESPACE::set<int>::iterator, bool> ret;
		NAMESPACE::set<int>::iterator begin = set.begin();
		NAMESPACE::set<int>::iterator end = set.end();
		for (int i = 0; i < SET_BIG_N; i++) {
			ret = set.insert(i % 2 == 0 ? i : -i);
		}
		std::cout << ret.second << std::endl;
		print_after_insert(ret.first, begin, end);
	}
	// Add test to check no leaks with empty set.
}

template <class SET>
void cst(const SET &lhs, const SET &rhs) {
	static int i = 0;

	std::cout << "############### [" << i++ << "] ###############"  << std::endl;
	std::cout << "eq: " << (lhs == rhs) << " | ne: " << (lhs != rhs) << std::endl;
	std::cout << "lt: " << (lhs <  rhs) << " | le: " << (lhs <= rhs) << std::endl;
	std::cout << "gt: " << (lhs >  rhs) << " | ge: " << (lhs >= rhs) << std::endl;
}

void	t() {
	NAMESPACE::set<char> st1;
	NAMESPACE::set<char> st2;

	st1.insert('a');
	st1.insert('b');
	st1.insert('c');
	st1.insert('d');
	st2.insert('a');
	st2.insert('b');
	st2.insert('c');
	st2.insert('d');

	cst(st1, st1); // 0
	cst(st1, st2); // 1

	st2.insert('e');
	st2.insert('f');
	st2.insert('h');
	st2.insert('h');

	cst(st1, st2); // 2
	cst(st2, st1); // 3

	NAMESPACE::swap(st1, st2);

	cst(st1, st2); // 4
	cst(st2, st1); // 5

}

void	set_test() {
	std::cout << "Set Test" << std::endl;
	//set_insert_1();
	t();
	return;
}

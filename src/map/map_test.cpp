#include "map.hpp"
#include "map_test.hpp"
#include <map>
#include <utility>

// TMP
#include <stdlib.h>     /* srand, rand */
#include <time.h>       /* time */
#include <set>

void	pair_relational_operators_output(const NAMESPACE::pair<int, float>& p1, const NAMESPACE::pair<int, float>& p2) {
	std::cout << std::boolalpha;
	std::cout << (p1 == p2) << std::endl;
	std::cout << (p1 != p2) << std::endl;
	std::cout << (p1 < p2) << std::endl;
	std::cout << (p1 <= p2) << std::endl;
	std::cout << (p1 > p2) << std::endl;
	std::cout << (p1 >= p2) << std::endl;
}

void	pair_relational_operators() {
	NAMESPACE::pair<int, float> p1 = NAMESPACE::make_pair(1, 4.6);
	NAMESPACE::pair<int, float> p2 = NAMESPACE::make_pair(5, 3);
	// case_1
	std::cout << "\t=== lhs.first < rhs.first && lhs.second > rhs.second ===" << std::endl;
	pair_relational_operators_output(p1, p2);
	std::cout << "\t=== lhs.first < rhs.first && lhs.second >= rhs.second ===" << std::endl;
	p1 = NAMESPACE::make_pair(1, 3); p2 = NAMESPACE::make_pair(5, 3);
	pair_relational_operators_output(p1, p2);
	std::cout << "\t=== lhs.first < rhs.first && lhs.second < rhs.second ===" << std::endl;
	p1 = NAMESPACE::make_pair(1, 3); p2 = NAMESPACE::make_pair(5, 4);
	pair_relational_operators_output(p1, p2);
	std::cout << "\t=== lhs.first < rhs.first && lhs.second <= rhs.second ===" << std::endl;
	p1 = NAMESPACE::make_pair(1, 4); p2 = NAMESPACE::make_pair(5, 4);
	pair_relational_operators_output(p1, p2);
	std::cout << "\t=== lhs.first < rhs.first && lhs.second == rhs.second ===" << std::endl;
	p1 = NAMESPACE::make_pair(1, 4); p2 = NAMESPACE::make_pair(5, 4);
	pair_relational_operators_output(p1, p2);
	// case_2
	std::cout << "\t=== lhs.first > rhs.first && lhs.second > rhs.second ===" << std::endl;
	p1 = NAMESPACE::make_pair(5, 3.1); p2 = NAMESPACE::make_pair(3, 2);
	pair_relational_operators_output(p1, p2);
	std::cout << "\t=== lhs.first > rhs.first && lhs.second >= rhs.second ===" << std::endl;
	p1 = NAMESPACE::make_pair(5, 2); p2 = NAMESPACE::make_pair(3, 2);
	pair_relational_operators_output(p1, p2);
	std::cout << "\t=== lhs.first > rhs.first && lhs.second < rhs.second ===" << std::endl;
	p1 = NAMESPACE::make_pair(5, 1); p2 = NAMESPACE::make_pair(3, 2);
	pair_relational_operators_output(p1, p2);
	std::cout << "\t=== lhs.first > rhs.first && lhs.second <= rhs.second ===" << std::endl;
	p1 = NAMESPACE::make_pair(5, 2); p2 = NAMESPACE::make_pair(3, 2);
	pair_relational_operators_output(p1, p2);
	std::cout << "\t=== lhs.first > rhs.first && lhs.second == rhs.second ===" << std::endl;
	p1 = NAMESPACE::make_pair(5, 3.1); p2 = NAMESPACE::make_pair(3, 3.1);
	pair_relational_operators_output(p1, p2);
	// case_3
	std::cout << "\t=== lhs.first == rhs.first && lhs.second < rhs.second ===" << std::endl;
	p1 = NAMESPACE::make_pair(5, 1.3); p2 = NAMESPACE::make_pair(5, 3);
	pair_relational_operators_output(p1, p2);
	std::cout << "\t=== lhs.first == rhs.first && lhs.second <= rhs.second ===" << std::endl;
	p1 = NAMESPACE::make_pair(5, 3); p2 = NAMESPACE::make_pair(5, 3);
	pair_relational_operators_output(p1, p2);
	std::cout << "\t=== lhs.first == rhs.first && lhs.second > rhs.second ===" << std::endl;
	p1 = NAMESPACE::make_pair(5, 3); p2 = NAMESPACE::make_pair(5, 2);
	pair_relational_operators_output(p1, p2);
	std::cout << "\t=== lhs.first == rhs.first && lhs.second >= rhs.second ===" << std::endl;
	p1 = NAMESPACE::make_pair(5, 3); p2 = NAMESPACE::make_pair(5, 3);
	pair_relational_operators_output(p1, p2);
	std::cout << "\t===lhs.first == rhs.first && lhs.second > rhs.second ===" << std::endl;
	p1 = NAMESPACE::make_pair(5, 3); p2 = NAMESPACE::make_pair(5, 3);
	pair_relational_operators_output(p1, p2);
}

void	print_after_insert(NAMESPACE::map<int, float>::iterator returnedIterator, NAMESPACE::map<int, float>::iterator begin, NAMESPACE::map<int, float>::iterator end) {
	std::cout << "From returned iterator" << std::endl;
	while (returnedIterator != end)
		std::cout << (returnedIterator++)->first << " ";
	std::cout << std::endl;
	std::cout << "From begin" << std::endl;
	while (begin != end)
		std::cout << (begin++)->first << " ";
	std::cout << std::endl;
}

void	map_insert_1() {
	std::cout << "Map Insert (first proto)" << std::endl;
	{
		std::cout << "\t=== Case_1 ===" << std::endl;
		NAMESPACE::map<int, float> map;
		NAMESPACE::pair<NAMESPACE::map<int, float>::iterator, bool> ret;
		ret = map.insert(NAMESPACE::make_pair(42, 1.02));
		std::cout << std::boolalpha;
		std::cout << "BOOL: " << ret.second << std::endl;
		print_after_insert(ret.first, map.begin(), map.end());
		ret = map.insert(NAMESPACE::make_pair(2, 2.56));
		std::cout << "BOOL: " << ret.second << std::endl;
		print_after_insert(ret.first, map.begin(), map.end());
		ret = map.insert(NAMESPACE::make_pair(9, 2.00));
		std::cout << "BOOL: " << ret.second << std::endl;
		print_after_insert(ret.first, map.begin(), map.end());
		ret = map.insert(NAMESPACE::make_pair(1, 2.70));
		std::cout << "BOOL: " << ret.second << std::endl;
		print_after_insert(ret.first, map.begin(), map.end());
		ret = map.insert(NAMESPACE::make_pair(78, 4.98));
		std::cout << "BOOL: " << ret.second << std::endl;
		print_after_insert(ret.first, map.begin(), map.end());
		std::cout << "\t===" << std::endl;
	}
	{
		std::cout << "\t=== Case_2 ===" << std::endl;
		NAMESPACE::map<int, float> map;
		NAMESPACE::pair<NAMESPACE::map<int, float>::iterator, bool> ret;
		ret = map.insert(NAMESPACE::make_pair(17, 1.02));
		std::cout << "BOOL: " << ret.second << std::endl;
		print_after_insert(ret.first, map.begin(), map.end());
		ret = map.insert(NAMESPACE::make_pair(9, 1.32));
		std::cout << "BOOL: " << ret.second << std::endl;
		print_after_insert(ret.first, map.begin(), map.end());
		ret = map.insert(NAMESPACE::make_pair(19, 1.82));
		std::cout << "BOOL: " << ret.second << std::endl;
		print_after_insert(ret.first, map.begin(), map.end());
		ret = map.insert(NAMESPACE::make_pair(75, 1.92));
		std::cout << "BOOL: " << ret.second << std::endl;
		print_after_insert(ret.first, map.begin(), map.end());
		ret = map.insert(NAMESPACE::make_pair(81, 1.12));
		std::cout << "BOOL: " << ret.second << std::endl;
		print_after_insert(ret.first, map.begin(), map.end());
		std::cout << "\t===" << std::endl;
	}
	{
		std::cout << "\t=== Case_3 ===" << std::endl;
		NAMESPACE::map<int, float> map;
		NAMESPACE::pair<NAMESPACE::map<int, float>::iterator, bool> ret;
		ret = map.insert(NAMESPACE::make_pair(17, 1.02));
		std::cout << "BOOL: " << ret.second << std::endl;
		print_after_insert(ret.first, map.begin(), map.end());ret = map.insert(NAMESPACE::make_pair(9, 1.32));
		ret = map.insert(NAMESPACE::make_pair(19, 1.82));
		std::cout << "BOOL: " << ret.second << std::endl;
		print_after_insert(ret.first, map.begin(), map.end());ret = map.insert(NAMESPACE::make_pair(75, 1.92));
		ret = map.insert(NAMESPACE::make_pair(8, 1.12));
		std::cout << "BOOL: " << ret.second << std::endl;
		print_after_insert(ret.first, map.begin(), map.end());ret = map.insert(NAMESPACE::make_pair(10, 1.12));
		ret = map.insert(NAMESPACE::make_pair(34, 1.12));
		std::cout << "BOOL: " << ret.second << std::endl;
		print_after_insert(ret.first, map.begin(), map.end());ret = map.insert(NAMESPACE::make_pair(67, 1.12));
		ret = map.insert(NAMESPACE::make_pair(46, 1.12));
		std::cout << "BOOL: " << ret.second << std::endl;
		print_after_insert(ret.first, map.begin(), map.end());ret = map.insert(NAMESPACE::make_pair(98, 1.12));
		ret = map.insert(NAMESPACE::make_pair(89, 1.12));
		std::cout << "BOOL: " << ret.second << std::endl;
		print_after_insert(ret.first, map.begin(), map.end());ret = map.insert(NAMESPACE::make_pair(1, 1.12));
		ret = map.insert(NAMESPACE::make_pair(3, 1.12));
		std::cout << "BOOL: " << ret.second << std::endl;
		print_after_insert(ret.first, map.begin(), map.end());ret = map.insert(NAMESPACE::make_pair(80, 1.12));
	}
	{
		std::cout << "\t=== Case_4 ===" << std::endl;
		NAMESPACE::map<int, float> map;
		NAMESPACE::pair<NAMESPACE::map<int, float>::iterator, bool> ret;
		ret = map.insert(NAMESPACE::make_pair(0, 1.02));
		std::cout << "BOOL: " << ret.second << std::endl;
		print_after_insert(ret.first, map.begin(), map.end());
		ret = map.insert(NAMESPACE::make_pair(9, 1.32));
		std::cout << "BOOL: " << ret.second << std::endl;
		print_after_insert(ret.first, map.begin(), map.end());
		ret = map.insert(NAMESPACE::make_pair(-1, 1.02));
		std::cout << "BOOL: " << ret.second << std::endl;
		print_after_insert(ret.first, map.begin(), map.end());
		ret = map.insert(NAMESPACE::make_pair(-2, 1.02));
		std::cout << "BOOL: " << ret.second << std::endl;
		print_after_insert(ret.first, map.begin(), map.end());
		ret = map.insert(NAMESPACE::make_pair(-10, 1.02));
		std::cout << "BOOL: " << ret.second << std::endl;
		print_after_insert(ret.first, map.begin(), map.end());
		ret = map.insert(NAMESPACE::make_pair(-5, 1.02));
		std::cout << "BOOL: " << ret.second << std::endl;
		print_after_insert(ret.first, map.begin(), map.end());
		ret = map.insert(NAMESPACE::make_pair(10, 1.02));
		std::cout << "BOOL: " << ret.second << std::endl;
		print_after_insert(ret.first, map.begin(), map.end());
		ret = map.insert(NAMESPACE::make_pair(8, 1.02));
		std::cout << "BOOL: " << ret.second << std::endl;
		print_after_insert(ret.first, map.begin(), map.end());
		ret = map.insert(NAMESPACE::make_pair(6, 1.02));
		std::cout << "BOOL: " << ret.second << std::endl;
		print_after_insert(ret.first, map.begin(), map.end());
		ret = map.insert(NAMESPACE::make_pair(7, 1.02));
		std::cout << "BOOL: " << ret.second << std::endl;
		print_after_insert(ret.first, map.begin(), map.end());
		ret = map.insert(NAMESPACE::make_pair(9, 1.32));
		std::cout << "BOOL: " << ret.second << std::endl;
		print_after_insert(ret.first, map.begin(), map.end());
	}
}

void	map_case1() {
	NAMESPACE::map<int, float> map;
	map.insert(NAMESPACE::make_pair(42, 1.02));
	map.insert(NAMESPACE::make_pair(2, 2.56));
	map.insert(NAMESPACE::make_pair(9, 2.00));
	map.insert(NAMESPACE::make_pair(1, 2.70));
	map.insert(NAMESPACE::make_pair(78, 4.98));
	std::cout << "Print Map:" << std::endl;
	NAMESPACE::map<int, float>::iterator it = map.begin();
	while (it != map.end()) {
		std::cout << "[" << it->first << "] | [" << it->second << "]" << std::endl;
		it++;
	}
	std::cout << "===" << std::endl;
}

void	map_case2() {
	NAMESPACE::map<int, float> map;
	map.insert(NAMESPACE::make_pair(17, 1.02));
	map.insert(NAMESPACE::make_pair(9, 1.32));
	map.insert(NAMESPACE::make_pair(19, 1.82));
	map.insert(NAMESPACE::make_pair(75, 1.92));
	map.insert(NAMESPACE::make_pair(81, 1.12));
	std::cout << "Print Map:" << std::endl;
	NAMESPACE::map<int, float>::iterator it = map.begin();
	while (it != map.end()) {
		std::cout << "[" << it->first << "] | [" << it->second << "]" << std::endl;
		it++;
	}
	std::cout << "===" << std::endl;
}

void	print_exit(NAMESPACE::map<int, float>& map) {
	//map.print();
	(void)map;
	exit(0);
}

void	map_case3() {
	NAMESPACE::map<int, float> map;
	map.insert(NAMESPACE::make_pair(17, 1.02));
	map.insert(NAMESPACE::make_pair(9, 1.32));
	map.insert(NAMESPACE::make_pair(19, 1.82));
	map.insert(NAMESPACE::make_pair(75, 1.92));
	map.insert(NAMESPACE::make_pair(8, 1.12));
	map.insert(NAMESPACE::make_pair(10, 1.12));
	map.insert(NAMESPACE::make_pair(34, 1.12));
	map.insert(NAMESPACE::make_pair(67, 1.12));
	map.insert(NAMESPACE::make_pair(46, 1.12));
	map.insert(NAMESPACE::make_pair(98, 1.12));
	map.insert(NAMESPACE::make_pair(89, 1.12));
	map.insert(NAMESPACE::make_pair(1, 1.12));
	map.insert(NAMESPACE::make_pair(3, 1.12));
	map.insert(NAMESPACE::make_pair(80, 1.12));
	std::cout << "Print Map:" << std::endl;
	NAMESPACE::map<int, float>::iterator it = map.begin();
	while (it != map.end()) {
		std::cout << "[" << it->first << "] | [" << it->second << "]" << std::endl;
		it++;
	}
	std::cout << "===" << std::endl;
}

void	map_case4() {
	NAMESPACE::map<int, float> map;
	map.insert(NAMESPACE::make_pair(0, 1.02));
	map.insert(NAMESPACE::make_pair(-1, 1.02));
	map.insert(NAMESPACE::make_pair(-2, 1.02));
	map.insert(NAMESPACE::make_pair(-10, 1.02));
	map.insert(NAMESPACE::make_pair(-5, 1.02));
	map.insert(NAMESPACE::make_pair(10, 1.02));
	map.insert(NAMESPACE::make_pair(9, 1.02));
	map.insert(NAMESPACE::make_pair(8, 1.02));
	map.insert(NAMESPACE::make_pair(6, 1.02));
	map.insert(NAMESPACE::make_pair(7, 1.02));
	map.erase(6);
	// map.print();
	std::cout << "Print Map:" << std::endl;
	NAMESPACE::map<int, float>::iterator it = map.begin();
	while (it != map.end()) {
		std::cout << "[" << it->first << "] | [" << it->second << "]" << std::endl;
		it++;
	}
	std::cout << "===" << std::endl;
}

void	map_case5() {
	NAMESPACE::map<int, float> map;
	for (int i = 0; i < 200; ++i)
		map.insert(NAMESPACE::make_pair(i % 2 == 0 ? i : -i, 1.02));
	if (map.empty()) {
		std::cout << "Empty" << std::endl;
	} else {
		std::cout << "Size: " << map.size() << std::endl;
	}
	std::cout << "Is there the number 100 : " << map.count(100) << std::endl;

	std::cout << "Print Map:" << std::endl;
	NAMESPACE::map<int, float>::iterator it = map.begin();
	while (it != map.end()) {
		std::cout << "[" << it->first << "] | [" << it->second << "]" << std::endl;
		it++;
	}
	std::cout << "===" << std::endl;
}

void	map_test() {
	std::cout << "map Test" << std::endl;
	//pair_relational_operators();
	map_insert_1();
	//map_case1();
	//map_case2();
	//map_case3();
	//map_case4();
	//map_case5();
	return;
}

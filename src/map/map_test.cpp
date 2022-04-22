#include "map.hpp"
#include "map_test.hpp"
#include <map>
#include <utility>
#include "../vector/vector.hpp"
#include <vector>

// TMP
#include <stdlib.h>     /* srand, rand */
#include <time.h>       /* time */
#include <set>

#define MAP_BIG_N	10000

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

void	map_constructor() {
	std::cout << "Test Constructor" << std::endl;
	NAMESPACE::map<int, float> map;
	map.insert(NAMESPACE::make_pair(3, 2.02));
	map.insert(NAMESPACE::make_pair(2, 1.29));
	map.insert(NAMESPACE::make_pair(9, 1.89));
	map.insert(NAMESPACE::make_pair(0, 1.90));
	{
		std::cout << "\t=== Construct by range ===" << std::endl;
		NAMESPACE::map<int, float> map2(map.begin(), map.end());
		NAMESPACE::map<int, float>::iterator it = map2.begin();
		while (it != map2.end())
			std::cout << (it++)->first << " ";
		std::cout << std::endl;
		std::cout << map2.empty() << std::endl;
		std::cout << map2.size() << std::endl;
		std::cout << map2.max_size() << std::endl;
	}
	{
		std::cout << "\t=== Construct by range (not full) ===" << std::endl;
		NAMESPACE::map<int, float>::iterator begin = map.begin(); begin++;
		NAMESPACE::map<int, float>::iterator end = map.end(); end--;
		NAMESPACE::map<int, float> map2(begin, end);
		NAMESPACE::map<int, float>::iterator it = map2.begin();
		while (it != map2.end())
			std::cout << (it++)->first << " ";
		std::cout << std::endl;
		std::cout << map2.empty() << std::endl;
		std::cout << map2.size() << std::endl;
		std::cout << map2.max_size() << std::endl;
	}
	{
		std::cout << "\t=== Construct Copy ===" << std::endl;
		NAMESPACE::map<int, float> map2(map);
		NAMESPACE::map<int, float>::iterator it = map2.begin();
		while (it != map2.end())
			std::cout << (it++)->first << " ";
		std::cout << std::endl;
		std::cout << map2.empty() << std::endl;
		std::cout << map2.size() << std::endl;
		std::cout << map2.max_size() << std::endl;
	}
	{
		std::cout << "\t=== Construct Copy (empty map)===" << std::endl;
		NAMESPACE::map<int, float> emptyMap;
		NAMESPACE::map<int, float> map2(emptyMap);
		NAMESPACE::map<int, float>::iterator it = map2.begin();
		while (it != map2.end())
			std::cout << (it++)->first << " ";
		std::cout << std::endl;
		std::cout << map2.empty() << std::endl;
		std::cout << map2.size() << std::endl;
		std::cout << map2.max_size() << std::endl;
	}
	{
		std::cout << "\t=== Operator= ===" << std::endl;
		NAMESPACE::map<int, float> map2;
		map2 = map;
		NAMESPACE::map<int, float>::iterator it = map2.begin();
		while (it != map2.end())
			std::cout << (it++)->first << " ";
		std::cout << std::endl;
		std::cout << map2.empty() << std::endl;
		std::cout << map2.size() << std::endl;
		std::cout << map2.max_size() << std::endl;
	}
	{
		std::cout << "\t=== Operator= (Big copy) ===" << std::endl;
		NAMESPACE::map<int, float> big_map;
		for (int i = 0; i < 100000; i++)
			map.insert(NAMESPACE::make_pair((i % 2 == 0 ? i : -i), 1.02));
		NAMESPACE::map<int, float> map2;
		map2 = big_map;
		NAMESPACE::map<int, float>::iterator it = map2.begin();
		while (it != map2.end())
			std::cout << (it++)->first << " ";
		std::cout << std::endl;
		std::cout << map2.empty() << std::endl;
		std::cout << map2.size() << std::endl;
		std::cout << map2.max_size() << std::endl;
		std::cout << "\t=== Operator= from empty map ===" << std::endl;
		NAMESPACE::map<int, float> empty_map;
		map2 = empty_map;
		it = map2.begin();
		while (it != map2.end())
			std::cout << (it++)->first << " ";
		std::cout << std::endl;
		std::cout << map2.empty() << std::endl;
		std::cout << map2.size() << std::endl;
		std::cout << map2.max_size() << std::endl;
		//std::cout << "\t=== Operator= on same map ===" << std::endl;
		//map2 = map2;
		//it = map2.begin();
		//while (it != map2.end())
		//	std::cout << (it++)->first << " ";
		//std::cout << std::endl;
		//std::cout << map2.empty() << std::endl;
		//std::cout << map2.size() << std::endl;
		//std::cout << map2.max_size() << std::endl;
	}
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
		NAMESPACE::map<int, float>::iterator begin = map.begin();
		NAMESPACE::map<int, float>::iterator end = map.end();
		ret = map.insert(NAMESPACE::make_pair(42, 1.02));
		std::cout << std::boolalpha;
		std::cout << "BOOL: " << ret.second << std::endl;
		print_after_insert(ret.first, begin, end);
		ret = map.insert(NAMESPACE::make_pair(2, 2.56));
		std::cout << "BOOL: " << ret.second << std::endl;
		print_after_insert(ret.first, begin, end);
		ret = map.insert(NAMESPACE::make_pair(9, 2.00));
		std::cout << "BOOL: " << ret.second << std::endl;
		print_after_insert(ret.first, begin, end);
		ret = map.insert(NAMESPACE::make_pair(1, 2.70));
		std::cout << "BOOL: " << ret.second << std::endl;
		print_after_insert(ret.first, begin, end);
		ret = map.insert(NAMESPACE::make_pair(78, 4.98));
		std::cout << "BOOL: " << ret.second << std::endl;
		print_after_insert(ret.first, begin, end);
		std::cout << "\t===" << std::endl;
	}
	{
		std::cout << "\t=== Case_2 ===" << std::endl;
		NAMESPACE::map<int, float> map;
		NAMESPACE::pair<NAMESPACE::map<int, float>::iterator, bool> ret;
		NAMESPACE::map<int, float>::iterator begin = map.begin();
		NAMESPACE::map<int, float>::iterator end = map.end();
		ret = map.insert(NAMESPACE::make_pair(17, 1.02));
		std::cout << "BOOL: " << ret.second << std::endl;
		print_after_insert(ret.first, begin, end);
		ret = map.insert(NAMESPACE::make_pair(9, 1.32));
		std::cout << "BOOL: " << ret.second << std::endl;
		print_after_insert(ret.first, begin, end);
		ret = map.insert(NAMESPACE::make_pair(19, 1.82));
		std::cout << "BOOL: " << ret.second << std::endl;
		print_after_insert(ret.first, begin, end);
		ret = map.insert(NAMESPACE::make_pair(75, 1.92));
		std::cout << "BOOL: " << ret.second << std::endl;
		print_after_insert(ret.first, begin, end);
		ret = map.insert(NAMESPACE::make_pair(81, 1.12));
		std::cout << "BOOL: " << ret.second << std::endl;
		print_after_insert(ret.first, begin, end);
		std::cout << "\t===" << std::endl;
	}
	{
		std::cout << "\t=== Case_3 ===" << std::endl;
		NAMESPACE::map<int, float> map;
		NAMESPACE::pair<NAMESPACE::map<int, float>::iterator, bool> ret;
		NAMESPACE::map<int, float>::iterator begin = map.begin();
		NAMESPACE::map<int, float>::iterator end = map.end();
		ret = map.insert(NAMESPACE::make_pair(17, 1.02));
		std::cout << "BOOL: " << ret.second << std::endl;
		print_after_insert(ret.first, begin, end);
		ret = map.insert(NAMESPACE::make_pair(9, 1.32));
		std::cout << "BOOL: " << ret.second << std::endl;
		print_after_insert(ret.first, begin, end);
		ret = map.insert(NAMESPACE::make_pair(19, 1.82));
		std::cout << "BOOL: " << ret.second << std::endl;
		print_after_insert(ret.first, begin, end);
		ret = map.insert(NAMESPACE::make_pair(75, 1.92));
		std::cout << "BOOL: " << ret.second << std::endl;
		print_after_insert(ret.first, begin, end);
		ret = map.insert(NAMESPACE::make_pair(8, 1.12));
		std::cout << "BOOL: " << ret.second << std::endl;
		print_after_insert(ret.first, begin, end);
		ret = map.insert(NAMESPACE::make_pair(10, 1.12));
		std::cout << "BOOL: " << ret.second << std::endl;
		print_after_insert(ret.first, begin, end);
		ret = map.insert(NAMESPACE::make_pair(34, 1.12));
		std::cout << "BOOL: " << ret.second << std::endl;
		print_after_insert(ret.first, begin, end);
		ret = map.insert(NAMESPACE::make_pair(67, 1.12));
		std::cout << "BOOL: " << ret.second << std::endl;
		print_after_insert(ret.first, begin, end);
		ret = map.insert(NAMESPACE::make_pair(46, 1.12));
		std::cout << "BOOL: " << ret.second << std::endl;
		print_after_insert(ret.first, begin, end);
		ret = map.insert(NAMESPACE::make_pair(98, 1.12));
		std::cout << "BOOL: " << ret.second << std::endl;
		print_after_insert(ret.first, begin, end);
		ret = map.insert(NAMESPACE::make_pair(89, 1.12));
		std::cout << "BOOL: " << ret.second << std::endl;
		print_after_insert(ret.first, begin, end);
		ret = map.insert(NAMESPACE::make_pair(1, 1.12));
		std::cout << "BOOL: " << ret.second << std::endl;
		print_after_insert(ret.first, begin, end);
		ret = map.insert(NAMESPACE::make_pair(3, 1.12));
		std::cout << "BOOL: " << ret.second << std::endl;
		print_after_insert(ret.first, begin, end);
		ret = map.insert(NAMESPACE::make_pair(80, 1.12));
		std::cout << "BOOL: " << ret.second << std::endl;
		print_after_insert(ret.first, begin, end);
	}
	{
		std::cout << "\t=== Case_4 ===" << std::endl;
		NAMESPACE::map<int, float> map;
		NAMESPACE::pair<NAMESPACE::map<int, float>::iterator, bool> ret;
		NAMESPACE::map<int, float>::iterator begin = map.begin();
		NAMESPACE::map<int, float>::iterator end = map.end();
		ret = map.insert(NAMESPACE::make_pair(0, 1.02));
		std::cout << "BOOL: " << ret.second << std::endl;
		print_after_insert(ret.first, begin, end);
		ret = map.insert(NAMESPACE::make_pair(9, 1.32));
		std::cout << "BOOL: " << ret.second << std::endl;
		print_after_insert(ret.first, begin, end);
		ret = map.insert(NAMESPACE::make_pair(-1, 1.02));
		std::cout << "BOOL: " << ret.second << std::endl;
		print_after_insert(ret.first, begin, end);
		ret = map.insert(NAMESPACE::make_pair(-2, 1.02));
		std::cout << "BOOL: " << ret.second << std::endl;
		print_after_insert(ret.first, begin, end);
		ret = map.insert(NAMESPACE::make_pair(-10, 1.02));
		std::cout << "BOOL: " << ret.second << std::endl;
		print_after_insert(ret.first, begin, end);
		ret = map.insert(NAMESPACE::make_pair(-5, 1.02));
		std::cout << "BOOL: " << ret.second << std::endl;
		print_after_insert(ret.first, begin, end);
		ret = map.insert(NAMESPACE::make_pair(10, 1.02));
		std::cout << "BOOL: " << ret.second << std::endl;
		print_after_insert(ret.first, begin, end);
		ret = map.insert(NAMESPACE::make_pair(8, 1.02));
		std::cout << "BOOL: " << ret.second << std::endl;
		print_after_insert(ret.first, begin, end);
		ret = map.insert(NAMESPACE::make_pair(6, 1.02));
		std::cout << "BOOL: " << ret.second << std::endl;
		print_after_insert(ret.first, begin, end);
		ret = map.insert(NAMESPACE::make_pair(7, 1.02));
		std::cout << "BOOL: " << ret.second << std::endl;
		print_after_insert(ret.first, begin, end);
		ret = map.insert(NAMESPACE::make_pair(9, 1.32));
		std::cout << "BOOL: " << ret.second << std::endl;
		print_after_insert(ret.first, begin, end);
	}
	{
		std::cout << "\t=== Big Insert ===" << std::endl;
		NAMESPACE::map<int, float> map;
		NAMESPACE::pair<NAMESPACE::map<int, float>::iterator, bool> ret;
		NAMESPACE::map<int, float>::iterator begin = map.begin();
		NAMESPACE::map<int, float>::iterator end = map.end();
		for (int i = 0; i < MAP_BIG_N; i++) {
			ret = map.insert(NAMESPACE::make_pair(i % 2 == 0 ? i : -i, 1.02));
		}
		std::cout << ret.second << std::endl;
		print_after_insert(ret.first, begin, end);
	}
	// Add test to check no leaks with empty map.
}

void	map_insert_2() {
	std::cout << "Map Insert (second proto)" << std::endl;
	{
		std::cout << "\t=== Case_1 ===" << std::endl;
		NAMESPACE::map<int, float> map;
		NAMESPACE::map<int, float>::iterator ret = map.begin();
		NAMESPACE::map<int, float>::iterator begin = map.begin();
		NAMESPACE::map<int, float>::iterator end = map.end();
		ret = map.insert(ret, NAMESPACE::make_pair(42, 1.02));
		std::cout << std::boolalpha;
		print_after_insert(ret, begin, end);
		ret = map.insert(ret, NAMESPACE::make_pair(2, 2.56));
		print_after_insert(ret, begin, end);
		ret = map.insert(ret, NAMESPACE::make_pair(9, 2.00));
		print_after_insert(ret, begin, end);
		ret = map.insert(ret, NAMESPACE::make_pair(1, 2.70));
		print_after_insert(ret, begin, end);
		ret = map.insert(ret, NAMESPACE::make_pair(78, 4.98));
		print_after_insert(ret, begin, end);
		std::cout << "\t===" << std::endl;
	}
	{
		std::cout << "\t=== Case_2 ===" << std::endl;
		NAMESPACE::map<int, float> map;
		NAMESPACE::map<int, float>::iterator ret = map.begin();
		NAMESPACE::map<int, float>::iterator begin = map.begin();
		NAMESPACE::map<int, float>::iterator end = map.end();
		ret = map.insert(ret, NAMESPACE::make_pair(17, 1.02));
		print_after_insert(ret, begin, end);
		ret = map.insert(ret, NAMESPACE::make_pair(9, 1.32));
		print_after_insert(ret, begin, end);
		ret = map.insert(ret, NAMESPACE::make_pair(19, 1.82));
		print_after_insert(ret, begin, end);
		ret = map.insert(ret, NAMESPACE::make_pair(75, 1.92));
		print_after_insert(ret, begin, end);
		ret = map.insert(ret, NAMESPACE::make_pair(81, 1.12));
		print_after_insert(ret, begin, end);
		std::cout << "\t===" << std::endl;
	}
	{
		std::cout << "\t=== Case_3 ===" << std::endl;
		NAMESPACE::map<int, float> map;
		NAMESPACE::map<int, float>::iterator ret = map.begin();
		NAMESPACE::map<int, float>::iterator begin = map.begin();
		NAMESPACE::map<int, float>::iterator end = map.end();
		ret = map.insert(ret, NAMESPACE::make_pair(17, 1.02));
		print_after_insert(ret, begin, end);
		ret = map.insert(ret, NAMESPACE::make_pair(9, 1.32));
		print_after_insert(ret, begin, end);
		ret = map.insert(ret, NAMESPACE::make_pair(19, 1.82));
		print_after_insert(ret, begin, end);
		ret = map.insert(ret, NAMESPACE::make_pair(75, 1.92));
		print_after_insert(ret, begin, end);
		ret = map.insert(ret, NAMESPACE::make_pair(8, 1.12));
		print_after_insert(ret, begin, end);
		ret = map.insert(ret, NAMESPACE::make_pair(10, 1.12));
		print_after_insert(ret, begin, end);
		ret = map.insert(ret, NAMESPACE::make_pair(34, 1.12));
		print_after_insert(ret, begin, end);
		ret = map.insert(ret, NAMESPACE::make_pair(67, 1.12));
		print_after_insert(ret, begin, end);
		ret = map.insert(ret, NAMESPACE::make_pair(46, 1.12));
		print_after_insert(ret, begin, end);
		ret = map.insert(ret, NAMESPACE::make_pair(98, 1.12));
		print_after_insert(ret, begin, end);
		ret = map.insert(ret, NAMESPACE::make_pair(89, 1.12));
		print_after_insert(ret, begin, end);
		ret = map.insert(ret, NAMESPACE::make_pair(1, 1.12));
		print_after_insert(ret, begin, end);
		ret = map.insert(ret, NAMESPACE::make_pair(3, 1.12));
		print_after_insert(ret, begin, end);
		ret = map.insert(ret, NAMESPACE::make_pair(80, 1.12));
		print_after_insert(ret, begin, end);
	}
	{
		std::cout << "\t=== Case_4 ===" << std::endl;
		NAMESPACE::map<int, float> map;
		NAMESPACE::map<int, float>::iterator ret = map.begin();
		NAMESPACE::map<int, float>::iterator begin = map.begin();
		NAMESPACE::map<int, float>::iterator end = map.end();
		ret = map.insert(ret, NAMESPACE::make_pair(0, 1.02));
		print_after_insert(ret, begin, end);
		ret = map.insert(ret, NAMESPACE::make_pair(9, 1.32));
		print_after_insert(ret, begin, end);
		ret = map.insert(ret, NAMESPACE::make_pair(-1, 1.02));
		print_after_insert(ret, begin, end);
		ret = map.insert(ret, NAMESPACE::make_pair(-2, 1.02));
		print_after_insert(ret, begin, end);
		ret = map.insert(ret, NAMESPACE::make_pair(-10, 1.02));
		print_after_insert(ret, begin, end);
		ret = map.insert(ret, NAMESPACE::make_pair(-5, 1.02));
		print_after_insert(ret, begin, end);
		ret = map.insert(ret, NAMESPACE::make_pair(10, 1.02));
		print_after_insert(ret, begin, end);
		ret = map.insert(ret, NAMESPACE::make_pair(8, 1.02));
		print_after_insert(ret, begin, end);
		ret = map.insert(ret, NAMESPACE::make_pair(6, 1.02));
		print_after_insert(ret, begin, end);
		ret = map.insert(ret, NAMESPACE::make_pair(7, 1.02));
		print_after_insert(ret, begin, end);
		ret = map.insert(ret, NAMESPACE::make_pair(9, 1.32));
		print_after_insert(ret, begin, end);
	}
	{
		std::cout << "\t=== Big Insert ===" << std::endl;
		NAMESPACE::map<int, float> map;
		NAMESPACE::map<int, float>::iterator ret = map.begin();
		NAMESPACE::map<int, float>::iterator begin = map.begin();
		NAMESPACE::map<int, float>::iterator end = map.end();
		for (int i = 0; i < MAP_BIG_N; i++) {
			ret = map.insert(ret, NAMESPACE::make_pair(i % 2 == 0 ? i : -i, 1.02));
		}
		print_after_insert(ret, begin, end);
	}
}

void	map_insert_3() {
	std::cout << "map_insert_3" << std::endl;
	NAMESPACE::map<int, float> map;
	for (int i = 0; i < 100; i++)
		map.insert(NAMESPACE::make_pair((i + 1) * 2, 1.02));
	NAMESPACE::map<int, float>::iterator begin = map.begin();
	NAMESPACE::map<int, float>::iterator end = map.end();
	{
		NAMESPACE::map<int, float> map2;
		map2.insert(begin, end);
		NAMESPACE::map<int, float>::iterator b = map2.begin();
		while (b != map2.end())
			std::cout << (b++)->first << " ";
		std::cout << std::endl;
	}
	{
		NAMESPACE::map<int, float> map2;
		for (int i = 0; i++ < 15; begin++);
		end--; end--; end--;
		map2.insert(begin, end);
		NAMESPACE::map<int, float>::iterator b = map2.begin();
		while (b != map2.end())
			std::cout << (b++)->first << " ";
		std::cout << std::endl;
	}
	{
		NAMESPACE::map<int, float> map2;
		NAMESPACE::map<int, float>::iterator begin2 = map.begin();
		while (begin2 != end)
			begin2++;
		begin2--;
		map2.insert(begin2, end);
		NAMESPACE::map<int, float>::iterator b = map2.begin();
		while (b != map2.end())
			std::cout << (b++)->first << " ";
		std::cout << std::endl;
		begin2++;
		map2.insert(begin2, end);
		b = map2.begin();
		while (b != map2.end())
			std::cout << (b++)->first << " ";
		std::cout << std::endl;
	}
	{
		NAMESPACE::map<int, float> map2;
		for (int i = 0; i++ < 15; begin++);
		end--; end--; end--;
		NAMESPACE::map<int, float>::const_iterator const_begin = begin;
		NAMESPACE::map<int, float>::const_iterator const_end = end;
		map2.insert(const_begin, const_end);
		NAMESPACE::map<int, float>::iterator b = map2.begin();
		while (b != map2.end())
			std::cout << (b++)->first << " ";
		std::cout << std::endl;
	}
}

void	map_operator_brackets() {
	std::cout << "Operator brackets" << std::endl;
	{
		NAMESPACE::map<int, float> map;
		for (int i = 0; i < 1000; i++)
			map.insert(NAMESPACE::make_pair(i, 1.03));
		std::cout << map[3] << std::endl;
		NAMESPACE::map<int, float>::iterator begin = map.begin();
		while (begin != map.end())
			std::cout << begin->first << " " << (begin++)->second << " ";
		std::cout << std::endl;
		std::cout << map[-1] << std::endl;
		begin = map.begin();
		while (begin != map.end())
			std::cout << begin->first << " " << (begin++)->second << " ";
		std::cout << std::endl;
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

void	map_swap() {
	NAMESPACE::map<int, float> map;
	NAMESPACE::map<int, float> map2;
	for (int i = 0; i < 4; i++)
		map.insert(NAMESPACE::make_pair(i + 1, 1.03 + i));
	//NAMESPACE::map<int, float>::iterator it1 = map.begin();
	//NAMESPACE::map<int, float>::iterator it2 = map2.begin();
	NAMESPACE::map<int, float>::iterator t_it1 = map.begin();
	NAMESPACE::map<int, float>::iterator t_it2 = map2.begin();
	std::cout << "BEFORE SWAP" << std::endl;
	while (t_it1 != map.end())
		std::cout << (t_it1++)->first << " ";
	std::cout << std::endl;
	while (t_it2 != map2.end())
		std::cout << (t_it2++)->first << " ";
	std::cout << std::endl;
	map.swap(map2);
	std::cout << "AFTER SWAP" << std::endl;
	//while (it1 != map2.end())
	//	std::cout << (it1++)->first << " ";
	//std::cout << std::endl;
	//while (it2 != map.end())
	//	std::cout << (it2++)->first << " ";
	//std::cout << std::endl;
	t_it1 = map.begin();
	t_it2 = map2.begin();
	while (t_it1 != map.end())
		std::cout << (t_it1++)->first << " ";
	std::cout << std::endl;
	while (t_it2 != map2.end())
		std::cout << (t_it2++)->first << " ";
	std::cout << std::endl;
	map.insert(NAMESPACE::make_pair(55, 34));
	map2.insert(NAMESPACE::make_pair(55, 34));
	map.swap(map2);
	std::cout << "RE-SWAP" << std::endl;
	t_it1 = map.begin();
	t_it2 = map2.begin();
	while (t_it1 != map.end())
		std::cout << (t_it1++)->first << " ";
	std::cout << std::endl;
	while (t_it2 != map2.end())
		std::cout << (t_it2++)->first << " ";
	std::cout << std::endl;
}

void	map_swap_non_member() {
	NAMESPACE::map<int, float> map;
	NAMESPACE::map<int, float> map2;
	for (int i = 0; i < 4; i++)
		map.insert(NAMESPACE::make_pair(i + 1, 1.03 + i));
	//NAMESPACE::map<int, float>::iterator it1 = map.begin();
	//NAMESPACE::map<int, float>::iterator it2 = map2.begin();
	NAMESPACE::map<int, float>::iterator t_it1 = map.begin();
	NAMESPACE::map<int, float>::iterator t_it2 = map2.begin();
	std::cout << "BEFORE SWAP" << std::endl;
	while (t_it1 != map.end())
		std::cout << (t_it1++)->first << " ";
	std::cout << std::endl;
	while (t_it2 != map2.end())
		std::cout << (t_it2++)->first << " ";
	std::cout << std::endl;
	NAMESPACE::swap(map, map2);
	std::cout << "AFTER SWAP" << std::endl;
	//while (it1 != map2.end())
	//	std::cout << (it1++)->first << " ";
	//std::cout << std::endl;
	//while (it2 != map.end())
	//	std::cout << (it2++)->first << " ";
	//std::cout << std::endl;
	t_it1 = map.begin();
	t_it2 = map2.begin();
	while (t_it1 != map.end())
		std::cout << (t_it1++)->first << " ";
	std::cout << std::endl;
	while (t_it2 != map2.end())
		std::cout << (t_it2++)->first << " ";
	std::cout << std::endl;
	map.insert(NAMESPACE::make_pair(55, 34));
	map2.insert(NAMESPACE::make_pair(55, 34));
	NAMESPACE::swap(map, map2);
	std::cout << "RE-SWAP" << std::endl;
	t_it1 = map.begin();
	t_it2 = map2.begin();
	while (t_it1 != map.end())
		std::cout << (t_it1++)->first << " ";
	std::cout << std::endl;
	while (t_it2 != map2.end())
		std::cout << (t_it2++)->first << " ";
	std::cout << std::endl;
}

void	map_clear() {
	std::cout << "map clear" << std::endl;
	{
		std::cout << "\t=== big clear ===" << std::endl;
		NAMESPACE::map<int, int> map;
		for (int i = 0; i < 100000; i++)
			map.insert(NAMESPACE::make_pair(i, 1));
		map.clear();
		std::cout << map.size() << " " << map.max_size() << " " << map.empty() << std::endl;
		map.clear();
		std::cout << map.size() << " " << map.max_size() << " " << map.empty() << std::endl;
		map.clear();
		std::cout << map.size() << " " << map.max_size() << " " << map.empty() << std::endl;
		map.insert(NAMESPACE::make_pair(4, 8));
		map.insert(NAMESPACE::make_pair(3, 8));
		map.insert(NAMESPACE::make_pair(1, 8));
		NAMESPACE::map<int, int>::iterator it = map.begin();
		while (it != map.end())
			std::cout << (it++)->first << " ";
		std::cout << std::endl;
	}
	{
		std::cout << "\t=== on empty map ===" << std::endl;
		NAMESPACE::map<int, int> map;
		map.clear();
		std::cout << map.size() << " " << map.max_size() << " " << map.empty() << std::endl;
		map.clear();
		std::cout << map.size() << " " << map.max_size() << " " << map.empty() << std::endl;
		map.clear();
		std::cout << map.size() << " " << map.max_size() << " " << map.empty() << std::endl;
		map.insert(NAMESPACE::make_pair(4, 8));
		map.insert(NAMESPACE::make_pair(3, 8));
		map.insert(NAMESPACE::make_pair(1, 8));
		NAMESPACE::map<int, int>::iterator it = map.begin();
		while (it != map.end())
			std::cout << (it++)->first << " ";
		std::cout << std::endl;
	}
}

void	map_key_comp() {
	NAMESPACE::map<int, float> map1;
	map1.insert(NAMESPACE::make_pair(3, 1.02));
	NAMESPACE::map<int, float> map2;
	map2.insert(NAMESPACE::make_pair(2, 1.45));
	NAMESPACE::map<int, float>::key_compare comp = map1.key_comp();
	std::cout << std::boolalpha;
	std::cout << comp(map1.begin()->first, map2.begin()->first) << std::endl;
	std::cout << comp(map1.begin()->first, map1.begin()->first) << std::endl;
}

void	map_value_comp() {
	NAMESPACE::map<int, int> map;
	for (int i = 0; i < 10; i++)
		map.insert(NAMESPACE::make_pair(i * 2, i));
	NAMESPACE::map<int, int>::iterator it = map.begin();
	NAMESPACE::pair<int, int> last_elem = *(--map.end());
	while (map.value_comp()(*it++, last_elem))
		std::cout << "[" << it->first << ";" << it->second << "] ";
	std::cout << std::endl;
	NAMESPACE::pair<int, int> pair = NAMESPACE::make_pair(42, 24);
	std::cout << std::boolalpha;
	std::cout << map.value_comp()(pair, last_elem) << std::endl;
	std::cout << map.value_comp()(last_elem, pair) << std::endl;
}

void	map_lower_bound() {
	std::cout << "Map lower_bound" << std::endl;
	{
		NAMESPACE::map<int, int> map;
		for (int i = 0; i < 10; i++)
			map.insert(NAMESPACE::make_pair(i * 2, i - 5));
		std::cout << "\tClassic" << std::endl;
		NAMESPACE::map<int, int>::iterator it = map.lower_bound(4);
		while (it != map.end())
			std::cout << "[" << it->first << ";" << (it++)->second << "] ";
		std::cout << std::endl;
		std::cout << "\tClassic (no-existant value)" << std::endl;
		it = map.lower_bound(7);
		while (it != map.end())
			std::cout << "[" << it->first << ";" << (it++)->second << "] ";
		std::cout << std::endl;
		std::cout << "\tk < begin()" << std::endl;
		it = map.lower_bound(-1);
		while (it != map.end())
			std::cout << "[" << it->first << ";" << (it++)->second << "] ";
		std::cout << std::endl;
		std::cout << "\tk == begin" << std::endl;
		it = map.lower_bound(map.begin()->first);
		while (it != map.end())
			std::cout << "[" << it->first << ";" << (it++)->second << "] ";
		std::cout << std::endl;
		std::cout << "\tk == end - 1" << std::endl;
		it = map.lower_bound((--map.end())->first);
		while (it != map.end())
			std::cout << "[" << it->first << ";" << (it++)->second << "] ";
		std::cout << std::endl;
		std::cout << "\tk > end" << std::endl;
		it = map.lower_bound(100);
		while (it != map.end())
			std::cout << "[" << it->first << ";" << (it++)->second << "] ";
		std::cout << std::endl;
		// This test is non-sense because:
		// This element acts as a placeholder; attempting to access it results in undefined behavior.
		//std::cout << "\tk == end()" << std::endl;
		//it = map.lower_bound(map.end()->first);
		//std::cout << map.end()->first << std::endl;
		//while (it != map.end())
		//	std::cout << "[" << it->first << ";" << (it++)->second << "] ";
		//std::cout << std::endl;
	}
	{
		NAMESPACE::map<int, int> map;
		std::cout << "\tClassic" << std::endl;
		NAMESPACE::map<int, int>::iterator it = map.lower_bound(4);
		while (it != map.end())
			std::cout << "[" << it->first << ";" << (it++)->second << "] ";
		std::cout << std::endl;
		std::cout << "\tClassic (no-existant value)" << std::endl;
		it = map.lower_bound(7);
		while (it != map.end())
			std::cout << "[" << it->first << ";" << (it++)->second << "] ";
		std::cout << std::endl;
		std::cout << "\tk < begin()" << std::endl;
		it = map.lower_bound(-1);
		while (it != map.end())
			std::cout << "[" << it->first << ";" << (it++)->second << "] ";
		std::cout << std::endl;
		std::cout << "\tk == begin" << std::endl;
		it = map.lower_bound(map.begin()->first);
		while (it != map.end())
			std::cout << "[" << it->first << ";" << (it++)->second << "] ";
		std::cout << std::endl;
		std::cout << "\tk > end" << std::endl;
		it = map.lower_bound(100);
		while (it != map.end())
			std::cout << "[" << it->first << ";" << (it++)->second << "] ";
		std::cout << std::endl;
	}
}

void	map_lower_bound_const() {
	std::cout << "Map lower_bound Const" << std::endl;
	{
		NAMESPACE::map<int, int> map;
		for (int i = 0; i < 10; i++)
			map.insert(NAMESPACE::make_pair(i * 2, i - 5));
		std::cout << "\tClassic" << std::endl;
		NAMESPACE::map<int, int>::const_iterator it = map.lower_bound(4);
		while (it != map.end())
			std::cout << "[" << it->first << ";" << (it++)->second << "] ";
		std::cout << std::endl;
		std::cout << "\tClassic (no-existant value)" << std::endl;
		it = map.lower_bound(7);
		while (it != map.end())
			std::cout << "[" << it->first << ";" << (it++)->second << "] ";
		std::cout << std::endl;
		std::cout << "\tk < begin()" << std::endl;
		it = map.lower_bound(-1);
		while (it != map.end())
			std::cout << "[" << it->first << ";" << (it++)->second << "] ";
		std::cout << std::endl;
		std::cout << "\tk == begin" << std::endl;
		it = map.lower_bound(map.begin()->first);
		while (it != map.end())
			std::cout << "[" << it->first << ";" << (it++)->second << "] ";
		std::cout << std::endl;
		std::cout << "\tk == end - 1" << std::endl;
		it = map.lower_bound((--map.end())->first);
		while (it != map.end())
			std::cout << "[" << it->first << ";" << (it++)->second << "] ";
		std::cout << std::endl;
		std::cout << "\tk > end" << std::endl;
		it = map.lower_bound(100);
		while (it != map.end())
			std::cout << "[" << it->first << ";" << (it++)->second << "] ";
		std::cout << std::endl;
		// This test is non-sense because:
		// This element acts as a placeholder; attempting to access it results in undefined behavior.
		//std::cout << "\tk == end()" << std::endl;
		//it = map.lower_bound(map.end()->first);
		//std::cout << map.end()->first << std::endl;
		//while (it != map.end())
		//	std::cout << "[" << it->first << ";" << (it++)->second << "] ";
		//std::cout << std::endl;
	}
	{
		NAMESPACE::map<int, int> map;
		std::cout << "\tClassic" << std::endl;
		NAMESPACE::map<int, int>::const_iterator it = map.lower_bound(4);
		while (it != map.end())
			std::cout << "[" << it->first << ";" << (it++)->second << "] ";
		std::cout << std::endl;
		std::cout << "\tClassic (no-existant value)" << std::endl;
		it = map.lower_bound(7);
		while (it != map.end())
			std::cout << "[" << it->first << ";" << (it++)->second << "] ";
		std::cout << std::endl;
		std::cout << "\tk < begin()" << std::endl;
		it = map.lower_bound(-1);
		while (it != map.end())
			std::cout << "[" << it->first << ";" << (it++)->second << "] ";
		std::cout << std::endl;
		std::cout << "\tk == begin" << std::endl;
		it = map.lower_bound(map.begin()->first);
		while (it != map.end())
			std::cout << "[" << it->first << ";" << (it++)->second << "] ";
		std::cout << std::endl;
		std::cout << "\tk > end" << std::endl;
		it = map.lower_bound(100);
		while (it != map.end())
			std::cout << "[" << it->first << ";" << (it++)->second << "] ";
		std::cout << std::endl;
	}
}

void	map_upper_bound() {
	std::cout << "Map upper_bound" << std::endl;
	{
		NAMESPACE::map<int, int> map;
		for (int i = 0; i < 10; i++)
			map.insert(NAMESPACE::make_pair(i * 2, i - 5));
		std::cout << "\tClassic" << std::endl;
		NAMESPACE::map<int, int>::iterator it = map.lower_bound(4);
		while (it != map.end())
			std::cout << "[" << it->first << ";" << (it++)->second << "] ";
		std::cout << std::endl;
		std::cout << "\tClassic (no-existant value)" << std::endl;
		it = map.upper_bound(7);
		while (it != map.end())
			std::cout << "[" << it->first << ";" << (it++)->second << "] ";
		std::cout << std::endl;
		std::cout << "\tk < begin()" << std::endl;
		it = map.upper_bound(-1);
		while (it != map.end())
			std::cout << "[" << it->first << ";" << (it++)->second << "] ";
		std::cout << std::endl;
		std::cout << "\tk == begin" << std::endl;
		it = map.upper_bound(map.begin()->first);
		while (it != map.end())
			std::cout << "[" << it->first << ";" << (it++)->second << "] ";
		std::cout << std::endl;
		std::cout << "\tk == end - 1" << std::endl;
		it = map.upper_bound((--map.end())->first);
		while (it != map.end())
			std::cout << "[" << it->first << ";" << (it++)->second << "] ";
		std::cout << std::endl;
		std::cout << "\tk > end" << std::endl;
		it = map.upper_bound(100);
		while (it != map.end())
			std::cout << "[" << it->first << ";" << (it++)->second << "] ";
		std::cout << std::endl;
		// This test is non-sense because:
		// This element acts as a placeholder; attempting to access it results in undefined behavior.
		//std::cout << "\tk == end()" << std::endl;
		//it = map.lower_bound(map.end()->first);
		//std::cout << map.end()->first << std::endl;
		//while (it != map.end())
		//	std::cout << "[" << it->first << ";" << (it++)->second << "] ";
		//std::cout << std::endl;
	}
	{
		NAMESPACE::map<int, int> map;
		std::cout << "\tClassic" << std::endl;
		NAMESPACE::map<int, int>::iterator it = map.lower_bound(4);
		while (it != map.end())
			std::cout << "[" << it->first << ";" << (it++)->second << "] ";
		std::cout << std::endl;
		// std::cout << "\tClassic (no-existant value)" << std::endl;
		// it = map.upper_bound(7);
		// while (it != map.end())
		// 	std::cout << "[" << it->first << ";" << (it++)->second << "] ";
		// std::cout << std::endl;
		// std::cout << "\tk < begin()" << std::endl;
		// it = map.upper_bound(-1);
		// while (it != map.end())
		// 	std::cout << "[" << it->first << ";" << (it++)->second << "] ";
		// std::cout << std::endl;
		std::cout << "\tk == begin" << std::endl;
		it = map.upper_bound(map.begin()->first);
		while (it != map.end())
			std::cout << "[" << it->first << ";" << (it++)->second << "] ";
		std::cout << std::endl;
		std::cout << "\tk > end" << std::endl;
		it = map.upper_bound(100);
		while (it != map.end())
			std::cout << "[" << it->first << ";" << (it++)->second << "] ";
		std::cout << std::endl;
	}
}

void	map_upper_bound_const() {
	std::cout << "Map upper_bound Const" << std::endl;
	{
		NAMESPACE::map<int, int> map;
		for (int i = 0; i < 10; i++)
			map.insert(NAMESPACE::make_pair(i * 2, i - 5));
		std::cout << "\tClassic" << std::endl;
		NAMESPACE::map<int, int>::const_iterator it = map.lower_bound(4);
		while (it != map.end())
			std::cout << "[" << it->first << ";" << (it++)->second << "] ";
		std::cout << std::endl;
		std::cout << "\tClassic (no-existant value)" << std::endl;
		it = map.upper_bound(7);
		while (it != map.end())
			std::cout << "[" << it->first << ";" << (it++)->second << "] ";
		std::cout << std::endl;
		std::cout << "\tk < begin()" << std::endl;
		it = map.upper_bound(-1);
		while (it != map.end())
			std::cout << "[" << it->first << ";" << (it++)->second << "] ";
		std::cout << std::endl;
		std::cout << "\tk == begin" << std::endl;
		it = map.upper_bound(map.begin()->first);
		while (it != map.end())
			std::cout << "[" << it->first << ";" << (it++)->second << "] ";
		std::cout << std::endl;
		std::cout << "\tk == end - 1" << std::endl;
		it = map.upper_bound((--map.end())->first);
		while (it != map.end())
			std::cout << "[" << it->first << ";" << (it++)->second << "] ";
		std::cout << std::endl;
		std::cout << "\tk > end" << std::endl;
		it = map.upper_bound(100);
		while (it != map.end())
			std::cout << "[" << it->first << ";" << (it++)->second << "] ";
		std::cout << std::endl;
		// This test is non-sense because:
		// This element acts as a placeholder; attempting to access it results in undefined behavior.
		//std::cout << "\tk == end()" << std::endl;
		//it = map.lower_bound(map.end()->first);
		//std::cout << map.end()->first << std::endl;
		//while (it != map.end())
		//	std::cout << "[" << it->first << ";" << (it++)->second << "] ";
		//std::cout << std::endl;
	}
	{
		NAMESPACE::map<int, int> map;
		std::cout << "\tClassic" << std::endl;
		NAMESPACE::map<int, int>::const_iterator it = map.lower_bound(4);
		while (it != map.end())
			std::cout << "[" << it->first << ";" << (it++)->second << "] ";
		std::cout << std::endl;
		std::cout << "\tClassic (no-existant value)" << std::endl;
		it = map.upper_bound(7);
		while (it != map.end())
			std::cout << "[" << it->first << ";" << (it++)->second << "] ";
		std::cout << std::endl;
		std::cout << "\tk < begin()" << std::endl;
		it = map.upper_bound(-1);
		while (it != map.end())
			std::cout << "[" << it->first << ";" << (it++)->second << "] ";
		std::cout << std::endl;
		std::cout << "\tk == begin" << std::endl;
		it = map.upper_bound(map.begin()->first);
		while (it != map.end())
			std::cout << "[" << it->first << ";" << (it++)->second << "] ";
		std::cout << std::endl;
		std::cout << "\tk > end" << std::endl;
		it = map.upper_bound(100);
		while (it != map.end())
			std::cout << "[" << it->first << ";" << (it++)->second << "] ";
		std::cout << std::endl;
	}
}

void	map_get_allocator() {
	ft::map<int, float> map1;
	std::map<int, float> map2;
	if (map1.get_allocator() == map2.get_allocator())
		std::cout << "OK" << std::endl;
	else
		std::cout << "WRONG" << std::endl;
}

void	print_map_relational_operators(NAMESPACE::map<int, int>& map, NAMESPACE::map<int, int>& map2) {
	std::cout << std::boolalpha;
	std::cout << (map == map2) << std::endl;
	std::cout << (map != map2) << std::endl;
	std::cout << (map < map2) << std::endl;
	std::cout << (map <= map2) << std::endl;
	std::cout << (map > map2) << std::endl;
	std::cout << (map >= map2) << std::endl;
}

void	map_relational_operators() {
	std::cout << "Map relational operators" << std::endl;
	NAMESPACE::map<int, int> map;
	for (int i = 1; i < 11; i++)
		map.insert(NAMESPACE::make_pair(i * 3, i * 2));
	{
		std::cout << "\t=== Same size ===" << std::endl;
		NAMESPACE::map<int, int> map2;
		for (int i = 1; i < 11; i++)
			map2.insert(NAMESPACE::make_pair(i * 4, i * 5));
		print_map_relational_operators(map, map2);
	}
	{
		std::cout << "\t=== map.size() > map2.size() ===" << std::endl;
		NAMESPACE::map<int, int> map2;
		for (int i = 1; i < 8; i++)
			map2.insert(NAMESPACE::make_pair(i * 4, i * 5));
		print_map_relational_operators(map, map2);
	}
	{
		std::cout << "\t=== map.size() < map2.size() ===" << std::endl;
		NAMESPACE::map<int, int> map2;
		for (int i = 1; i < 24; i++)
			map2.insert(NAMESPACE::make_pair(i * 4, i * 5));
		print_map_relational_operators(map, map2);
	}
}

void	map_erase() {
	std::cout << "Map.erase()" << std::endl;
	NAMESPACE::map<int, int> map;
	// std::cout << "\t=== Empty map ===" << std::endl;
	// map.erase(map.begin(), map.end());
	// std::cout << map.erase(map.erase(10)) << std::endl;
	// map.erase(map.begin());
	std::cout << "\t=== erase(const key_type& k) ===" << std::endl;
	for (int i = 0; i < 1000; ++i)
		map.insert(NAMESPACE::make_pair<int, int>(i % 3 == 0 ? i : -i, 1));
	for (int i = -200; i < 200; ++i)
		map.erase(i);
	for (NAMESPACE::map<int, int>::iterator it = map.begin(); it != map.end(); ++it)
		std::cout << it->first << std::endl;
	std::cout << "\t=== erase(iterator first) ===" << std::endl;
	// for (int i = -1000; i < -600; ++i)
	// 	map.erase(map.find(i));
	// for (NAMESPACE::map<int, int>::iterator it = map.begin(); it != map.end(); ++it)
	// 	std::cout << it->first << std::endl;
	std::cout << "\t=== erase(iterator first, iterator last) ===" << std::endl;
	// map.erase(map.begin(), map.end());
	// for (NAMESPACE::map<int, int>::iterator it = map.begin(); it != map.end(); ++it)
	// 	std::cout << it->first << std::endl;
}

void	map_test() {
	std::cout << "map Test" << std::endl;
	// pair_relational_operators();
	// map_constructor();
	// map_insert_1();
	// map_insert_2();
	// map_insert_3();
	// map_operator_brackets();
	// map_swap();
	// map_swap_non_member();
	// map_clear();
	// map_key_comp();
	// map_value_comp();
	// map_lower_bound();
	// map_lower_bound_const();
	// map_upper_bound();
	// map_upper_bound_const();
	// map_get_allocator();
	// map_relational_operators();
	// map_case1();
	// map_case2();
	// map_case3();
	// map_case4();
	// map_case5();
	// map_iterator();
	// map_const_iterator();
	map_reverse_iterator();
	// map_erase();
	return;
}

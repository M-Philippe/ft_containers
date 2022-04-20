#include "map_test.hpp"
#include "map.hpp"
#include <map>

void	print_iterator(NAMESPACE::map<int, int>::iterator it, NAMESPACE::map<int, int>::iterator end) {
	while (it != end)
		std::cout << "[" << it->first << ";" << it++->second << "] ";
	std::cout << std::endl;
}

void	print_iterator(NAMESPACE::map<int, int>::const_iterator it, NAMESPACE::map<int, int>::iterator end) {
	while (it != end)
		std::cout << "[" << it->first << ";" << it++->second << "] ";
	std::cout << std::endl;
}

void	map_iterator() {
	std::cout << "Map Iterator" << std::endl;
	std::cout << std::boolalpha;
	NAMESPACE::map<int, int> map;
	for (int i = 1; i < 11; i++)
		map.insert(NAMESPACE::make_pair(i * 2, i));
	{
		std::cout << "=== Default Constructible ===" << std::endl;
		NAMESPACE::map<int, int>::iterator it;
		(void)it;
	}
	{
		std::cout << "=== Copy-constructible ===" << std::endl;
		NAMESPACE::map<int, int>::iterator begin = map.begin();
		begin++; begin++;
		NAMESPACE::map<int, int>::iterator it(begin);
		print_iterator(it, map.end());
	}
	{
		std::cout << "=== Operator= ===" << std::endl;
		NAMESPACE::map<int, int>::iterator begin = map.begin();
		begin++; begin++;
		NAMESPACE::map<int, int>::iterator it(begin);
		print_iterator(it, map.end());
		begin++; begin++;
		it = begin;
		print_iterator(it, map.end());
	}
	{
		std::cout << "=== equality/inequality operators ===" << std::endl;
		NAMESPACE::map<int, int>::iterator end = map.end();
		end--; end--;
		NAMESPACE::map<int, int>::iterator it(map.begin());
		while (it != end)
			std::cout << "[" << it->first << ";" << it++->second << "] ";
		std::cout << std::endl;
		std::cout << (it == end) << std::endl;
		std::cout << (it != end) << std::endl;
		end++;
		std::cout << (end == it) << std::endl;
		std::cout << (end != it) << std::endl;
	}
	{
		std::cout << "=== Operator* ===" << std::endl;
		NAMESPACE::map<int, int>::iterator it = map.begin();
		NAMESPACE::pair<int, int> pair = *it;
		std::cout << "[" << pair.first << ";" << pair.second << "] " << std::endl;
		pair.first = -5;
		pair.second = -1;
		std::cout << "[" << pair.first << ";" << pair.second << "] " << std::endl;
		// doesn't compile for both.
		//*it = pair;
		print_iterator(it, map.end());
	}
	{
		std::cout << "=== Operator-> ===" << std::endl;
		NAMESPACE::map<int, int>::iterator it = map.begin();
		it++; it++;
		std::cout << "[" << it->first << ";" << it->second << "] " << std::endl;
		it->second = 8;
		print_iterator(it, map.end());
		it->second = 3;
		print_iterator(it, map.end());
	}
	{
		std::cout << "=== mutable ===" << std::endl;
		NAMESPACE::map<int, int>::iterator it = map.begin();
		it++;
		NAMESPACE::map<int, int>::iterator it2 = map.end();
		it2--; it2--; it2--;
		//*it = NAMESPACE::make_pair(3, 3);
	}
	{
		std::cout << "=== pre/post-increment operator ===" << std::endl;
		NAMESPACE::map<int, int>::iterator it1 = map.begin();
		NAMESPACE::map<int, int>::iterator it2 = map.begin();
		it1++;
		it2++;
		print_iterator(it1, map.end());
		print_iterator(it2, map.end());
		std::cout << (it1 == it2) << " | " << (it1 != it2) << std::endl;
		++it1;
		++it2;
		print_iterator(it1, map.end());
		print_iterator(it2, map.end());
		std::cout << (it1 == it2) << " | " << (it1 != it2) << std::endl;
		*it1++;
		*it2++;
		print_iterator(it1, map.end());
		print_iterator(it2, map.end());
		std::cout << (it1 == it2) << " | " << (it1 != it2) << std::endl;
	}
	{
		std::cout << "=== pre/post-decrement operator ===" << std::endl;
		NAMESPACE::map<int, int>::iterator it1 = map.end();
		NAMESPACE::map<int, int>::iterator it2 = map.end();
		it1--;
		it2--;
		print_iterator(it1, map.end());
		print_iterator(it2, map.end());
		std::cout << (it1 == it2) << " | " << (it1 != it2) << std::endl;
		--it1;
		--it2;
		print_iterator(it1, map.end());
		print_iterator(it2, map.end());
		std::cout << (it1 == it2) << " | " << (it1 != it2) << std::endl;
		*it1--;
		*it2--;
		print_iterator(it1, map.end());
		print_iterator(it2, map.end());
		std::cout << (it1 == it2) << " | " << (it1 != it2) << std::endl;
	}
	{
		std::cout << "=== Can be converted to const_iterator ===" << std::endl;
		NAMESPACE::map<int, int>::iterator it = map.begin();
		it++; it++; it++;
		print_iterator(it, map.end());
		NAMESPACE::map<int, int>::const_iterator const_it = it;
		print_iterator(const_it, map.end());
		const_it--;
		const_it--;
		print_iterator(const_it, map.end());
	}
}

void	map_const_iterator() {
	std::cout << "Map const_iterator" << std::endl;
	std::cout << std::boolalpha;
	NAMESPACE::map<int, int> map;
	for (int i = 1; i < 11; i++)
		map.insert(NAMESPACE::make_pair(i * 2, i));
	{
		std::cout << "=== Default Constructible ===" << std::endl;
		NAMESPACE::map<int, int>::const_iterator it;
		(void)it;
	}
	{
		std::cout << "=== Copy-constructible ===" << std::endl;
		NAMESPACE::map<int, int>::const_iterator begin = map.begin();
		begin++; begin++;
		NAMESPACE::map<int, int>::const_iterator it(begin);
		print_iterator(it, map.end());
	}
	{
		std::cout << "=== Operator= ===" << std::endl;
		NAMESPACE::map<int, int>::const_iterator begin = map.begin();
		begin++; begin++;
		NAMESPACE::map<int, int>::const_iterator it(begin);
		print_iterator(it, map.end());
		begin++; begin++;
		it = begin;
		print_iterator(it, map.end());
	}
	{
		std::cout << "=== equality/inequality operators ===" << std::endl;
		NAMESPACE::map<int, int>::const_iterator end = map.end();
		end--; end--;
		NAMESPACE::map<int, int>::const_iterator it(map.begin());
		while (it != end)
			std::cout << "[" << it->first << ";" << it++->second << "] ";
		std::cout << std::endl;
		std::cout << (it == end) << std::endl;
		std::cout << (it != end) << std::endl;
		end++;
		std::cout << (end == it) << std::endl;
		std::cout << (end != it) << std::endl;
	}
	{
		std::cout << "=== Operator* ===" << std::endl;
		NAMESPACE::map<int, int>::const_iterator it = map.begin();
		NAMESPACE::pair<int, int> pair = *it;
		std::cout << "[" << pair.first << ";" << pair.second << "] " << std::endl;
		pair.first = -5;
		pair.second = -1;
		std::cout << "[" << pair.first << ";" << pair.second << "] " << std::endl;
		// doesn't compile for both.
		//*it = pair;
		print_iterator(it, map.end());
	}
	{
		std::cout << "=== Operator-> ===" << std::endl;
		NAMESPACE::map<int, int>::const_iterator it = map.begin();
		it++; it++;
		std::cout << "[" << it->first << ";" << it->second << "] " << std::endl;
		// doesn't compile for const
		//it->second = 8;
		print_iterator(it, map.end());
		//it->second = 3;
		print_iterator(it, map.end());
	}
	{
		std::cout << "=== mutable ===" << std::endl;
		NAMESPACE::map<int, int>::const_iterator it = map.begin();
		it++;
		NAMESPACE::map<int, int>::const_iterator it2 = map.end();
		it2--; it2--; it2--;
		//*it = NAMESPACE::make_pair(3, 3);
	}
	{
		std::cout << "=== pre/post-increment operator ===" << std::endl;
		NAMESPACE::map<int, int>::const_iterator it1 = map.begin();
		NAMESPACE::map<int, int>::const_iterator it2 = map.begin();
		it1++;
		it2++;
		print_iterator(it1, map.end());
		print_iterator(it2, map.end());
		std::cout << (it1 == it2) << " | " << (it1 != it2) << std::endl;
		++it1;
		++it2;
		print_iterator(it1, map.end());
		print_iterator(it2, map.end());
		std::cout << (it1 == it2) << " | " << (it1 != it2) << std::endl;
		*it1++;
		*it2++;
		print_iterator(it1, map.end());
		print_iterator(it2, map.end());
		std::cout << (it1 == it2) << " | " << (it1 != it2) << std::endl;
	}
	{
		std::cout << "=== pre/post-decrement operator ===" << std::endl;
		NAMESPACE::map<int, int>::const_iterator it1 = map.end();
		NAMESPACE::map<int, int>::const_iterator it2 = map.end();
		it1--;
		it2--;
		print_iterator(it1, map.end());
		print_iterator(it2, map.end());
		std::cout << (it1 == it2) << " | " << (it1 != it2) << std::endl;
		--it1;
		--it2;
		print_iterator(it1, map.end());
		print_iterator(it2, map.end());
		std::cout << (it1 == it2) << " | " << (it1 != it2) << std::endl;
		*it1--;
		*it2--;
		print_iterator(it1, map.end());
		print_iterator(it2, map.end());
		std::cout << (it1 == it2) << " | " << (it1 != it2) << std::endl;
	}
	{
		std::cout << "=== Can't be converted to iterator ===" << std::endl;
		NAMESPACE::map<int, int>::const_iterator const_it = map.begin();
		(void)const_it;
		// doesn't compile so ok.
		//NAMESPACE::map<int, int>::iterator it = const_it;
		//print_iterator(it, map.end());
	}
}

#include "map.hpp"
#include "map_test.hpp"
#include <map>
#include <utility>

// TMP
#include <stdlib.h>     /* srand, rand */
#include <time.h>       /* time */
#include <set>

void	map_test() {
	std::cout << "map Test" << std::endl;
	NAMESPACE::pair<std::string, int> p("hihi", 42);
	std::cout << p.first << std::endl;
	std::cout << p.second << std::endl;
	//for (int i = 0; i < 1000000; i++) {
	srand(time(NULL));
	NAMESPACE::map<int, float> map;
	map.insert(NAMESPACE::make_pair(42, 1.02));
	std::cout << "Print Vector:" << std::endl;
	map.insert(NAMESPACE::make_pair(2, 2.56));
	map.insert(NAMESPACE::make_pair(9, 2.00));
	map.insert(NAMESPACE::make_pair(1, 2.70));
	map.insert(NAMESPACE::make_pair(78, 4.98));
	#ifdef STD_TEST
		//for (int i = 0; i < 10000; i++)
		//	map.insert(std::make_pair(rand() % 1000 + 1, 0.1));
		std::map<int, float>::iterator it = map.begin();
		//while (it != map.end())
		//	std::cout << "[" << it->first << "] : " << it++->second << std::endl;
		map.insert(NAMESPACE::make_pair(9, 2.00));
		map.insert(NAMESPACE::make_pair(1, 2.70));
		map.insert(NAMESPACE::make_pair(2, 2.56));
		map.insert(NAMESPACE::make_pair(78, 4.98));
		it = map.begin();
		while (it != map.end())
			std::cout << "(std)[" << it->first << "] : " << it++->second << std::endl;
	#else
		map.print();
	#endif
	//}
	//std::cout << "\tSize: " << map.size() << std::endl;
	std::cout << "===" << std::endl;
}

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
	//for (int i = 0; i < 1000000; i++) {
	srand(time(NULL));
	NAMESPACE::map<int, float> map;
	map.insert(NAMESPACE::make_pair(42, 1.02));
	map.insert(NAMESPACE::make_pair(2, 2.56));
	map.insert(NAMESPACE::make_pair(9, 2.00));
	map.insert(NAMESPACE::make_pair(1, 2.70));
	map.insert(NAMESPACE::make_pair(78, 4.98));
	std::cout << "Print Vector:" << std::endl;
	NAMESPACE::map<int, float>::iterator it = map.begin();
	while (it != map.end()) {
		std::cout << "[" << it->first << "] | [" << it->second << "]" << std::endl;
		it++;
	}
	//map.print();
	std::cout << "===" << std::endl;
}

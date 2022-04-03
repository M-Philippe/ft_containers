#ifndef MAP_TEST_HPP
# define MAP_TEST_HPP

#include <iostream>

#undef NAMESPACE
#define NAMESPACE ft
#ifdef STD_TEST
	#undef NAMESPACE
	#define NAMESPACE std
#endif
// NAMESPACE::vector<int> foo;

void	map_test();

#endif

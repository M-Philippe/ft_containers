#ifndef SET_TEST_HPP
# define SET_TEST_HPP

#include <iostream>

#undef NAMESPACE
#define NAMESPACE ft
#ifdef STD_TEST
	#undef NAMESPACE
	#define NAMESPACE ft
#endif

void	set_test();

#endif

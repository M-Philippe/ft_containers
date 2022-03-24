#ifndef VECTOR_TEST_HPP
# define VECTOR_TEST_HPP

#include <ctime>
#include "./vector.hpp"
#include <vector>
#include <string.h>

#define NAMESPACE ft
#ifdef STD_TEST
	#undef NAMESPACE
	#define NAMESPACE std
#endif
// NAMESPACE::vector<int> foo;


struct fooStruct {
	std::string	message = "foo";
};

void	printVector(NAMESPACE::vector<int> vector);
void	vector_test();
void	vectorConstIterator();
void	vectorIterator();
void	vectorConstReverseIterator();
void	vectorReverseIterator();

#endif

#ifndef VECTOR_TEST_HPP
# define VECTOR_TEST_HPP

#define NAMESPACE ft
#ifdef STD_TEST
	#undef NAMESPACE
	#define NAMESPACE std
#endif
// NAMESPACE::vector<int> foo;

#include <ctime>
#include "./vector.hpp"
#include <vector>
#include <string.h>

struct fooStruct {
	std::string	message;
};

void	printVector(NAMESPACE::vector<int> vector);
void	vector_test();
void	vectorConstIterator();
void	vectorIterator();
void	vectorConstReverseIterator();
void	vectorReverseIterator();

#endif

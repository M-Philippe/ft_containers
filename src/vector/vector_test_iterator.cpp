#include <ctime>
#include "./vector.hpp"
#include <vector>
#include <string.h>
#include <iostream>
#include "vector_test.hpp"

void	vectorConstIterator() {
	std::cout << "Vector ConstIterator" << std::endl;
	/*
	**	Const:
	**		can't assign like : *it = 5
	*/

	NAMESPACE::vector<int> vector;
	for (unsigned long i = 0; i < 20; i++)
		vector.push_back(i * 2);
	{
		std::cout << "=== Default Constructible ===" << std::endl;
		NAMESPACE::vector<int>::const_iterator it;
		(void)it;
	}
	{
		std::cout << "=== Copy-constructible ===" << std::endl;
		NAMESPACE::vector<int>::const_iterator begin = vector.begin();
		NAMESPACE::vector<int>::const_iterator it(begin + 5);
		std::cout << *it << std::endl;
		// Expression is not assignable
		// *it = 5;
		printVector(vector);
	}
	{
		std::cout << "=== Operator= ===" << std::endl;
		NAMESPACE::vector<int>::const_iterator it;
		it = vector.begin() + 5;
		std::cout << *it << std::endl;
		while (it != vector.end())
			std::cout << *it++ << " ";
		std::cout << std::endl;
	}
	{
		std::cout << "=== Comparison equality/inequality operator ===" << std::endl;
		NAMESPACE::vector<int>::const_iterator a = vector.begin();
		NAMESPACE::vector<int>::const_iterator b = vector.begin() + 2;
		NAMESPACE::vector<int>::iterator c = vector.begin() + 2;
		if (a == b)
			std::cout << "OK" << std::endl;
		else
			std::cout << "FALSE" << std::endl;
		if (a != b)
			std::cout << "OK" << std::endl;
		else
			std::cout << "FALSE" << std::endl;
		int tmp = *b;
		*c = *a;
		if (a == b)
			std::cout << "OK" << std::endl;
		else
			std::cout << "FALSE" << std::endl;
		if (a != b)
			std::cout << "OK" << std::endl;
		else
			std::cout << "FALSE" << std::endl;
		*c = tmp;
		a = a + 2;
		if (a == b)
			std::cout << "OK" << std::endl;
		else
			std::cout << "FALSE" << std::endl;
		if (a != b)
			std::cout << "OK" << std::endl;
		else
			std::cout << "FALSE" << std::endl;
	}
	{
		std::cout << "=== Operator-> ===" << std::endl;
		struct fooStruct foo;
		NAMESPACE::vector<struct fooStruct> v(10, foo);
		NAMESPACE::vector<struct fooStruct>::const_iterator it = v.begin();
		std::cout << it->message << std::endl;
		// Cannot assign with operator -> for both
		//it->message = "fooCHANGED";
		//std::cout << it->message << std::endl;
	}
	{
		std::cout << "=== Increment ===" << std::endl;
		NAMESPACE::vector<int>::const_iterator a = vector.begin();
		std::cout << *a << std::endl;
		for (int i = 0; i < 3; i++)
			a++;
		std::cout << *a << std::endl;
		++a;
		std::cout << *a << std::endl;
		*a++;
		std::cout << *a << std::endl;
		while (a != vector.end())
			std::cout << *a++ << " ";
		std::cout << std::endl;
		NAMESPACE::vector<int>::const_iterator b = vector.begin();
		while (b < vector.end() - 1)
			std::cout << *(++b) << " ";
		std::cout << std::endl;
		b = vector.begin();
		std::cout << *(b++) << std::endl;
		std::cout << *b << std::endl;
		std::cout << *(++b) << std::endl;
		std::cout << *b << std::endl;
	}
	{
		std::cout << "=== Decrement ===" << std::endl;
		NAMESPACE::vector<int>::const_iterator a = vector.end() - 1;
		std::cout << *a << std::endl;
		for (int i = 0; i < 3; i++)
			a--;
		std::cout << *a << std::endl;
		--a;
		std::cout << *a << std::endl;
		*a--;
		std::cout << *a << std::endl;
		while (a != vector.begin())
			std::cout << *a-- << " ";
		std::cout << std::endl;
		NAMESPACE::vector<int>::const_iterator b = vector.end() - 1;
		while (b < vector.begin())
			std::cout << *(--b) << " ";
		std::cout << std::endl;
		b = vector.end() - 1;
		std::cout << *(b--) << std::endl;
		std::cout << *b << std::endl;
		std::cout << *(--b) << std::endl;
		std::cout << *b << std::endl;
	}
	{
		std::cout << "=== Arithmetic Operators + (only works between iterator and int) ===" << std::endl;
		NAMESPACE::vector<int>::const_iterator a = vector.begin();
		std::cout << *(a + 3) << std::endl;
		std::cout << *a << std::endl;
		std::cout << *(a += 4) << std::endl;
		std::cout << *a << std::endl;
		std::cout << *(4 + a) << std::endl;
		std::cout << *a << std::endl;
		printVector(vector);
	}
	{
		std::cout << "=== Arithmetic operators - (between iterator and int, and iterators) ===" << std::endl;
		NAMESPACE::vector<int>::const_iterator a = vector.end() - 1;
		std::cout << *(a - 3) << std::endl;
		std::cout << *a << std::endl;
		std::cout << *(a -= 4) << std::endl;
		std::cout << *a << std::endl;
		a = vector.end() - 1;
		// Substracting two iterators returns difference_type.
		std::cout << "=== Between iterators ===" << std::endl;
		NAMESPACE::vector<int>::const_iterator b = vector.begin() + 4;
		std::cout << *a << std::endl;
		std::cout << *b << std::endl;
		std::cout << (a - b) << std::endl;
		std::cout << *a << std::endl;
		std::cout << *b << std::endl;
		//NAMESPACE::vector<int>::const_iterator c;
		//std::cout << (c - b) << std::endl;
		//std::cout << (b - c) << std::endl;
		//b = vector.begin();
		//std::cout << (c - b) << std::endl;
		//std::cout << (b - c) << std::endl;
	}
	std::cout << "=== Compound assignments were tested ===" << std::endl;
	{
		std::cout << "=== Inequality relational operators (<, >, <= and >=) ===" << std::endl;
		NAMESPACE::vector<int>::const_iterator a = vector.begin();
		NAMESPACE::vector<int>::const_iterator b = vector.end() - 1;
		std::cout << (a < b) << std::endl;
		std::cout << (a <= b) << std::endl;
		std::cout << (a > b) << std::endl;
		std::cout << (a >= b) << std::endl;
		a = vector.end() - 1;
		b = vector.begin();
		std::cout << (a < b) << std::endl;
		std::cout << (a <= b) << std::endl;
		std::cout << (a > b) << std::endl;
		std::cout << (a >= b) << std::endl;
		std::cout << *a << std::endl;
		std::cout << *b << std::endl;
		a = b;
		std::cout << (a < b) << std::endl;
		std::cout << (a <= b) << std::endl;
		std::cout << (a > b) << std::endl;
		std::cout << (a >= b) << std::endl;
		std::cout << *a << std::endl;
		std::cout << *b << std::endl;
		NAMESPACE::vector<int>::const_iterator c;
		std::cout << (c < b) << std::endl;
		std::cout << (c <= b) << std::endl;
		std::cout << (c > b) << std::endl;
		std::cout << (c >= b) << std::endl;
		std::cout << (b < c) << std::endl;
		std::cout << (b <= c) << std::endl;
		std::cout << (b > c) << std::endl;
		std::cout << (b >= c) << std::endl;
	}
	{
		std::cout << "=== Offset dereference operator ===" << std::endl;
		NAMESPACE::vector<int>::const_iterator a = vector.begin();
		std::cout << a[0] << std::endl;
		//std::cout << a[21] << std::endl;
		for (unsigned long i = 0; i < vector.size(); i++)
			std::cout << a[i] << " ";
		std::cout << std::endl;
		NAMESPACE::vector<int>::const_iterator b = vector.begin() + 5;
		a = b;
		std::cout << a[3] << std::endl;
		std::cout << a[-1] << std::endl;
		//std::cout << a[-6] << std::endl;
		// impossible bc const
		// a[0] = 4;
	}
	{
		std::cout << "=== Check that it compiles -> means iterator_traits is implemented ===" << std::endl;
		const int array[10] = {0,1,2,3,4,5,6,7,8,9};
		const int* a = &array[0];
		const int* b = &array[5];
		std::cout << NAMESPACE::distance(a, b) << std::endl;
		while (a != b)
			std::cout << *(a++) << " ";
		std::cout << std::endl;
	}
}

void	vectorIterator() {
	std::cout << "Vector iterator" << std::endl;
	NAMESPACE::vector<int> vector;
	for (unsigned long i = 0; i < 20; i++)
		vector.push_back(i * 2);
	{
		std::cout << "=== Default Constructible ===" << std::endl;
		NAMESPACE::vector<int>::iterator it;
		(void)it;
	}
	{
		std::cout << "=== Copy-constructible ===" << std::endl;
		NAMESPACE::vector<int>::iterator begin = vector.begin();
		NAMESPACE::vector<int>::iterator it(begin + 5);
		std::cout << *it << std::endl;
		*it = 5;
		std::cout << *it << std::endl;
		printVector(vector);
	}
	{
		std::cout << "=== Operator= ===" << std::endl;
		NAMESPACE::vector<int>::iterator it;
		it = vector.begin() + 5;
		std::cout << *it << std::endl;
		while (it != vector.end())
			std::cout << *it++ << " ";
		std::cout << std::endl;
	}
	{
		std::cout << "=== Comparison equality/inequality operator ===" << std::endl;
		NAMESPACE::vector<int>::iterator a = vector.begin();
		NAMESPACE::vector<int>::iterator b = vector.begin() + 2;
		NAMESPACE::vector<int>::iterator c = vector.begin() + 2;
		if (a == b)
			std::cout << "OK" << std::endl;
		else
			std::cout << "FALSE" << std::endl;
		if (a != b)
			std::cout << "OK" << std::endl;
		else
			std::cout << "FALSE" << std::endl;
		int tmp = *b;
		*c = *a;
		if (a == b)
			std::cout << "OK" << std::endl;
		else
			std::cout << "FALSE" << std::endl;
		if (a != b)
			std::cout << "OK" << std::endl;
		else
			std::cout << "FALSE" << std::endl;
		*c = tmp;
		a = a + 2;
		if (a == b)
			std::cout << "OK" << std::endl;
		else
			std::cout << "FALSE" << std::endl;
		if (a != b)
			std::cout << "OK" << std::endl;
		else
			std::cout << "FALSE" << std::endl;
	}
	{
		std::cout << "=== Operator-> ===" << std::endl;
		struct fooStruct foo;
		NAMESPACE::vector<struct fooStruct> v(10, foo);
		NAMESPACE::vector<struct fooStruct>::iterator it = v.begin();
		std::cout << it->message << std::endl;
		it->message = "fooCHANGED";
		std::cout << it->message << std::endl;
	}
	{
		std::cout << "=== Increment ===" << std::endl;
		NAMESPACE::vector<int>::iterator a = vector.begin();
		std::cout << *a << std::endl;
		for (int i = 0; i < 3; i++)
			a++;
		std::cout << *a << std::endl;
		++a;
		std::cout << *a << std::endl;
		*a++;
		std::cout << *a << std::endl;
		while (a != vector.end())
			std::cout << *a++ << " ";
		std::cout << std::endl;
		NAMESPACE::vector<int>::iterator b = vector.begin();
		while (b < vector.end() - 1)
			std::cout << *(++b) << " ";
		std::cout << std::endl;
		b = vector.begin();
		std::cout << *(b++) << std::endl;
		std::cout << *b << std::endl;
		std::cout << *(++b) << std::endl;
		std::cout << *b << std::endl;
	}
	{
		std::cout << "=== Decrement ===" << std::endl;
		NAMESPACE::vector<int>::iterator a = vector.end() - 1;
		std::cout << *a << std::endl;
		for (int i = 0; i < 3; i++)
			a--;
		std::cout << *a << std::endl;
		--a;
		std::cout << *a << std::endl;
		*a--;
		std::cout << *a << std::endl;
		while (a != vector.begin())
			std::cout << *a-- << " ";
		std::cout << std::endl;
		NAMESPACE::vector<int>::iterator b = vector.end() - 1;
		while (b < vector.begin())
			std::cout << *(--b) << " ";
		std::cout << std::endl;
		b = vector.end() - 1;
		std::cout << *(b--) << std::endl;
		std::cout << *b << std::endl;
		std::cout << *(--b) << std::endl;
		std::cout << *b << std::endl;
	}
	{
		std::cout << "=== Arithmetic Operators + (only works between iterator and int) ===" << std::endl;
		NAMESPACE::vector<int>::iterator a = vector.begin();
		std::cout << *(a + 3) << std::endl;
		std::cout << *a << std::endl;
		std::cout << *(a += 4) << std::endl;
		std::cout << *a << std::endl;
		std::cout << *(4 + a) << std::endl;
		std::cout << *a << std::endl;
		printVector(vector);
	}
	{
		std::cout << "=== Arithmetic operators - (between iterator and int, and iterators) ===" << std::endl;
		NAMESPACE::vector<int>::iterator a = vector.end() - 1;
		std::cout << *(a - 3) << std::endl;
		std::cout << *a << std::endl;
		std::cout << *(a -= 4) << std::endl;
		std::cout << *a << std::endl;
		a = vector.end() - 1;
		// Substracting two iterators returns difference_type.
		std::cout << "=== Between iterators ===" << std::endl;
		NAMESPACE::vector<int>::iterator b = vector.begin() + 4;
		std::cout << *a << std::endl;
		std::cout << *b << std::endl;
		std::cout << (a - b) << std::endl;
		std::cout << *a << std::endl;
		std::cout << *b << std::endl;
		/*NAMESPACE::vector<int>::iterator c;
		std::cout << (c - b) << std::endl;
		std::cout << (b - c) << std::endl;
		b = vector.begin();
		std::cout << (c - b) << std::endl;
		std::cout << (b - c) << std::endl;*/
	}
	std::cout << "=== Compound assignments were tested ===" << std::endl;
	{
		std::cout << "=== Inequality relational operators (<, >, <= and >=) ===" << std::endl;
		NAMESPACE::vector<int>::iterator a = vector.begin();
		NAMESPACE::vector<int>::iterator b = vector.end() - 1;
		std::cout << (a < b) << std::endl;
		std::cout << (a <= b) << std::endl;
		std::cout << (a > b) << std::endl;
		std::cout << (a >= b) << std::endl;
		a = vector.end() - 1;
		b = vector.begin();
		std::cout << (a < b) << std::endl;
		std::cout << (a <= b) << std::endl;
		std::cout << (a > b) << std::endl;
		std::cout << (a >= b) << std::endl;
		std::cout << *a << std::endl;
		std::cout << *b << std::endl;
		a = b;
		std::cout << (a < b) << std::endl;
		std::cout << (a <= b) << std::endl;
		std::cout << (a > b) << std::endl;
		std::cout << (a >= b) << std::endl;
		std::cout << *a << std::endl;
		std::cout << *b << std::endl;
		NAMESPACE::vector<int>::iterator c;
		std::cout << (c < b) << std::endl;
		std::cout << (c <= b) << std::endl;
		std::cout << (c > b) << std::endl;
		std::cout << (c >= b) << std::endl;
		std::cout << (b < c) << std::endl;
		std::cout << (b <= c) << std::endl;
		std::cout << (b > c) << std::endl;
		std::cout << (b >= c) << std::endl;
	}
	{
		std::cout << "=== Offset dereference operator ===" << std::endl;
		NAMESPACE::vector<int>::iterator a = vector.begin();
		std::cout << a[0] << std::endl;
		//std::cout << a[21] << std::endl;
		for (unsigned long i = 0; i < vector.size(); i++)
			std::cout << a[i] << " ";
		std::cout << std::endl;
		NAMESPACE::vector<int>::iterator b = vector.begin() + 5;
		a = b;
		std::cout << a[3] << std::endl;
		std::cout << a[-1] << std::endl;
		//std::cout << a[-6] << std::endl;
		a[0] = 4;
		std::cout << *a << std::endl;
		std::cout << *b << std::endl;
	}
	{
		std::cout << "=== Check that iterator can be cast to const_iterator ===" << std::endl;
		NAMESPACE::vector<int>::iterator a = vector.begin();
		NAMESPACE::vector<int>::const_iterator b = vector.begin() + 4;
		std::cout << *a << std::endl;
		std::cout << *b << std::endl;
		b = a;
		// a = b impossible for both
		std::cout << *a << std::endl;
		std::cout << *b << std::endl;
	}
	{
		std::cout << "=== Check that it compiles -> means iterator_traits is implemented ===" << std::endl;
		int array[10] = {0,1,2,3,4,5,6,7,8,9};
		int *a = &array[0];
		int *b = &array[5];
		std::cout << NAMESPACE::distance(a, b) << std::endl;
		while (a != b)
			std::cout << *(a++) << " ";
		std::cout << std::endl;
	}
}

void	vectorConstReverseIterator() {
	std::cout << "Vector ReverseConstIterator" << std::endl;
}

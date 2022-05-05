#include <ctime>
#include "./vector.hpp"
#include <vector>
#include <string.h>
#include <iostream>
#include "vector_test.hpp"
#include <map>

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
		struct fooStruct t;
		struct fooStruct *ac = &t;
		struct fooStruct *bc = &t;
		struct fooStruct arr[2] = {*ac,*bc};
		std::cout << NAMESPACE::distance(ac, bc) << std::endl;
		std::map<int, std::string> m;
		std::map<int, std::string>::iterator ma = m.begin();
		std::map<int, std::string>::iterator mb = m.begin();
		std::cout << NAMESPACE::distance(ma, mb) << std::endl;
		std::cout << std::distance(ma, mb) << std::endl;
	}
	{
		const int test = 42;
    int array[1] = {test};
    int* const a = &array[0];
    int* const b = &array[1];
    std::cout << "DISTANCE: " << NAMESPACE::distance(b, a) << std::endl << std::endl;
	}
}

void	vectorConstReverseIterator() {
	std::cout << "Vector ReverseConstIterator" << std::endl;
	NAMESPACE::vector<int> vector;
	for (unsigned long i = 1; i < 21; i++)
		vector.push_back(i * 2);
	{
		std::cout << "=== Empty creation ===" << std::endl;
		ft::vector<int>::const_reverse_iterator ft_it;
		std::vector<int>::const_reverse_iterator std_it;
	}
	{
		std::cout << "=== Creation from classic iterator ===" << std::endl;
		NAMESPACE::vector<int>::const_iterator it = vector.begin();
		NAMESPACE::vector<int>::const_reverse_iterator r_it(it + 1);
		std::cout << *r_it << std::endl;
		NAMESPACE::vector<int>::const_iterator it_test = r_it.base();
		while (it_test != vector.end())
			std::cout << *(it_test++) << " ";
		std::cout << std::endl;
		NAMESPACE::vector<int>::const_reverse_iterator r_it2(vector.end());
		std::cout << "r_it2: " << *r_it2 << std::endl;
	}
	{
		std::cout << "=== Creation from other const_reverse_iterator ===" << std::endl;
		NAMESPACE::vector<int>::iterator it = vector.begin();
		NAMESPACE::vector<int>::const_reverse_iterator first(it + 1);
		NAMESPACE::vector<int>::const_reverse_iterator second(first);
		std::cout << "base: " << *(first.base()) << " " << *(second.base()) << std::endl;
		std::cout << *first << " " << *second << std::endl;
	}
	{
		std::cout << "=== constRev. Test Operator+ ===" << std::endl;
			//std::list<int> lst;
			//std::list<int>::const_reverse_iterator it(lst.begin());
			//std::list<int>::const_reverse_iterator it2 = it + 4;
		NAMESPACE::vector<int>::const_reverse_iterator it(vector.end());
		std::cout << "end? " << *(it) << std::endl;
		NAMESPACE::vector<int>::const_reverse_iterator it_2 = it + 5;
		std::cout << *it << " | " << *it_2 << std::endl;
	}
	{
		std::cout << "=== constRev. Test Operator++ 'pre and post ===" << std::endl;
		NAMESPACE::vector<int>::const_reverse_iterator it(vector.end());
		NAMESPACE::vector<int>::const_reverse_iterator start(vector.begin() + 1);
		while (it++ != start)
			std::cout << *it << " ";
		std::cout << std::endl;
		NAMESPACE::vector<int>::const_reverse_iterator it_e(vector.end());
		while (++it_e != start)
			std::cout << *it_e << " ";
		std::cout << std::endl;
	}
	NAMESPACE::vector<int>::const_reverse_iterator start(vector.begin() + 1);
	{
		std::cout << "=== constRev. Test Operator += ===" << std::endl;
		NAMESPACE::vector<int>::const_reverse_iterator it(vector.end());
		std::cout << *it << std::endl;
		it += 5;
		std::cout << *it << std::endl;
		while (it++ != start)
			std::cout << *it << " ";
		std::cout << std::endl;
	}
	{
		std::cout << "=== constRev. Test Operator- ===" << std::endl;
		NAMESPACE::vector<int>::const_reverse_iterator it(vector.begin() + 3);
		std::cout << *it << std::endl;
		NAMESPACE::vector<int>::const_reverse_iterator it_e = it - 5;
		std::cout << *it_e << std::endl;
		// while it--;
	}
	NAMESPACE::vector<int>::const_reverse_iterator end(vector.end());
	{
		std::cout << "=== constRev. Test Operator-- ===" << std::endl;
		NAMESPACE::vector<int>::const_reverse_iterator it(vector.begin() + 1);
		std::cout << *it << std::endl;
		while (it-- != end)
			std::cout << *it << " ";
		std::cout << std::endl;
		NAMESPACE::vector<int>::const_reverse_iterator it_e(vector.begin() + 1);
		while (--it_e != end)
			std::cout << *it_e << " ";
		std::cout << std::endl;
	}
	{
		std::cout << "=== constRev. Test Operator -= ===" << std::endl;
		NAMESPACE::vector<int>::const_reverse_iterator it(vector.begin() + 1);
		std::cout << *it << std::endl;
		it -= 5;
		std::cout << *it << std::endl;
		while (it-- != end)
			std::cout << *it << " ";
		std::cout << std::endl;
	}
	{
		std::cout << "=== constRev. Test Operator-> ===" << std::endl;
		struct fooStruct f;
		NAMESPACE::vector<struct fooStruct> vectorStruct(10, f);
		//NAMESPACE::vector<struct fooStruct>::const_reverse_iterator it(vectorStruct.begin() + 1);
		//std::cout << it->message << std::endl;
		// Impossible because const.
		// it->message = "hihi";
	}
	{
		std::cout << "=== constRev. Test Operator[] ===" << std::endl;
		NAMESPACE::vector<int>::const_reverse_iterator it(vector.end());
		std::cout << it[5] << std::endl;
		int i = 19;
		while (i != 0)
			std::cout << it[i--] << " ";
		std::cout << std::endl;
	}
	{
		std::cout << "=== constRev. Test relational Operators ===" << std::endl;
		NAMESPACE::vector<int>::const_reverse_iterator first(vector.begin() + 1);
		NAMESPACE::vector<int>::const_reverse_iterator second(vector.end());
		std::cout << (first == second) << " ";
		std::cout << (first == first) << " ";
		std::cout << (first != second) << " ";
		std::cout << (first != first) << " ";
		std::cout << (first < second) << " ";
		std::cout << (first <= second) << " ";
		std::cout << (first > second) << " ";
		std::cout << (first >= second) << " ";
		std::cout << std::endl;
	}
	{
		std::cout << "=== constRev. non-member operator+ ===" << std::endl;
		NAMESPACE::vector<int>::const_reverse_iterator it(vector.end());
		NAMESPACE::vector<int>::const_reverse_iterator rev_it = it + 5;
		NAMESPACE::vector<int>::const_reverse_iterator rev_it2 = 5 + it;
		std::cout << *rev_it << std::endl;
		std::cout << *rev_it2 << std::endl;
	}
	{
		std::cout << "=== constRev. non-member operator- ===" << std::endl;
		NAMESPACE::vector<int>::const_reverse_iterator it(vector.begin() + 1);
		NAMESPACE::vector<int>::const_reverse_iterator it2(vector.end());
		std::cout << it - it2 << std::endl;
		std::cout << it2 - it << std::endl;
		NAMESPACE::vector<int>::const_reverse_iterator it3(vector.begin() + 2);
		std::cout << it - it3 << std::endl;
		std::cout << it3 - it << std::endl;
		NAMESPACE::vector<int>::const_reverse_iterator it4(vector.begin() + 1);
		std::cout << it - it4 << std::endl;
		std::cout << it4 - it << std::endl;
	}
}

void	vectorReverseIterator() {
	std::cout << "Vector ReverseConstIterator" << std::endl;
	NAMESPACE::vector<int> vector;
	for (unsigned long i = 1; i < 21; i++)
		vector.push_back(i * 2);
	{
		std::cout << "=== Empty creation ===" << std::endl;
		ft::vector<int>::reverse_iterator ft_it;
		std::vector<int>::reverse_iterator std_it;
	}
	{
		std::cout << "=== Creation from classic iterator ===" << std::endl;
		NAMESPACE::vector<int>::iterator it = vector.begin();
		std::cout << *it << std::endl;
		NAMESPACE::vector<int>::reverse_iterator r_it(it + 1);
		std::cout << "r_it: " << *r_it << std::endl;
		NAMESPACE::vector<int>::const_iterator it_test = r_it.base();
		while (it_test != vector.end())
			std::cout << *(it_test++) << " ";
		std::cout << std::endl;
		NAMESPACE::vector<int>::reverse_iterator r_it2 = vector.rbegin();
		std::cout << "r_it2: " << *r_it2 << std::endl;
	}
	{
		std::cout << "=== Creation from other reverse_iterator ===" << std::endl;
		NAMESPACE::vector<int>::iterator it = vector.begin();
		NAMESPACE::vector<int>::reverse_iterator first(it + 1);
		NAMESPACE::vector<int>::reverse_iterator second(first);
		std::cout << "base: " << *(first.base()) << " " << *(second.base()) << std::endl;
		std::cout << *first << " " << *second << std::endl;
	}
	{
		std::cout << "=== revIterator. Test Operator+ ===" << std::endl;
			//std::list<int> lst;
			//std::list<int>::reverse_iterator it(lst.begin());
			//std::list<int>::reverse_iterator it2 = it + 4;
		NAMESPACE::vector<int>::reverse_iterator it(vector.rend());
		it--; it--; it--; it--; it--; it--; it--;
		std::cout << "end? " << *(it) << std::endl;
		NAMESPACE::vector<int>::reverse_iterator it_2 = it + 5;
		std::cout << *it << " | " << *it_2 << std::endl;
	}
	{
		std::cout << "=== revIterator. Test Operator++ 'pre and post ===" << std::endl;
		NAMESPACE::vector<int>::reverse_iterator it(vector.rend());
		NAMESPACE::vector<int>::reverse_iterator start(vector.rbegin());
		while (++start != it)
			std::cout << *start << " ";
		std::cout << std::endl;
		NAMESPACE::vector<int>::reverse_iterator it_e(vector.end());
		while (++it_e != it)
			std::cout << *it_e << " ";
		std::cout << std::endl;
	}
	NAMESPACE::vector<int>::reverse_iterator start(vector.begin() + 1);
	{
		std::cout << "=== revIterator. Test Operator += ===" << std::endl;
		NAMESPACE::vector<int>::reverse_iterator it(vector.end());
		std::cout << *it << std::endl;
		it += 5;
		std::cout << *it << std::endl;
		while (it++ != start)
			std::cout << *it << " ";
		std::cout << std::endl;
	}
	{
		std::cout << "=== iterate ===" << std::endl;
		NAMESPACE::vector<int>::reverse_iterator b = vector.rbegin();
		while (b != vector.rend())
			std::cout << *(b++) << std::endl;
	}
	{
		std::cout << "=== revIterator. Test Operator- ===" << std::endl;
		NAMESPACE::vector<int>::reverse_iterator it(vector.begin() + 3);
		std::cout << *it << std::endl;
		NAMESPACE::vector<int>::reverse_iterator it_e = it - 5;
		std::cout << *it_e << std::endl;
		// while it--;
	}
	NAMESPACE::vector<int>::reverse_iterator end(vector.end());
	{
		std::cout << "=== revIterator. Test Operator-- ===" << std::endl;
		NAMESPACE::vector<int>::reverse_iterator it(vector.begin() + 1);
		std::cout << *it << std::endl;
		while (it-- != end)
			std::cout << *it << " ";
		std::cout << std::endl;
		NAMESPACE::vector<int>::reverse_iterator it_e(vector.begin() + 1);
		while (--it_e != end)
			std::cout << *it_e << " ";
		std::cout << std::endl;
	}
	{
		std::cout << "=== revIterator. Test Operator -= ===" << std::endl;
		NAMESPACE::vector<int>::reverse_iterator it(vector.begin() + 1);
		std::cout << *it << std::endl;
		it -= 5;
		std::cout << *it << std::endl;
		while (it-- != end)
			std::cout << *it << " ";
		std::cout << std::endl;
	}
	{
		std::cout << "=== revIterator. Test Operator-> ===" << std::endl;
		struct fooStruct f;
		NAMESPACE::vector<struct fooStruct> vectorStruct(10, f);
		//NAMESPACE::vector<struct fooStruct>::reverse_iterator it(vectorStruct.begin() + 1);
		//std::cout << it->message << std::endl;
		//it->message = "hihi";
	}
	{
		std::cout << "=== revIterator. Test Operator[] ===" << std::endl;
		NAMESPACE::vector<int>::reverse_iterator it(vector.end());
		std::cout << it[5] << std::endl;
		int i = 19;
		while (i != 0)
			std::cout << it[i--] << " ";
		std::cout << std::endl;
	}
	{
		std::cout << "=== revIterator. Test relational Operators ===" << std::endl;
		NAMESPACE::vector<int>::reverse_iterator first(vector.begin() + 1);
		NAMESPACE::vector<int>::reverse_iterator second(vector.end());
		std::cout << (first == second) << " ";
		std::cout << (first == first) << " ";
		std::cout << (first != second) << " ";
		std::cout << (first != first) << " ";
		std::cout << (first < second) << " ";
		std::cout << (first <= second) << " ";
		std::cout << (first > second) << " ";
		std::cout << (first >= second) << " ";
		std::cout << std::endl;
	}
	{
		std::cout << "=== revIterator. non-member operator+ ===" << std::endl;
		NAMESPACE::vector<int>::reverse_iterator it(vector.end());
		NAMESPACE::vector<int>::reverse_iterator rev_it = it + 5;
		NAMESPACE::vector<int>::reverse_iterator rev_it2 = 5 + it;
		std::cout << *rev_it << std::endl;
		std::cout << *rev_it2 << std::endl;
	}
	{
		std::cout << "=== revIterator. non-member operator- ===" << std::endl;
		NAMESPACE::vector<int>::reverse_iterator it(vector.begin() + 1);
		NAMESPACE::vector<int>::reverse_iterator it2(vector.end());
		std::cout << it - it2 << std::endl;
		std::cout << it2 - it << std::endl;
		NAMESPACE::vector<int>::reverse_iterator it3(vector.begin() + 2);
		std::cout << it - it3 << std::endl;
		std::cout << it3 - it << std::endl;
		NAMESPACE::vector<int>::reverse_iterator it4(vector.begin() + 1);
		std::cout << it - it4 << std::endl;
		std::cout << it4 - it << std::endl;
	}
	{
		std::cout << "=== Trying cast from non-const to const ===" << std::endl;
		NAMESPACE::vector<int>::reverse_iterator it(vector.begin() + 1);
		std::cout << *it << " " << *(it.base()) << std::endl;
		NAMESPACE::vector<int>::const_reverse_iterator it2(it);
		std::cout << *it << " " << *it2 << std::endl;
		NAMESPACE::vector<int>::reverse_iterator it3(it);
		std::cout << *it << " " << *it3 << std::endl;
		// Impossible cast like in doc.
		//NAMESPACE::vector<int>::reverse_iterator it4(it2);
	}
}


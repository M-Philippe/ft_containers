#include <ctime>
#include "./vector.hpp"
#include <vector>
#include <string.h>
#include "vector_test.hpp"

#define MAX_TEST 10000

void	printOk() {
	std::cout << "\033[0;32m" << "V" << "\033[0;37m";
}

void	printError(std::string message) {
	std::cout << "\033[0;31m" << message << "\033[0;37m" << std::endl;
}

void	printVector(NAMESPACE::vector<int> vector) {
	for (unsigned long i = 0; i < vector.size(); i++)
		std::cout << vector[i] << " ";
	std::cout << std::endl;
}

void	simpleCreation() {
	std::cout << "SimpleCreation" << std::endl;
	NAMESPACE::vector<int> NAMESPACE_vct(10, 5);
	std::cout << NAMESPACE_vct.size() << std::endl;
	std::cout << NAMESPACE_vct.max_size() << std::endl;
	std::cout << "\n\t===" << std::endl;
	std::cout << "=== RangeConstructor ===" << std::endl;
	NAMESPACE::vector<int> vector(18, 5);
	for (u_long i = 0; i < vector.size(); i++)
		std::cout << vector[i] << " ";
	std::cout << std::endl;
	NAMESPACE::vector<int> vectorIterator(vector.begin(), vector.end());
	for (u_long i = 0; i < vectorIterator.size(); i++)
		std::cout << vectorIterator[i] << " ";
	NAMESPACE::vector<int> a(5, 10);
	NAMESPACE::vector<int> b(a);
	for (u_long i = 0; i < a.size(); i++) {
		if (a[i] != b[i])
			printError("False");
	}
	a.clear();
	for (u_long i = 0; i < a.size(); i++) {
		std::cout << b[i] << std::endl;
	}
	std::cout << b.size() <<  " " << b.capacity() << " " << b.max_size() << std::endl;
	NAMESPACE::vector<int> empty;
	NAMESPACE::vector<int> empty_copy(empty);
	std::cout << empty.size() << " " << empty.capacity() << std::endl;
	std::cout << "\n===" << std::endl;
}

void	vectorExpansion() {
	std::cout << "VectorExpansion" << std::endl;
	{
		// Default constructor
		std::cout << "=== Default constructor ===" << std::endl;;
		NAMESPACE::vector<int> vector;
    std::cout << vector.capacity() << std::endl;
		for (std::size_t i = 0; i < MAX_TEST; ++i) {
      vector.push_back(i);
			std::cout << vector.size() << " " << vector.capacity() << std::endl;
    }
		printOk();
	}
	{
		// Fill constructor
		std::cout << "\nFill constructor" << std::endl;
		NAMESPACE::vector<int> vector(10, 8);
		std::cout << vector.size() << " " << vector.capacity() << std::endl;
    for (std::size_t i = 0; i < MAX_TEST; ++i) {
      vector.push_back(i);
			std::cout << vector[vector.size() - 1] << " " << vector.capacity() << std::endl;
    }
		printOk();
		printOk();
	}
	std::cout << "\n\t===" << std::endl;
}

void	vectorOperatorEqual() {
	std::cout << "Vector operator=" << std::endl;
	{
		std::cout << "=== _capacity >= rhs.size ===" << std::endl;
    NAMESPACE::vector<int> vector(3, 8);
    NAMESPACE::vector<int> st_vector(3, 4);

    vector = st_vector;
    std::cout << vector.size() << " " << vector.capacity() << std::endl;
    NAMESPACE::vector<int>::iterator it = vector.begin();
    while (it != vector.end()) {
			std::cout << *it;
			it++;
		}
		std::cout << std::endl;
  }
  {
    std::cout << "\n=== _capacity < rhs.size ===" << std::endl;
		NAMESPACE::vector<int> vector(3, 8);
    NAMESPACE::vector<int> st_vector(10, 4);

    vector = st_vector;
    NAMESPACE::vector<int>::iterator it = vector.begin();
    std::cout << vector.size() << " " << vector.capacity() << std::endl;
		while (it != vector.end()) {
			std::cout << *it;
			it++;
		}
		std::cout << std::endl;
  }
	std::cout << "\n\t===" << std::endl;
}

void	vectorIteratorToInc() {
	std::cout << "VectorIterator" << std::endl;
	NAMESPACE::vector<int> NAMESPACE_vector(10, 8);
  std::vector<int> st_vector(10, 8);
  NAMESPACE::vector<int>::iterator NAMESPACE_it = NAMESPACE_vector.begin();
  std::vector<int>::iterator st_it = st_vector.begin();

  {
    std::cout << "Test that iteration is good" << std::endl;
		int i = 0;
    while (st_it != st_vector.end()) {
      (*NAMESPACE_it == *st_it) ? printOk() : printError("\n*NAMESPACE_it != *st_it");
      ++i;
      ++st_it;
    }
  }
  {
    std::cout << "\nTest that iteration stops at it.end()" << std::endl;
		int i = 0;
    while (NAMESPACE_it++ != NAMESPACE_vector.end()) {
      ++i;
    }
		i == 10 ? printOk() : printError("\ni != 10");
  }
	{
		std::cout << "\nOn an empty vector" << std::endl;
		NAMESPACE::vector<int> NAMESPACE_empty_vector;
		std::vector<int> st_empty_vector;
		NAMESPACE::vector<int>::iterator NAMESPACE_it = NAMESPACE_empty_vector.begin();
		std::vector<int>::iterator st_it = st_empty_vector.begin();
		int i = 0;
		while (NAMESPACE_it != NAMESPACE_empty_vector.end()) {
      (*NAMESPACE_it == *st_it) ? printOk() : printError("\n*NAMESPACE_it != *st_it");
		}
		i == 0 ? printOk() : printError("\ni != 0");
	}
	std::cout << "\n\t===" << std::endl;
}

void	vectorResize() {
	std::cout << "VectorResize" << std::endl;
	NAMESPACE::vector<int> vector(10, 8);

	{
		std::cout << "=== Size/max_size/capacity of empty vector ===" << std::endl;
		NAMESPACE::vector<int> empty;
		std::cout << empty.size() << " " << empty.capacity() << " " << empty.max_size() << " " << empty.empty() << std::endl;
	}
	{
		std::cout << vector.empty() << std::endl;
		std::cout << vector.max_size() << std::endl;
	}
	{
		// resize (n < _size)
		std::cout << "\nResize (n < _size)" << std::endl;
    NAMESPACE::vector<int>::iterator first_it = vector.begin();
    vector.resize(5);

		std::cout << vector.size() << std::endl;
		std::cout << vector.capacity() << std::endl;
    /*  Iterator still must be valid a resize */
    NAMESPACE::vector<int>::iterator second_it = vector.begin();
    while (second_it != vector.end()) {
			if (first_it++ == second_it++)
				std::cout << "TRUE" << std::endl;
		}
  }

  {
		// resize (n < _size && n < _capacity)
		std::cout << "\n=== Resize (n > _size && n < _capactity) ===" << std::endl;
    // To increase _capacity from 10 to 20
    vector.push_back(1);
    vector.resize(15);

		std::cout << vector.size() << std::endl;
		std::cout << vector.capacity() << std::endl;
    NAMESPACE::vector<int>::iterator it = vector.begin();
		std::cout << *(it + 12) << std::endl;
	}
	{
		std::cout << "\nresize (n > _size && n > _capacity)" << std::endl;
		// To increase _capacity from 10 to 20
    vector.push_back(1);
    vector.resize(22);
		std::cout << vector.size() << std::endl;
		std::cout << vector.capacity() << std::endl;
    NAMESPACE::vector<int>::iterator it = vector.begin();
		std::cout << *(it + 12) << std::endl;
    for (int i = 0; i < 20; ++i) {
      vector.push_back(i);
			std::cout << vector.capacity() << std::endl;
    }
		printOk();
	}
	std::cout << "\n\t===" << std::endl;
}

void	vectorReserve() {
	std::cout << "VectorReserve" << std::endl;
	NAMESPACE::vector<int> vector(10, 8);

  {
		std::cout << "\n=== n < _capacity ===" << std::endl;
    vector.reserve(5);
		std::cout << vector.size() << " " << vector.capacity() << std::endl;
	}
  {
    std::cout << "\nn == _capacity" << std::endl;
		vector.reserve(10);
		std::cout << vector.size() << " " << vector.capacity() << std::endl;
	}
	{
    std::cout << "\nn > _capacity" << std::endl;
		vector.reserve(15);
		std::cout << vector.size() << " " << vector.capacity() << std::endl;
	}
	{
		std::cout << "\nTest that exception is thrown" << std::endl;
    NAMESPACE::vector<int>::size_type max = vector.max_size();

		std::cout << max << std::endl;
		try {
			vector.reserve(max + 1);
			printError("vector.reserve(NAMESPACE_max + 15) should throw an error");
		} catch (std::exception& e) {
			std::cout << e.what() << std::endl;
		}
	}
	std::cout << "\n\t===" << std::endl;
}

void	vectorOperatorBrackets() {

}

void	vectorAt() {
	std::cout << "VectorAt" << std::endl;
	NAMESPACE::vector<int> vector(10, 8);
  std::vector<int> st_vector(10, 8);

  vector.push_back(100);
	std::cout << vector.at(10) << std::endl;
	try {
		vector.at(11);
		printError("\nNAMESPACE_vector.at(11) should throw an error");
	} catch (std::exception& e) {
		std::cout << e.what() << std::endl;
	}
	{
		std::cout << "\n=== On empty vector ===" << std::endl;
		NAMESPACE::vector<int> empty;
		vector.clear();
		try {
			std::cout << vector.at(0);
			std::cout << "a on empty vector SHOULD THROW AN ERROR" << std::endl;
		} catch (std::exception& e) {
			std::cout << e.what() << std::endl;
		}
		std::cout << vector.size() << std::endl;
	}
	std::cout << "\n\t===" << std::endl;
}


void vectorFrontBack() {
	std::cout << "VectorFrontBack" << std::endl;
	NAMESPACE::vector<int> vector;

	/*
	**	You can call front/back on an empty vector but trying to do stuff if returned reference will segfault, both for NAMESPACE or std
	*/

	vector.push_back(15);
  vector.push_back(40);
  vector.push_back(1);

	std::cout << vector.front() << " " << vector.back() << std::endl;
	vector.back() -= vector.front();
	std::cout << vector.front() << " " << vector.back() << std::endl;

	while (!vector.empty()) {
		vector.clear();
	}
	std::cout << vector.size() << " " << vector.capacity() << " " << vector.front() << " " << vector.back() << std::endl;
	std::cout << "\n\t===" << std::endl;
}

void	vectorPushPopBack() {
	std::cout << "VectorPushPopBack" << std::endl;
	NAMESPACE::vector<int> vector;
	int sum = 0;
  vector.push_back(100);
  vector.push_back(200);
  vector.push_back(300);

  while (!vector.empty())
  {
    sum += vector.back();
    vector.pop_back();
  }
	std::cout << sum << std::endl;
	vector.pop_back();
	vector.pop_back();
	std::cout << vector[0] << std::endl;
	std::cout << "\n\t===" << std::endl;
}

void	vectorErase() {
	std::cout << "VectorErase" << std::endl;
	NAMESPACE::vector<int> vector(7);
		for (unsigned long i = 0; i < vector.size(); i++) {
		vector[i] = i;
	}
	/*{
		std::cout << "\n=== Simple erase ===" << std::endl;
		printVector(vector);
		NAMESPACE::vector<int>::iterator b = vector.begin();
		NAMESPACE::vector<int>::iterator it = vector.erase(b + 2);
		printVector(vector);
		std::cout << "value: " << *it << std::endl;
		std::cout << "size: " << vector.size() << std::endl;
		std::cout << "capacity: " << vector.capacity() << std::endl;
	}*/
	{
		/*	Provoke segfault for both.
		std::cout << "\n=== Erase with end() as input ===" << std::endl;
		NAMESPACE::vector<int>::iterator it = vector.erase(vector.end());
		std::cout << *it << std::endl;
		printVector(vector);*/
	}
	{
		/*std::cout << "\n=== Erase last element ===" << std::endl;
		NAMESPACE::vector<int>::iterator it = vector.end() - 1;
		it = vector.erase(vector.end() - 1);
		std::cout << *it << std::endl;
		if (*it == *(vector.end()))
			std::cout << "TRUE" << std::endl;*/
	}
	{
		/*std::cout << "\n=== Erase while i > 0 ===" << std::endl;
		NAMESPACE::vector<int>:: iterator b = vector.begin();
		for (unsigned long i = vector.size(); i > 0; i = vector.size()) {
			b = vector.erase(b);
			std::cout << *b << std::endl;
			printVector(vector);
		}*/
		/*std::vector<int>::iterator it;
		std::vector<int> v;
		ft::vector<int>::iterator itf;
		ft::vector<int> vf;
		while (it++ < v.end());
		while (itf++ < vf.end());*/
	}
	/*{
		NAMESPACE::vector<int>::iterator it = vector.begin() + 2;
		std::cout << "value_before: " << *it << std::endl;
		NAMESPACE::vector<int>::iterator x = it - 1;
		std::cout << "value_after: " << *it << std::endl;
	}*/
	for (unsigned long i = 10; i < 20; i++)
		vector.push_back(i);
	//std::cout << vector_copy.size() << " " << vector_copy.capacity() << std::endl;
	/*{
		std::cout << "\n=== Erase with range ===" << std::endl;
		NAMESPACE::vector<int> vector_copy(vector);
		NAMESPACE::vector<int>::iterator it = vector_copy.erase(vector_copy.begin() + 4, vector_copy.end() - 2);
		std::cout << "From returned iterator" << std::endl;
		while (it != vector_copy.end()) {
			std::cout << *it << " ";
			it++;
		}
		std::cout << "From begin iterator" << std::endl;
		for (NAMESPACE::vector<int>::iterator it = vector_copy.begin(); it != vector_copy.end(); it++)
			std::cout << *it << " ";
		std::cout << std::endl;
	}
	{
		std::cout << "\n=== Erase with begin and end ===" << std::endl;
		NAMESPACE::vector<int> vector_copy(vector);
		NAMESPACE::vector<int>::iterator it = vector_copy.erase(vector_copy.begin(), vector_copy.end());
		std::cout << "From returned iterator" << std::endl;
		while (it != vector_copy.end()) {
			std::cout << *it << " ";
			it++;
		}
		std::cout << std::endl;
		std::cout << "From begin iterator" << std::endl;
		for (NAMESPACE::vector<int>::iterator it = vector_copy.begin(); it != vector_copy.end(); it++)
			std::cout << *it << " ";
	}
	{
		std::cout << "\n=== Erase with end ===" << std::endl;
		NAMESPACE::vector<int> vector_copy(vector);
		NAMESPACE::vector<int>::iterator it = vector_copy.erase(vector_copy.begin() + 4, vector_copy.end());
		std::cout << "From returned iterator" << std::endl;
		while (it != vector_copy.end()) {
			std::cout << *it << " ";
			it++;
		}
		std::cout << "From begin iterator" << std::endl;
		for (NAMESPACE::vector<int>::iterator it = vector_copy.begin(); it != vector_copy.end(); it++)
			std::cout << *it << " ";
		std::cout << std::endl;
	}*/
	/*{
		std::cout << "\n=== Erase with end - 1 ===" << std::endl;
		NAMESPACE::vector<int> vector_copy(vector);
		NAMESPACE::vector<int>::iterator it = vector_copy.erase(vector_copy.begin() + 4, vector_copy.end() - 1);
		std::cout << "From returned iterator" << std::endl;
		while (it != vector_copy.end()) {
			std::cout << *it << " ";
			it++;
		}
		std::cout << "\nFrom begin iterator" << std::endl;
		for (NAMESPACE::vector<int>::iterator it = vector_copy.begin(); it != vector_copy.end(); it++)
			std::cout << *it << " ";
		std::cout << std::endl;
	}*/
	/*{
		std::cout << "\n=== Erase with start + 3 ===" << std::endl;
		NAMESPACE::vector<int> vector_copy(vector);
		NAMESPACE::vector<int>::iterator it = vector_copy.erase(vector_copy.begin(), vector_copy.begin() + 3);
		std::cout << "From returned iterator" << std::endl;
		while (it != vector_copy.end()) {
			std::cout << *it << " ";
			it++;
		}
		std::cout << "\nFrom begin iterator" << std::endl;
		for (NAMESPACE::vector<int>::iterator it = vector_copy.begin(); it != vector_copy.end(); it++)
			std::cout << *it << " ";
		std::cout << std::endl;
	}*/
	std::cout << "TEST VECTOR" << std::endl;
	NAMESPACE::vector<int> vct;
	for (int i = 0; i < 15; i++)
		vct.push_back(i);
	for (unsigned long i = 0; i < vct.size(); i++)
		std::cout << vct.at(i) << " ";
	NAMESPACE::vector<int>::iterator a = vct.begin() + 1;
	NAMESPACE::vector<int>::iterator b = vct.begin() + 8;
	b - a;
	std::cout << "\nRET: " << (b - a) << std::endl;
	std::cout << std::endl;
}

void	vectorSwap() {
	std::cout << "VectorSwap" << std::endl;

	NAMESPACE::vector<int> vector(3, 100);
	NAMESPACE::vector<int> vector2(5, 200);

	for (u_long i = 0; i < vector.size(); i++)
		std::cout << vector[i] << " ";
	std::cout << std::endl;
	for (u_long i = 0; i < vector2.size(); i++)
		std::cout << vector2[i] << " ";
	std::cout << std::endl;
	std::cout << "AFTER" << std::endl;
	vector.swap(vector2);
	for (u_long i = 0; i < vector.size(); i++)
		std::cout << vector[i] << " ";
	std::cout << std::endl;
	for (u_long i = 0; i < vector2.size(); i++)
		std::cout << vector2[i] << " ";
	std::cout << "\nBACK" << std::endl;
	vector2.swap(vector);
	for (u_long i = 0; i < vector.size(); i++)
		std::cout << vector[i] << " ";
	std::cout << std::endl;
	for (u_long i = 0; i < vector2.size(); i++)
		std::cout << vector2[i] << " ";
	std::cout << "\n=== On empty vector ===" << std::endl;
	NAMESPACE::vector<int> empty;
	empty.swap(vector);
	for (u_long i = 0; i < vector.size(); i++)
		std::cout << vector[i] << " ";
	std::cout << std::endl;
	for (u_long i = 0; i < empty.size(); i++)
		std::cout << empty[i] << " ";
	std::cout << std::endl;
	empty.swap(vector);
	std::cout << "\n=== Swap two empty vector ===" << std::endl;
	std::cout << empty.empty() << std::endl;
	NAMESPACE::vector<int> empty2;
	empty.swap(empty2);
	for (u_long i = 0; i < empty.size(); i++)
		std::cout << empty[i] << " ";
	std::cout << std::endl;
	for (u_long i = 0; i < empty2.size(); i++)
		std::cout << empty2[i] << " ";
	std::cout << std::endl;
	std::cout << "\n\t===" << std::endl;
}

void	vectorClear() {
	std::cout << "VectorClear" << std::endl;
	NAMESPACE::vector<int> vector(1000, 8);
  vector.clear();
	std::cout << vector.size() << " " << vector.capacity() << std::endl;
	std::cout << "\n=== On empty Vector ===" << std::endl;
	NAMESPACE::vector<int> empty;
	empty.clear();
	std::cout << empty.size() << " " << empty.capacity() << std::endl;
	std::cout << "\n\t===" << std::endl;
}

void	vectorGetAllocator() {
	std::cout << "VectorGetAllocator" << std::endl;
	ft::vector<int> vector(10, 8);
	std::vector<int> st_vector(10, 8);
	vector.get_allocator() == st_vector.get_allocator() ? printOk() : printError("\nget_allocation !=");
	std::cout << "\n\t===" << std::endl;
}

void	vector_test() {
	simpleCreation();	//DONE
	vectorExpansion(); //DONE
	vectorOperatorEqual(); //DONE
	//vectorIterator(); // TODO
	vectorResize(); //DONE
	vectorReserve(); //DONE
	//vectorOperatorBrackets();
	vectorAt(); //DONE
	vectorFrontBack(); //DONE
	//vectorAssign(); // TODO
	vectorPushPopBack(); // DONE
	//vectorInsert(); // TODO
	//vectorErase(); // TOFINISH
	vectorSwap(); // DONE
	vectorClear(); // DONE
	vectorGetAllocator(); // DONE
	vectorConstIterator();
	vectorIterator();
	//vectorConstReverseIterator();
}

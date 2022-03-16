#include <ctime>
#include "./vector/vector.hpp"
#include <vector>
#include <string.h>

enum Color {
	RED = 31,
	//"\033["
};

void	printOk() {
	std::cout << "\033[0;32m" << "V" << "\033[0;37m";
}

void	printError(std::string message) {
	std::cout << "\033[0;31m" << message << "\033[0;37m" << std::endl;
}

void	simpleCreation() {
	std::cout << "SimpleCreation" << std::endl;
	ft::vector<int> ft_vct(10, 5);
	std::vector<int> st_vct(10, 5);
	ft_vct.size() == st_vct.size() ? printOk() : printError("ft_vct.size != st_vct.size");
	ft_vct.max_size() == st_vct.max_size() ? printOk() : printError("ft_vct.max_size != st_vct.max_size");
	std::cout << "\n\t===" << std::endl;
}

void	vectorExpansion() {
	std::cout << "VectorExpansion" << std::endl;
	{
		// Default constructor
		std::cout << "Default constructor" << std::endl;;
		ft::vector<int> ft_vector;
    std::vector<int> st_vector;
    ft_vector.capacity() == st_vector.capacity() ? printOk() : printError("ft_vector.capacity != st_vector.capacity");
    for (std::size_t i = 0; i < 1000000; ++i) {
      ft_vector.push_back(i);
      st_vector.push_back(i);
			if (ft_vector[ft_vector.size() - 1] != st_vector[st_vector.size() - 1]) {
				printError("\nft_vector[ft_vector.size() - 1] == st_vector[st_vector.size() - 1]");
				break;
			}
			if (ft_vector.capacity() != st_vector.capacity() || ft_vector.size() != st_vector.size()) {
				printError("\nft_vector.capacity != st_vector.capacity || ft_vector.size != st_vector.size");
				break;
			}
    }
		printOk();
		printOk();
	}
	{
		// Fill constructor
		std::cout << "\nFill constructor" << std::endl;
		ft::vector<int> ft_vector(10, 8);
    std::vector<int> st_vector(10, 8);
    ft_vector.capacity() == st_vector.capacity() ? printOk() : printError("ft_vector.capacity != st_vector.capacity");
    for (std::size_t i = 0; i < 1000000; ++i) {
      ft_vector.push_back(i);
      st_vector.push_back(i);
			if (ft_vector[ft_vector.size() - 1] != st_vector[st_vector.size() - 1]) {
				printError("\nft_vector[ft_vector.size() - 1] == st_vector[st_vector.size() - 1]");
				break;
			}
      if (ft_vector.capacity() != st_vector.capacity() || ft_vector.size() != st_vector.size()) {
				printError("\nft_vector.capacity != st_vector.capacity || ft_vector.size != st_vector.size");
				break;
			}
    }
		printOk();
		printOk();
	}
	std::cout << "\n\t===" << std::endl;
}

void	vectorResize() {
	std::cout << "VectorExpansion" << std::endl;
	ft::vector<int> ft_vector(10, 8);
  std::vector<int> st_vector(10, 8);

  {
		// resize (n < _size)
		std::cout << "Resize (n < _size)" << std::endl;
    ft::vector<int>::iterator first_it = ft_vector.begin();
    ft_vector.resize(5);
    st_vector.resize(5);

    ft_vector.size() == st_vector.size() ? printOk() : printError("ft_vector.size() != st_vector.size()");
    ft_vector.capacity() == st_vector.capacity() ? printOk() : printError("ft_vector.capacity() != st_vector.capacity()");

    /*  Iterator still must be valid after resize */
    ft::vector<int>::iterator second_it = ft_vector.begin();
    while (second_it != ft_vector.end())
			first_it++.operator==(second_it++) == true ? printOk() : printError("first_it++.operator==(second_it++) != true");
  }

  {
		// resize (n < _size && n < _capacity)
		std::cout << "\nResize (n > _size && n < _capactity)" << std::endl;
    // To increase _capacity from 10 to 20
    ft_vector.push_back(1);
    st_vector.push_back(1);
    ft_vector.resize(15);
    st_vector.resize(15);

    ft_vector.size() == st_vector.size() ? printOk() : printError("ft_vector.size() != st_vector.size()");
    ft_vector.capacity() == st_vector.capacity() ? printOk() : printError("ft_vector.capacity() != st_vector.capacity()");

    ft::vector<int>::iterator ft_it = ft_vector.begin();
    std::vector<int>::iterator st_it = st_vector.begin();
		*(ft_it + 12) == *(st_it + 12) ? printOk() : printError("*(ft_it + 12) != *(st_it + 12)");
	}
	{
		std::cout << "\nresize (n > _size && n > _capacity)" << std::endl;
		// To increase _capacity from 10 to 20
    ft_vector.push_back(1);
    st_vector.push_back(1);
    ft_vector.resize(22);
    st_vector.resize(22);

		ft_vector.size() == st_vector.size() ? printOk() : printError("\nft_vector.size() != st_vector.size()");
    ft_vector.capacity() == st_vector.capacity() ? printOk() : printError("\nft_vector.capacity() != st_vector.capacity()");

    ft::vector<int>::iterator ft_it = ft_vector.begin();
    std::vector<int>::iterator st_it = st_vector.begin();
		*(ft_it + 12) == *(st_it + 12) ? printOk() : printError("\n*(ft_it + 12) != *(st_it + 12)");

    for (int i = 0; i < 20; ++i) {
      ft_vector.push_back(i);
      st_vector.push_back(i);
    	if (ft_vector.capacity() != st_vector.capacity()) {
				printError("\nft_vector.capacity() != st_vector.capacity()");
				break;
			}
    }
		printOk();
	}
	std::cout << "\n\t===" << std::endl;
}

void	vectorClear() {
	std::cout << "VectorClear" << std::endl;
	ft::vector<int> ft_vector(10, 8);
	std::vector<int> st_vector(10, 8);
  ft_vector.clear();
	st_vector.clear();
  ft_vector.size() == st_vector.size() ? printOk() : printError("\nft_vector.size() != st_vector.size()");
	std::cout << "\n\t===" << std::endl;
}

void	vectorReserve() {
	std::cout << "VectorReserve" << std::endl;
	ft::vector<int> ft_vector(10, 8);
  std::vector<int> st_vector(10, 8);

  {
		std::cout << "\nn < _capacity" << std::endl;
    ft_vector.reserve(5);
    st_vector.reserve(5);
		ft_vector.size() == st_vector.size() ? printOk() : printError("\nft_vector.size() != st_vector.size()");
    ft_vector.capacity() == st_vector.capacity() ? printOk() : printError("\nft_vector.capacity() != st_vector.capacity()");
  }
  {
    std::cout << "\nn == _capacity" << std::endl;
		ft_vector.reserve(10);
    st_vector.reserve(10);
		ft_vector.size() == st_vector.size() ? printOk() : printError("\nft_vector.size() != st_vector.size()");
    ft_vector.capacity() == st_vector.capacity() ? printOk() : printError("\nft_vector.capacity() != st_vector.capacity()");
  }
	{
    std::cout << "\nn > _capacity" << std::endl;
		ft_vector.reserve(15);
    st_vector.reserve(15);
		ft_vector.size() == st_vector.size() ? printOk() : printError("\nft_vector.size() != st_vector.size()");
    ft_vector.capacity() == st_vector.capacity() ? printOk() : printError("\nft_vector.capacity() != st_vector.capacity()");
  }
	{
		std::cout << "\nTest that exception is thrown" << std::endl;
    ft::vector<int>::size_type ft_max = ft_vector.max_size();
    std::vector<int>::size_type st_max = st_vector.max_size();
		ft_max == st_max ? printOk() : printError("ft_max != st_max");

		std::string ft_error;
		std::string st_error;
		try {
			ft_vector.reserve(ft_max + 15);
			printError("ft_vector.reserve(ft_max + 15) should throw an error");
		} catch (std::exception& e) {
			ft_error = e.what();
			printOk();
		}
		try {
			st_error.reserve(st_max + 15);
			printError("st_vector.reserve(st_max + 15) should throw an error");
		} catch (std::exception& e) {
			st_error = e.what();
			printOk();
		}
		// we cut the std:: and ft:: part.
		st_error.substr(strlen("std::")) == ft_error.substr(strlen("ft::")) ? printOk() : printError("\nMessage thrown by exception aren't the same");
  }
	std::cout << "\n\t===" << std::endl;
}

void vectorFrontBack() {
	std::cout << "VectorFrontBack" << std::endl;
	ft::vector<int> ft_vector;
	std::vector<int> st_vector;

	/*
	**	You can call front/back on an empty vector but trying to do stuff if returned reference will segfault, both for ft or std
	*/

	ft_vector.push_back(15);
  ft_vector.push_back(40);
  ft_vector.push_back(1);
  st_vector.push_back(15);
  st_vector.push_back(40);
  st_vector.push_back(1);

	ft_vector.front() == st_vector.front() ? printOk() : printError("\nft_vector.front() != st_vector.front()");
	ft_vector.back() -= ft_vector.front();
	st_vector.back() -= st_vector.front();
	ft_vector.front() == st_vector.front() ? printOk() : printError("\nft_vector.front() != st_vector.front()");
	ft_vector.back() == st_vector.back() ? printOk() : printError("\nft_vector.back() != st_vector.back()");

	while (!st_vector.empty()) {
		ft_vector.clear();
		st_vector.clear();
	}
	ft_vector.size() == st_vector.size() ? printOk() : printError("ft_vector.size() != st_vector.size()");
  ft_vector.capacity() == st_vector.capacity() ? printOk() : printError("ft_vector.capacity() != st_vector.capacity()");
	ft_vector.front() == st_vector.front() ? printOk() : printError("\nft_vector.front() != st_vector.front()");
	ft_vector.back() == st_vector.back() ? printOk() : printError("\nft_vector.back() != st_vector.back()");

	std::cout << "\n\t===" << std::endl;
}

void	vectorPopBack() {
	std::cout << "VectorPopBack" << std::endl;
	ft::vector<int> ft_vector;
	std::vector<int> st_vector;
  int st_sum = 0;
	int ft_sum = 0;
  ft_vector.push_back(100);
  ft_vector.push_back(200);
  ft_vector.push_back(300);
	st_vector.push_back(100);
  st_vector.push_back(200);
  st_vector.push_back(300);

  while (!st_vector.empty())
  {
    ft_sum += ft_vector.back();
    ft_vector.pop_back();
		st_sum += st_vector.back();
		st_vector.pop_back();
  }
	ft_sum == st_sum ? printOk() : printError("\nft_sum != st_sum");
	st_vector.pop_back();
	st_vector.pop_back();
	ft_vector.pop_back();
	ft_vector.pop_back();
	ft_vector[0] == st_vector[0] ? printOk() : printError("\nft_vector[0] != st_vector[0]");
	std::cout << "\n\t===" << std::endl;
}

void	vectorAt() {
	std::cout << "VectorAt" << std::endl;
	ft::vector<int> ft_vector(10, 8);
  std::vector<int> st_vector(10, 8);

  ft_vector.push_back(100);
  st_vector.push_back(100);
	ft_vector.at(10) == st_vector.at(10) ? printOk() : printError("\nft_vector.at(10) != st_vector.at(10)");
	std::string ft_error;
	std::string st_error;
	try {
		ft_vector.at(11);
		printError("\nft_vector.at(11) should throw an error");
	} catch (std::exception& e) {
		printOk();
		ft_error = e.what();
	}
	try {
		st_vector.at(11);
		printError("\nst_vector.at(11) should throw an error");
	} catch (std::exception& e) {
		printOk();
		st_error = e.what();
	}
	st_error == ft_error ? printOk() : printError("\nMessage thrown by exception aren't the same");
	std::cout << "\n\t===" << std::endl;
}

void	vectorIterator() {
	std::cout << "VectorIterator" << std::endl;
	ft::vector<int> ft_vector(10, 8);
  std::vector<int> st_vector(10, 8);
  ft::vector<int>::iterator ft_it = ft_vector.begin();
  std::vector<int>::iterator st_it = st_vector.begin();

  {
    std::cout << "Test that iteration is good" << std::endl;
		int i = 0;
    while (st_it != st_vector.end()) {
      (*ft_it == *st_it) ? printOk() : printError("\n*ft_it != *st_it");
      ++i;
      ++st_it;
    }
  }
  {
    std::cout << "\nTest that iteration stops at it.end()" << std::endl;
		int i = 0;
    while (ft_it++ != ft_vector.end()) {
      ++i;
    }
		i == 10 ? printOk() : printError("\ni != 10");
  }
	{
		std::cout << "\nOn an empty vector" << std::endl;
		ft::vector<int> ft_empty_vector;
		std::vector<int> st_empty_vector;
		ft::vector<int>::iterator ft_it = ft_empty_vector.begin();
		std::vector<int>::iterator st_it = st_empty_vector.begin();
		int i = 0;
		while (ft_it != ft_empty_vector.end()) {
      (*ft_it == *st_it) ? printOk() : printError("\n*ft_it != *st_it");
		}
		i == 0 ? printOk() : printError("\ni != 0");
	}
	std::cout << "\n\t===" << std::endl;
}

void	vector_test() {
	simpleCreation();
	vectorExpansion();
	vectorResize();
	vectorReserve();
	vectorClear();
	vectorPopBack();
	vectorFrontBack();
	vectorAt();
	vectorIterator();
}


int main() {
	vector_test();
}

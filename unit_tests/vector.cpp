#include "catch.hpp"
#include "../vector/vector.hpp"
#include <iostream>
#include <vector>

TEST_CASE("simple creation", "[ft_vector]") {
  ft::vector<int> vct(10, 5);
  REQUIRE(vct.size() == 10);

  std::vector<int> std_vct(10, 5);
  REQUIRE(vct.max_size() == std_vct.max_size());
}

TEST_CASE("Tests operator =", "[ft_vector]") {
  ft::vector<int> ft_vector(10, 8);
  ft::vector<int> st_vector(3, 4);

  ft_vector = st_vector;
  ft::vector<int>::iterator ft_it = ft_vector.begin();
  ft::vector<int>::iterator st_it = ft_vector.begin();
  while (ft_it != ft_vector.end()) {
    std::cout << *ft_it << " | " << *st_it << std::endl;
    REQUIRE(*ft_it++ == *st_it++);
  }
}

TEST_CASE("test that ft_vector grows like st_vector", "[ft_vector]") {
  // Default constructor
  {
    ft::vector<int> ft_vector;
    std::vector<int> st_vector;
    REQUIRE(ft_vector.capacity() == st_vector.capacity());
    for (std::size_t i = 0; i < 1000000; ++i) {
      ft_vector.push_back(i);
      st_vector.push_back(i);
      REQUIRE(ft_vector.capacity() == st_vector.capacity());
      REQUIRE(ft_vector.size() == st_vector.size());
    }
  }

  // Fill constructor
  {
    ft::vector<int> ft_vector(10, 8);
    std::vector<int> st_vector(10, 8);
    REQUIRE(ft_vector.capacity() == st_vector.capacity());
    for (std::size_t i = 0; i < 1000000; ++i) {
      ft_vector.push_back(i);
      st_vector.push_back(i);
      REQUIRE(ft_vector[ft_vector.size() - 1] == st_vector[st_vector.size() - 1]);
      REQUIRE(ft_vector.capacity() == st_vector.capacity());
      REQUIRE(ft_vector.size() == st_vector.size());
    }
  }
}

TEST_CASE("Tests iterators", "[ft_vector]") {
  ft::vector<int> ft_vector(10, 8);
  std::vector<int> st_vector(10, 8);
  ft::vector<int>::iterator ft_it = ft_vector.begin();
  std::vector<int>::iterator st_it = st_vector.begin();

  SECTION("Tests that iteration is good") {
    int i = 0;
    while (st_it != st_vector.end()) {
      REQUIRE(*ft_it == *st_it);
      ++i;
      ++st_it;
    }
    REQUIRE(i == 10);
  }

  SECTION ("Test that iteration stops at it.end()") {
    int i = 0;
    while (ft_it++ != ft_vector.end()) {
      ++i;
    }
    REQUIRE(i == 10);
  }
}

TEST_CASE("Tests vector::resize()", "[ft_vector]") {
  ft::vector<int> ft_vector(10, 8);
  std::vector<int> st_vector(10, 8);

  SECTION("Test resize (n < _size)") {
    ft::vector<int>::iterator first_it = ft_vector.begin();
    ft_vector.resize(5);
    st_vector.resize(5);

    REQUIRE(ft_vector.size() == st_vector.size());
    REQUIRE(ft_vector.capacity() == st_vector.capacity());
  
    /*  Iterator still must be valid after resize */
    ft::vector<int>::iterator second_it = ft_vector.begin();
    while (second_it != ft_vector.end())
      REQUIRE(first_it++.operator==(second_it++) == true);
  }

  SECTION("Test resize (n > _size && n < _capacity)") {
    // To increase _capacity from 10 to 20
    ft_vector.push_back(1);
    st_vector.push_back(1);
    ft_vector.resize(15);
    st_vector.resize(15);
    
    REQUIRE(ft_vector.size() == st_vector.size());
    REQUIRE(ft_vector.capacity() == st_vector.capacity());
    ft::vector<int>::iterator ft_it = ft_vector.begin();
    std::vector<int>::iterator st_it = st_vector.begin();
    REQUIRE(*(ft_it + 12) == *(st_it + 12));
  }

  SECTION("Test resize (n > _size && n > _capacity)") {
    // To increase _capacity from 10 to 20
    ft_vector.push_back(1);
    st_vector.push_back(1);
    ft_vector.resize(22);
    st_vector.resize(22);
    
    REQUIRE(ft_vector.size() == st_vector.size());
    REQUIRE(ft_vector.capacity() == st_vector.capacity());
    ft::vector<int>::iterator ft_it = ft_vector.begin();
    std::vector<int>::iterator st_it = st_vector.begin();
    REQUIRE(*(ft_it + 12) == *(st_it + 12));

    for (int i = 0; i < 20; ++i) {
      ft_vector.push_back(i);
      st_vector.push_back(i);
      REQUIRE(ft_vector.capacity() == st_vector.capacity());
    }
  }
}

#ifdef BENCHMARK
TEST_CASE("BENCHMARK", "[ft_vector]") {
  ft::vector<int> ft_vector(10, 8);
  std::vector<int> st_vector(10, 8);

  ft::vector<int>::iterator ft_it = ft_vector.begin();
  std::vector<int>::iterator st_it = st_vector.begin();
  int i = 0;
  while (st_it != st_vector.end()) {
    REQUIRE(*ft_it == *st_it);
    ++i;
    ++st_it;
  }
  REQUIRE(i == 10);
}
#endif
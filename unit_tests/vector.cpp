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
  SECTION("_capacity >= rhs.size") {
    ft::vector<int> ft_vector(3, 8);
    ft::vector<int> st_vector(3, 4);

    ft_vector = st_vector;
    ft::vector<int>::iterator ft_it = ft_vector.begin();
    ft::vector<int>::iterator st_it = st_vector.begin();
    while (ft_it != ft_vector.end())
      REQUIRE(*ft_it++ == *st_it++);
  }

  SECTION("_capacity < rhs._size") {
    ft::vector<int> ft_vector(3, 8);
    ft::vector<int> st_vector(10, 4);

    ft_vector = st_vector;
    ft::vector<int>::iterator ft_it = ft_vector.begin();
    ft::vector<int>::iterator st_it = st_vector.begin();
    while (st_it != st_vector.end())
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

TEST_CASE("Tests at()", "[ft_vector]") {
  ft::vector<int> ft_vector(10, 8);
  std::vector<int> st_vector(10, 8);

  ft_vector.push_back(100);
  st_vector.push_back(100);
  REQUIRE(ft_vector.at(10) == 100);
  REQUIRE(st_vector.at(10) == 100);
  REQUIRE_THROWS(ft_vector.at(11));
  REQUIRE_THROWS(st_vector.at(11));
}

TEST_CASE("Tests front / back", "[ft_vector]") {
  ft::vector<int> ft_vector;
  ft_vector.push_back(15);
  ft_vector.push_back(40);
  ft_vector.push_back(1);

  ft_vector.front() += ft_vector.back();
  REQUIRE(ft_vector.front() == 16);
  ft_vector.back() -= ft_vector.front();
  REQUIRE(ft_vector.back() == -15);
}

TEST_CASE("Tests pop_back", "[ft_vector]") {
  ft::vector<int> ft_vector;
  int sum  = 0;
  ft_vector.push_back (100);
  ft_vector.push_back (200);
  ft_vector.push_back (300);

  while (!ft_vector.empty())
  {
    sum += ft_vector.back();
    ft_vector.pop_back();
  }
  REQUIRE(sum == 600);
}

TEST_CASE("Tests clear", "[ft_vector]") {
  ft::vector<int> ft_vector(10, 8);
  ft_vector.clear();
  REQUIRE(ft_vector.size() == 0);
}

TEST_CASE("Tests reserve", "[ft_vector]") {
  ft::vector<int> ft_vector(10, 8);
  std::vector<int> st_vector(10, 8);

  SECTION("n < _capacity") {
    ft_vector.reserve(5);
    st_vector.reserve(5);
    REQUIRE(ft_vector.size() == st_vector.size());
    REQUIRE(ft_vector.capacity() == st_vector.capacity());
  }

  SECTION("n == _capacity") {
    ft_vector.reserve(10);
    st_vector.reserve(10);
    REQUIRE(ft_vector.size() == st_vector.size());
    REQUIRE(ft_vector.capacity() == st_vector.capacity());
  }

  SECTION("n > _capacity") {
    ft_vector.reserve(15);
    st_vector.reserve(15);
    REQUIRE(ft_vector.size() == st_vector.size());
    REQUIRE(ft_vector.capacity() == st_vector.capacity());
  }

  SECTION("Test exception throw") {
    ft::vector<int>::size_type ft_max = ft_vector.max_size();
    std::vector<int>::size_type st_max = st_vector.max_size();

    REQUIRE_THROWS(ft_vector.reserve(ft_max + 15));
    REQUIRE_THROWS(st_vector.reserve(st_max + 15));
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

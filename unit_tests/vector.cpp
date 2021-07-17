#include "catch.hpp"
#include "../vector.hpp"
#include <iostream>
#include <vector>

TEST_CASE("simple creation", "[ft_vector]") {
  ft::vector<int> vct(10, 5);
  REQUIRE(vct.size() == 10);
}

TEST_CASE("test that ft_vector grows like st_vector", "[ft_vector]") {
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

TEST_CASE("Tests iterators", "[ft_vector]") {
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
#include "catch.hpp"
#include "../ft_vector.hpp"
#include <iostream>
#include <vector>

TEST_CASE ("FT_VECTOR", "CONSTRUCTOR") {
   ft::vector<int> vct(10, 5);
   REQUIRE(vct.size() == 10);
}

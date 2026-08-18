#include <catch2/catch_test_macros.hpp>
#include "../src/fixed_xor.hpp"
#include "../../../common/bytes.hpp"

TEST_CASE("Set 1 Challenge 2: fixed XOR")
{
  auto a = hex_decode("1c0111001f010100061a024b53535009181c");
  auto b = hex_decode("686974207468652062756c6c277320657965");
  auto result = fixed_xor(a, b);
  REQUIRE(hex_encode(result) == "746865206b696420646f6e277420706c6179");
}
TEST_CASE("Set 1 Challenge 2: mismatched lengths throw")
{
  std::vector<uint8_t> a = {1, 2, 3};
  std::vector<uint8_t> b = {1, 2};
  REQUIRE_THROWS_AS(fixed_xor(a, b), std::invalid_argument);
}
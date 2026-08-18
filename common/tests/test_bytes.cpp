#include <catch2/catch_test_macros.hpp>
#include "../bytes.hpp"

TEST_CASE("hex_decode: basic conversion")
{
  auto bytes = hex_decode("4d61");
  REQUIRE(bytes.size() == 2);
  REQUIRE(bytes[0] == 0x4D);
  REQUIRE(bytes[1] == 0x61);
}

TEST_CASE("hex_encode: basic conversion")
{
  std::vector<uint8_t> bytes = {0x4D, 0x61};
  REQUIRE(hex_encode(bytes) == "4d61"); // lowercase, per your fix above
}

TEST_CASE("hex_decode -> hex_encode round trip")
{
  std::string original = "1c0111001f010100061a024b53535009181c";
  auto bytes = hex_decode(original);
  REQUIRE(hex_encode(bytes) == original);
}

TEST_CASE("hex_decode: invalid character throws")
{
  REQUIRE_THROWS_AS(hex_decode("zz"), std::invalid_argument);
}

TEST_CASE("hex_decode: empty string")
{
  auto bytes = hex_decode("");
  REQUIRE(bytes.empty());
}
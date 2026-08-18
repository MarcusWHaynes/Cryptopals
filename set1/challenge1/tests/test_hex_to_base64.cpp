#include <catch2/catch_test_macros.hpp>
#include "../src/hex_to_base64.hpp"

TEST_CASE("Set 1 Challenge 1: hex to base64 Main Challenge")
{
  std::string input = "49276d206b696c6c696e6720796f757220627261696e206c696b65206120706f69736f6e6f7573206d757368726f6f6d";
  std::string expected = "SSdtIGtpbGxpbmcgeW91ciBicmFpbiBsaWtlIGEgcG9pc29ub3VzIG11c2hyb29t";
  REQUIRE(hex_to_base64(input) == expected);
}
TEST_CASE("Set 1 Challenge 1: base64 padding — one leftover byte")
{
  REQUIRE(hex_to_base64("4d") == "TQ==");
}

TEST_CASE("Set 1 Challenge 1: base64 padding — two leftover bytes")
{
  REQUIRE(hex_to_base64("4d61") == "TWE=");
}

TEST_CASE("Set 1 Challenge 1: base64 padding — no padding needed")
{
  REQUIRE(hex_to_base64("4d6161") == "TWFh");
}

TEST_CASE("Set 1 Challenge 1: empty input")
{
  REQUIRE(hex_to_base64("") == "");
}
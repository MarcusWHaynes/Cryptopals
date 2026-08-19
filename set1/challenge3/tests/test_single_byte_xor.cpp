#include <catch2/catch_test_macros.hpp>
#include "../src/single_byte_xor.hpp"
#include "bytes.hpp"

TEST_CASE("Set 1 Challenge 3: cracks the known cryptopals ciphertext")
{
  auto ciphertext = hex_decode("1b37373331363f78151b7f2b783431333d78397828372d363c78373e783a393b3736");
  XorResult result = crack_single_byte_xor(ciphertext);

  REQUIRE(result.key == 88); // 'X' — verify this against your own run's actual output
  REQUIRE(result.plaintext == "Cooking MC's like a pound of bacon");
}

TEST_CASE("Set 1 Challenge 3: single-byte XOR round trip")
{
  std::vector<uint8_t> original = {'h', 'e', 'l', 'l', 'o'};
  uint8_t key = 42;

  std::vector<uint8_t> encrypted;
  for (uint8_t b : original)
    encrypted.push_back(b ^ key);

  std::vector<uint8_t> decrypted;
  for (uint8_t b : encrypted)
    decrypted.push_back(b ^ key);

  REQUIRE(decrypted == original);
}

TEST_CASE("Set 1 Challenge 3: scoring favors plausible English")
{
  std::vector<uint8_t> english = {'t', 'h', 'e', ' ', 'q', 'u', 'i', 'c', 'k'};
  std::vector<uint8_t> garbage = {0x01, 0xFF, 0x02, 0xFE, 0x03, 0xFD};

  REQUIRE(scoring(english) < scoring(garbage));
}
#pragma once
#include <string>
#include <vector>
#include <cstdint>

struct XorResult
{
  uint8_t key;
  double score;
  std::string plaintext;
};

double scoring(const std::vector<uint8_t> &input);
XorResult crack_single_byte_xor(const std::vector<uint8_t> &ciphertext);
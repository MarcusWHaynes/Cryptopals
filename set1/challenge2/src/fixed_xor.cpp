#include "fixed_xor.hpp"
#include <stdexcept>

std::vector<uint8_t> fixed_xor(const std::vector<uint8_t> &a, const std::vector<uint8_t> &b)
{
  if (a.size() != b.size())
  {
    throw std::invalid_argument(std::string("Invalid input. Buffers should be the same length."));
  }
  std::vector<uint8_t> out;
  out.reserve(a.size());
  for (std::size_t i = 0; i < a.size(); i++)
  {
    out.push_back(a[i] ^ b[i]);
  }

  return out;
}
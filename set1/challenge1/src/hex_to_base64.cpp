#include "hex_to_base64.hpp"
#include <stdexcept>
/*
To convert from hex to b64 you need:
hex -> raw Binary -> b64
hex (4 bit binary) -> group -> take 6 bits and convert
*/

/*
Method to convert hex to Bin
*/

/*
Taking that binary and converting to b64
*/
static uint8_t hex_char_to_value(char c)
{
  c = static_cast<char>(std::toupper(static_cast<unsigned char>(c)));
  if (c >= '0' && c <= '9')
    return static_cast<uint8_t>(c - '0');
  if (c >= 'A' && c <= 'F')
    return static_cast<uint8_t>(c - 'A' + 10);
  throw std::invalid_argument(std::string("Invalid hex character: ") + c);
}

static std::vector<uint8_t> hex_to_bits(const std::string &hex)
{
  std::vector<uint8_t> bits;
  bits.reserve(hex.size() * 4);

  for (char c : hex)
  {
    uint8_t value = hex_char_to_value(c);
    bits.push_back((value >> 3) & 1);
    bits.push_back((value >> 2) & 1);
    bits.push_back((value >> 1) & 1);
    bits.push_back(value & 1);
  }
  return bits;
}

/*
Taking that binary and converting to b64
*/
static std::string bits_to_base64(const std::vector<uint8_t> &bytes)
{
  static const char *table =
      "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789+/";

  std::string out;
  for (std::size_t i = 0; i < bytes.size(); i += 6)
  {
    uint8_t value = 0;

    for (std::size_t j = 0; j < 6; ++j)
    {
      value <<= 1;

      if (i + j < bytes.size())
      {
        value |= bytes[i + j];
      }
    }
    out += table[value];
  }
  if (bytes.size() % 24 == 8)
  {
    out += "==";
  }
  else if (bytes.size() % 24 == 16)
  {
    out += "=";
  }

  return out;
}

// Public function — this is what main.cpp and the test file actually call
std::string hex_to_base64(const std::string &hex)
{
  std::vector<uint8_t> bytes = hex_to_bits(hex);
  return bits_to_base64(bytes);
}

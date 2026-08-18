#include "hex_to_base64.hpp"
#include <stdexcept>
#include <iostream>
/*
To convert from hex to b64 you need:
hex -> bytes -> b64
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

static std::vector<uint8_t> hex_to_bytes(const std::string &hex)
{

  std::vector<uint8_t> bytes;
  bytes.reserve(hex.size() / 2);
  for (std::size_t i = 0; i < hex.size(); i += 2)
  {
    uint8_t high = hex_char_to_value(hex[i]);
    // Padding odd length hex strings with a 0 at the end
    // NB Change this if padding is incorrect
    uint8_t low = 0;

    if (i + 1 < hex.size())
    {
      low = hex_char_to_value(hex[i + 1]);
    }
    bytes.push_back((high << 4) | low);
  }

  return bytes;
}

static std::string bytes_to_base64(const std::vector<uint8_t> &bytes)
{
  static const char *table =
      "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789+/";

  std::string out;

  std::size_t total_bits = bytes.size() * 8;
  for (std::size_t i = 0; i < total_bits; i += 6)
  {
    uint8_t b64value = 0;
    for (std::size_t j = 0; j < 6; ++j)
    {
      b64value <<= 1;
      std::size_t bitindex = i + j;

      if (bitindex < total_bits)
      {
        std::size_t byte_index = bitindex / 8;
        std::size_t bit_pos = 7 - (bitindex % 8);
        uint8_t bit = (bytes[byte_index] >> bit_pos) & 1;

        b64value |= bit;
      }
    }
    out += table[b64value];
  }
  if (bytes.size() % 3 == 1)
  {
    out += "==";
  }
  else if (bytes.size() % 3 == 2)
  {
    out += "=";
  }

  return out;
}

std::string hex_to_base64(const std::string &hex)
{
  std::vector<uint8_t> bytes = hex_to_bytes(hex);
  return bytes_to_base64(bytes);
}

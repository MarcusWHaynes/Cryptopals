#include "bytes.hpp"
#include <stdexcept>

static uint8_t hex_char_to_value(char c)
{
  c = static_cast<char>(std::toupper(static_cast<unsigned char>(c)));
  if (c >= '0' && c <= '9')
    return static_cast<uint8_t>(c - '0');
  if (c >= 'A' && c <= 'F')
    return static_cast<uint8_t>(c - 'A' + 10);
  throw std::invalid_argument(std::string("Invalid hex character: ") + c);
}

std::vector<uint8_t> hex_decode(const std::string &hex)
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

static char value_to_hex_char(uint8_t value)
{
  if (value <= 9)
    return static_cast<char>('0' + value);

  if (value <= 15)
    return static_cast<char>('a' + (value - 10));

  throw std::invalid_argument("Invalid hex value");
}

std::string hex_encode(const std::vector<uint8_t> &bytes)
{
  std::string out;
  for (std::size_t i = 0; i < bytes.size(); ++i)
  {
    uint8_t value = bytes[i];
    char high = value_to_hex_char((value >> 4) & 0x0F);
    char low = value_to_hex_char(value & 0x0F);
    out += high;
    out += low;
  }
  return out;
}

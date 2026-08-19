#include "fixed_xor.hpp"
#include "bytes.hpp"
#include <iostream>

int main()
{
  auto a = hex_decode("1c0111001f010100061a024b53535009181c");
  auto b = hex_decode("686974207468652062756c6c277320657965");
  auto result = fixed_xor(a, b);
  std::cout << hex_encode(result) << "\n";
  return 0;
}
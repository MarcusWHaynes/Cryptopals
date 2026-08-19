#include "single_byte_xor.hpp"
#include "bytes.hpp"
#include <iostream>

int main()
{
  auto ciphertext = hex_decode("1b37373331363f78151b7f2b783431333d78397828372d363c78373e783a393b3736");
  XorResult result = crack_single_byte_xor(ciphertext);

  std::cout << "Key: " << static_cast<int>(result.key) << "\n";
  std::cout << "Score: " << result.score << "\n";
  std::cout << "Plaintext: " << result.plaintext << "\n";
  return 0;
}
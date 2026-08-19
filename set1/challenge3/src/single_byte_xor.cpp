#include "single_byte_xor.hpp"
#include <array>

// Scoring for the key. Check the write up for more infomation and thoughts
double scoring(const std::vector<uint8_t> &input)
{
  static constexpr double english_freq[26] = {
      0.08167, 0.01492, 0.02782, 0.04253, 0.12702,
      0.02228, 0.02015, 0.06094, 0.06966, 0.00153,
      0.00772, 0.04025, 0.02406, 0.06749, 0.07507,
      0.01929, 0.00095, 0.05987, 0.06327, 0.09056,
      0.02758, 0.00978, 0.02360, 0.00150, 0.01974,
      0.00074};

  std::array<int, 26> observed{};
  int total = 0;

  for (uint8_t byte : input)
  {
    char c = static_cast<char>(byte);

    if (c >= 'A' && c <= 'Z')
      c += 'a' - 'A';

    if (c >= 'a' && c <= 'z')
    {
      observed[c - 'a']++;
      ++total;
    }
  }

  if (total == 0)
    return 1e9;

  double score = 0.0;

  for (int i = 0; i < 26; ++i)
  {
    double expected = total * english_freq[i];
    double diff = observed[i] - expected;

    score += (diff * diff) / expected;
  }

  return score;
}

static std::vector<uint8_t> apply_single_byte_xor(const std::vector<uint8_t> &input, uint8_t key)
{
  std::vector<uint8_t> out;
  out.reserve(input.size());
  for (uint8_t b : input)
  {
    out.push_back(b ^ key);
  }
  return out;
}

XorResult crack_single_byte_xor(const std::vector<uint8_t> &ciphertext)
{
  XorResult best{0, 1e9, ""};

  for (int i = 0; i <= 255; ++i)
  {
    uint8_t key = static_cast<uint8_t>(i);
    std::vector<uint8_t> candidate = apply_single_byte_xor(ciphertext, key);
    double score = scoring(candidate);

    if (score < best.score)
    {
      best.key = key;
      best.score = score;
      best.plaintext = std::string(candidate.begin(), candidate.end());
    }
  }
  return best;
}
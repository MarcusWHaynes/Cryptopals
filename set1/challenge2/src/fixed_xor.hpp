#pragma once
#include <string>
#include <vector>
#include <cstdint>

// XORs two equal-length byte buffers together
std::vector<uint8_t> fixed_xor(const std::vector<uint8_t> &a, const std::vector<uint8_t> &b);
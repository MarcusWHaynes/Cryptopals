#pragma once
#include <string>
#include <vector>
#include <cstdint>

std::vector<uint8_t> hex_decode(const std::string &hex);
std::string hex_encode(const std::vector<uint8_t> &bytes);
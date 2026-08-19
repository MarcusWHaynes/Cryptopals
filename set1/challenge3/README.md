# Set 1 / Challenge 3 — Single-byte XOR cipher

## Problem
A string has been XOR'd against a single character. Find the key and decrypt it.

## Approach
Brute-force all 256 possible single-byte keys, decrypt with each, and score the
result using a chi-squared statistic against known English letter frequencies.

## Run
\`\`\`
./build/set1/challenge3/set1_challenge3
\`\`\`

## Test
\`\`\`
ctest --test-dir build -R challenge3
\`\`\`
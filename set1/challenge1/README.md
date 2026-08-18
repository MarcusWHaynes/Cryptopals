# Set 1 / Challenge 1 - Converting Hex to Base64 

## Problem 
Convert a hex-encoded string into base64.

## Solution/Approach
Decoding the hex into binary then, re-encoding the binary 6 bits at a time using a lookup table.

## Other things of note
This was my first project in c (I am using these challenges to put what I've learnt of c to use)


## Run
\`\`\`
./build/set1/challenge1/set1_challenge1
\`\`\`

## Test
\`\`\`
ctest --test-dir build -R set1_challenge1
\`\`\`
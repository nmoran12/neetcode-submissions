class Solution {
public:
    uint32_t reverseBits(uint32_t n) {
        uint32_t result = 0; // Initialize 32-bit integer to hold reversed bits

        for (int i = 0; i < 32; i++) {
            // 1. Extract the single bit at index 'i' (0 through 31)
            uint32_t bit = (n >> i) & 1;
            
            // 2. Shift that bit to its mirrored position (31 - i) and add it to result
            result += (bit << (31 - i)); // Note: bitwise OR (result |= ...) also works!
        }
        
        return result; // Return full 32-bit reversed value
    }
};
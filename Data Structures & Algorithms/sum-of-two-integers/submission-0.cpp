class Solution {
public:
    int getSum(int a, int b) {
        while (b != 0) {
            // 1. Find carries. Cast to unsigned to prevent C++ negative shift UB.
            unsigned int carry = a & b; 
            
            // 2. Calculate sum without carries
            a = a ^ b;
            
            // 3. Shift carries to the left to be added in the next iteration
            b = carry << 1; 
        }
        
        return a;
    }
};
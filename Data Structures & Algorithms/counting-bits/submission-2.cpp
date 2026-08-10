class Solution {
public:
    vector<int> countBits(int n) {
        // Create an array of size (n + 1) to hold bit counts for 0 through n
        vector<int> output(n + 1, 0);

        // Process every number from 0 to n
        for (int i = 0; i <= n; i++) {
            int temp = i;  // Copy 'i' so we don't modify the loop variable
            int count = 0; // Tally of '1' bits for the current number 'i'
            
            // Kernighan's loop: runs once per set bit
            while (temp > 0) {
                temp = temp & (temp - 1); // Delete the rightmost '1' bit
                count++;                  // Tally the deleted bit
            }
            
            output[i] = count; // Save the result for index i
        }

        return output; // Return array of counts
    }
};
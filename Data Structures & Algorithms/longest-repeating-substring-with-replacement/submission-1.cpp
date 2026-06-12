class Solution {
public:
    int characterReplacement(string s, int k) {

        // Left Pointer of Sliding Window
        int left = 0;
        int maxLength = 0;
        int maxCount = 0;


        // Frequency Array
        int counts[26] = {0};


        // Loop, with incrementing right pointer
        for (int right = 0; right < s.length(); right++){

            // Get the character at the right pointer
            char rightChar = s[right];

            // Add +1 to frequency of that right character
            counts[rightChar - 'A']++;

            maxCount = max(maxCount, counts[rightChar - 'A']);

            
            // The current length of our sliding window;
            int windowLength = right - left + 1;


            if ((windowLength - maxCount) <= k){
                maxLength++;
            } else {
                char leftChar = s[left];
                counts[leftChar - 'A']--;
                left++;
            }
        }

        return maxLength;
    }
};

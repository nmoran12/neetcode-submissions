class Solution {
public:
    int lengthOfLongestSubstring(string s) {

        unordered_map<char, int> freqTable;
        int leftPointer = 0;
        int maxLength = 0;


        for (int rightPointer = 0; rightPointer < s.length(); rightPointer++){

            char rightChar = s[rightPointer];
            freqTable[rightChar]++;


            while (freqTables[rightPointer] > 1){
                char leftChar = s[leftPointer];
                freqTable[leftChar]--;
                leftPointer++;
            }

            int currWindowSize = rightPointer - leftPointer + 1;
            maxLength = max(maxLength, currWindowSize);

        }
        
        return maxLength;
    }
};

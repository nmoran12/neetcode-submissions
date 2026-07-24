class Solution {
public:
    int lengthOfLongestSubstring(string s) {

        unordered_map<char, int> hashMap;

        int maxSize = 0;
        int leftPointer = 0;

        // for the length of the string
        for (int rightPointer = 0; rightPointer < s.length(); rightPointer++){

            hashMap[s[rightPointer]]++;

            // If any frequencies exceed 1, reduce frequency of whatever char is at right pointer, because that is what made it exceed
            while (hashMap[s[rightPointer]] > 1){
                hashMap[s[leftPointer]]--;
                // Move left pointer forward
                leftPointer++;
            }

            maxSize = max(maxSize, rightPointer - leftPointer + 1);
        }
        

        return maxSize;
    }
};

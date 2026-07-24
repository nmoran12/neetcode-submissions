class Solution {
public:
    int lengthOfLongestSubstring(string s) {

        unordered_map<char, int> hashMap;

        // Add chars to hash map + their frequency
        for (auto chars : s){
            hashMap[chars]++;
        }

        int maxSize = 0;
        int leftPointer = 0;

        // for the length of the string
        for (int rightPointer = 0; rightPointer < s.length(); rightPointer++){

            // If any frequencies exceed 1, reduce frequency of whatever char is at right pointer, because that is what made it exceed
            if (hashMap[s[rightPointer]] > 1){
                hashMap[s[rightPointer]--];
                // Move left pointer forward
                leftPointer++;
            }

            maxSize = max(maxSize, rightPointer - leftPointer + 1);
        }
        

        return maxSize;
    }
};

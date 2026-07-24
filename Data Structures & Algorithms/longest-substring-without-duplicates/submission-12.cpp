class Solution {
public:
    int lengthOfLongestSubstring(string s) {

        // Declare a frequency map
        unordered_map<char, int> freqMap;

        // Loop through the string 's', for each character add +1 to its related key:value in the frequency map
        for (char c : s){
            freqMap[c]++;
        }

        int left = 0;
        int right = 1;
        int maxLength = 0;

        while (left < right){
            right++;
            maxLength++;
            freqMap[s[right]]++;


            for (auto& [key, count] : freqMap){
                if (count > 1){
                    freqMap.erase(count);
                    left = right + 1;
                    maxLength = 0;
                }
            }
        }

        
        return maxLength;
    }
};

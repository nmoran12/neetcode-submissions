class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int length = INT_MIN;
        int left = 0;
        int total = 0;
        unordered_set<char> charNums;

        for (int R = 0; R < s.length(); R++){

            while (charNums.count(s[R])){
                charNums.erase(s[left]);
                left++;
            }

            charNums.insert(s[R]);
            length = max(length, R - left + 1);
            

        }

        if (length == INT_MIN){
            return 0;
        }

        return length;
    }
};

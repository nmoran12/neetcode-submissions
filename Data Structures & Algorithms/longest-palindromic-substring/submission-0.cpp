class Solution {
public:
    string longestPalindrome(string s) {

        string result = "";
        int resultLength = 0;


        // Loop through every character in string
        for (int i = 0; i < s.length(); i++){
            int left = i;
            int right = i;


        while (left >= 0 && right <= s.size() && s[left] == s[right]){
            if ((right - left) + 1 > resultLength){
                result = 
                resultLength = (right - left) + 1;
            }

            left =- 1;
            right =+ 1;
        }
        
        left = i;
        right = i + 1;

        while (left >= && right + 1 <= s.size() && s[left] == s[right]){
            if ((right - left) + 1 > resultLength){
                result = 
                resultLength = (right - left) + 1;
            }

            left =- 1;
            right =+ 1;

        }
        };


        return result;
    }
};

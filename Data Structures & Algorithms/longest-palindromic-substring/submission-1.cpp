class Solution {
public:
    string longestPalindrome(string s) {

        string result = "";
        int resultLength = 0;
        int n = s.size();


        // Loop through every character in string
        for (int i = 0; i < n; i++){
            int left = i;
            int right = i;


        while (left >= 0 && right < n && s[left] == s[right]){
            if ((right - left) + 1 > resultLength){
                result = s.substr(left, (right - left) + 1);
                resultLength = (right - left) + 1;
            }

            left -= 1;
            right += 1;
        }
        
        left = i;
        right = i + 1;

        while (left >= && right + 1 < n && s[left] == s[right]){
            if ((right - left) + 1 > resultLength){
                result = s.substr(left, (right - left) + 1);
                resultLength = (right - left) + 1;
            }

            left -= 1;
            right += 1;

        }
        };


        return result;
    }
};

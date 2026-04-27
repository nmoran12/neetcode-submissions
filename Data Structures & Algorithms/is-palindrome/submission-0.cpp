class Solution {
public:
    bool isPalindrome(string s) {
        int lengthOfPal = s.length();

        for (int i=0; i<s.length(); i++){
            if (s[i] == s[lengthOfPal-1]){
                return false;
            } else{
                return true;
            }
        }

    }
};

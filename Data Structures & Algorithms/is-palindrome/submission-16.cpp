class Solution {
public:
    bool isPalindrome(string s) {

        string cleaned;



        for (int i = 0; i < s.length(); i++){
            if (isalnum(s[i])){
            s[i] = tolower(s[i]);
            };
        }

        int leftPointer = 0;
        int rightPointer = cleaned.length() - 1;

        while (leftPointer < rightPointer){
            if (s[leftPointer] == s[rightPointer]){
                leftPointer++;
                rightPointer--;
            } else {
                return false;
            }
        }
        

        return true;
    }
};

class Solution {
public:
    bool isPalindrome(string s) {

        int leftPointer = 0;
        int rightPointer = s.length() - 1;

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

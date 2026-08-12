class Solution {
public:
    int countSubstrings(string s) {

        int result = 0;
        int n = s.length();

        int count = 0;

        // 1-D Array initialised to false
        vector<bool> dp(n, false);

        // l goes backwards from n - 1 down to 0
        for (int l = n - 1; l >= 0; l--){
            // r goes backwards from n - 1 down to l
            for (int r = n - 1; r >= l; r--){
            bool sameOuterChars = (s[l] == s[r]);
            bool isShortString = (r - l <= 2); // Check if length <= 2, if it is then we know its automatically a palindrome
            bool innerIsPalindrome = r > 0 && dp[r - 1];

            // If outer characters of our string are same, and the inner substrings are all palindromes OR it is short enough that it doesnt matter
            if (sameOuterChars && (isShortString || innerIsPalindrome)){
                // Set that substring to 'true' and increment count
                dp[r] = true;
                count++;
            } else {
                // or set that substring to false
                dp[r] = false;
            }


            }
        }

        return count;
    }
};

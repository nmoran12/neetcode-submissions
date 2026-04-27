class Solution {
public:
    int characterReplacement(string s, int k) {
        int length = INT_MIN;
        int left = 0;
        vector<int> forNow(26, 0);
        int maxFrequency = 0;

        for (int R = 0; R < s.length(); R++){
            forNow[s[R] - 'A']++;
            maxFrequency = max(maxFrequency, forNow[s[R] - 'A']);

            while ((R - left + 1) - maxFrequency > k){
                forNow[s[left] - 'A']--;
                left++;




            }

            length = max(length, R - left + 1);

            if (length == INT_MIN){
                return 0;
            }


        }


        return length;
    }
};

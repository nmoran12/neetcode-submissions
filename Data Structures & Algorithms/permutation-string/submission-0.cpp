class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        vector<int> targetScorecard(26, 0);
        vector<int> windowScorecard(26, 0);
        int right = 0;
        int left = 0;
        int k = s1.length();

        for (int i = 0; i < s1.length(); i++){
            char current_letter = s1[i];

            // This is just the common ASCII trick of converting chars to int
            targetScorecard[current_letter - 'a']++;
        }

        while (right < s2.length()){
            windowScorecard[s2[right] - 'a']++;

            // Making sure the window is fixed size
            if ((right - left + 1) > k){
                // Decrement the frequency of whatever char was in that left box that was removed
                windowScorecard[s2[left] - 'a']--;
                // Move left forward by one to shrink window size
                left++;
            }

            if (windowScorecard == targetScorecard){
                return true;
            }




            right++;
        }


        return false;
    }
};

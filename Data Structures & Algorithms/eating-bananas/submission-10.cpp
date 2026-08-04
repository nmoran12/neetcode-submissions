class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {

        int left = 1;
        int right = 0;
        int answer = 0;

        // Get largest pile (i.e. the largest answer we will test) and put it into right pointer
        for (int i = 0; i < piles.size(); i++){
            right = max(right, piles[i]);
        }

        // Standard binary search pattern
        while (left <= right){
            int mid = left + (right - left) / 2;

            long long hours = 0;

            // Go through each piles[i] and get how long it will take to do each one, then add it all to hours
            for (int pile : piles){
                hours += ceil((double) pile / mid);
            };

            // If hours <= h (i.e. it is valid and below the maximum hours cutoff), add mid to answer, move
            // right pointer to halfway line - 1 to test lower answers
            if (hours <= h){
                answer = mid;
                right = mid - 1;
                // If hours > h, i.e. not valid, then move left to mid + 1 to test higher answers.
            } else if (hours > h){
                left = mid + 1;
            }
        }
        

        return answer;
    }
};

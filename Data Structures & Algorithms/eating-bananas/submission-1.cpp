class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {

        // ceiling: hours += (pile + k - 1) / k
        int left = 1;
        int right = 0;

        // getting largest value in piles to put as right border
        for (int i = 0; i < piles.size(); i++){
            if (piles[i] > right){
                right = piles[i];
            }
        }

        int answer = right;


        while (left <= right){

            long long hours = 0;

            int mid = left + (right - left) / 2;

            for (int i = 0; i < piles.size(); i++){
            hours += (piles[i] + mid - 1) / mid;
            };

            // If we can eat the banana pile within the allocate number of hours, we move left to try find a smaller
            // number
            if (hours <= h){
                answer = mid;
                right = mid - 1;

            // If we cannot eat the banana pile within allocated hours, go right to test bigger numbers
            } else {
                left = mid + 1;
            }

        }

        return answer;
    }
};

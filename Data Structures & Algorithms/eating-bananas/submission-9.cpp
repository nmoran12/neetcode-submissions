class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {

        int left = 1;
        int right = 0;
        int answer = 0;

        for (int i = 0; i < piles.size(); i++){
            right = max(right, piles[i]);
        }

        while (left <= right){
            int mid = left + (right - left) / 2;

            long long hours = 0;

            for (int pile : piles){
                hours += ceil((double) pile / mid);
            };

            if (hours <= h){
                answer = mid;
                right = mid - 1;
            } else if (hours > h){
                left = mid + 1;
            }
        }
        

        return answer;
    }
};

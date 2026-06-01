class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        int k = 0;
        int onePointer = 1;
        int twoPointer = piles.size() - 1;
        int currentValue = 0;

        for (int i = 0; i < piles.size(); i++){
            twoPointer = max(twoPointer, piles[i]);
        }

        int answer = twoPointer;

        while (onePointer <= twoPointer){
        int mid = onePointer + (twoPointer - onePointer) / 2;
            long long totalHours = 0;

            for (int i = 0; i < piles.size(); i++){
                totalHours += (piles[i] + mid - 1) / mid;
            }


            if (totalHours <= h){
                answer = mid;
                twoPointer = mid - 1;
            } else {
                onePointer = mid + 1;
            }
        }
        
        return answer;
    }
};

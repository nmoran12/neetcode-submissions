class Solution {
public:
    int numOfSubarrays(vector<int>& arr, int k, int threshold) {
        int currSum = 0;
        int left = 0;
        int aboveThreshold = 0;

        for (int right = 0; right < arr.size(); right++){
            currSum = currSum + arr[right];
            if (right - left + 1 > k){
                currSum = currSum - arr[left];
                left++;
            }

            if ((currSum / k) >= threshold){
                aboveThreshold++;

            }
        }
        return aboveThreshold;
    }

};
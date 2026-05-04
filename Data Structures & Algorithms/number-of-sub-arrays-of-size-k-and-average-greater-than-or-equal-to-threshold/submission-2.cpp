class Solution {
public:
    int numOfSubarrays(vector<int>& arr, int k, int threshold) {
        
        int curSum = 0;
        int results = 0;

        for (int i = 0; i < arr.size(); i++){
            curSum += arr[i];


            if (i >= k - 1){
                if ((curSum / k) >= threshold){
                    results++;
                }

                curSum -= arr[i - k + 1];
            }


        }

        return results;
    }
};
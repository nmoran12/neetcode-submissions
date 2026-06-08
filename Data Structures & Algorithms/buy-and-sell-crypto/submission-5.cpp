class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int leftPointer = 0;
        int rightPointer = 0;
        int maxProfit = 0;

        while (rightPointer < prices.size() - 1){
            rightPointer++;

            if (prices[rightPointer] < prices[leftPointer]){
                leftPointer = rightPointer;
            }

            maxProfit = max(maxProfit, prices[rightPointer] - prices[leftPointer]);
        }
        

        return maxProfit;
    }
};

class Solution {
public:
    int maxProfit(vector<int>& prices) {

        int lowestPrice = prices[0];
        int currentPrice = 0;
        int myProfit = 0;

        for (int i = 0; i < prices.size(); i++){
            lowestPrice = min(lowestPrice, prices[i]);

            int currentProfit = prices[i] = lowestPrice;

            maxProfit = max(maxProfit, currentProfit);


        }

        
        return maxProfit;
    }
};

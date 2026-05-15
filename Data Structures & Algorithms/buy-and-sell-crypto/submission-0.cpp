class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int left = 0;
        int right = 1;
        int max_profit = 0;



            while (right != prices.size()){

                if (prices[right] < prices[left]){
                    left = right;
                } else{
                    int profit = prices[right] - prices[left];
                    max_profit = max(max_profit, profit);
                }


                right++;
            }


        return max_profit;
    }
};

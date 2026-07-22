class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int sumGas = 0;
        int sumCost = 0;

        for (int i = 0; i < gas.size(); i++){
            sumGas += gas[i];
            sumCost+= cost[i];
        }

        // if total gas is less than total cost, we can't do it, return -1
        if (sumGas < sumCost){
            return -1;
        }

        int totalSum = 0;
        int startIndex = 0;

        // Loop through gas (cost will be same size, so you're looping through both essentially)
        for (int i = 0; i < gas.size(); i++){
            // Make total sum = gas - cost;
            totalSum += (gas[i] - cost[i]);

            // If total sum ever goes negative, just reset it to 0 and start at the next index.
            if (totalSum < 0){
                totalSum = 0;
                // move start index forward by one
                startIndex = i + 1;
            }
        }
        

        return startIndex;
    }
};

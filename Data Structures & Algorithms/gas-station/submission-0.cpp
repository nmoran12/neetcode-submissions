class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        // if total gas is less than total cost, we can't do it, return -1
        if sum(gas) < sum(cost){
            return -1;
        }

        int total = 0;
        int index = 0;
        int startIndex = 0;

        for (int i = 0; i < gas.size(); i++){
            total += (gas[i] - cost[i]);

            if (total < 0){
                total = 0;
                // move start index forward by one
                startIndex = i + 1;
            }
        }
        

        return startIndex;
    }
};

class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {

        stack<int> myStack;

        vector<int> results(temperatures.size(), 0);


    for (int i = 0; i < temperatures.size(); i++){

            while (!myStack.empty() && temperatures[i] > temperatures[myStack.top()]){

                int pastIndex = myStack.top();
                myStack.pop();
                results[pastIndex] = i - pastIndex;
            }

        myStack.push(i);
        };

        return results;
    }
};

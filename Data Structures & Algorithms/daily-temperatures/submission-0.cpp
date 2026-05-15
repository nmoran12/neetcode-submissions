class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        stack<int> myStack;
        int n = temperatures.size();
        vector<int> results(n, 0);


        for (int i = 0; i < n; i++){
            while (!myStack.empty() && temperatures[i] > temperatures[myStack.top()]){
                int index = myStack.top();
                myStack.pop();
                results[index] = i - index;
            }
            myStack.push(i);
        }

        return results;
    }
};

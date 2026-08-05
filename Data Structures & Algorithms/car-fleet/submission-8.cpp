class Solution {
public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        int n = position.size();

        stack<double> myStack;

        vector<int> timeToTarget;
        vector<pair<int, int>> myCars(n);

        for (int i = 0; i < n; i++){
            myCars[i] = {position[i], speed[i]};
        }
        
        sort(myCars.rbegin(), myCars.rend());

        for (const auto& car : myCars){
            double time = static_cast<double>(target - car.first) / car.second;
            myStack.push(time);

            if (myStack.size() >= 2){
                double currentCarTime = myStack.top();
                myStack.pop();
                double leadFleetTime = myStack.top();

                if (currentCarTime > leadFleetTime){
                    myStack.push(currentCarTime);
                }
            }
        }

        return myStack.size();
    }
};

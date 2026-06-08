class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        priority_queue<int> maxHeap;
        unordered_map<int, int> frequencyTable;
        queue<pair<int, int>> myQueue;

        int globalTime = 0;

        for (int i = 0; i < tasks.size(); i++){
            frequencyTable[tasks[i]]++;
        }

        for (auto c : frequencyTable){
            maxHeap.push(c.second);

        }

        while (!maxHeap.empty() || !myQueue.empty()){
            globalTime++;
            int currentFrequency = 0;


            // If there are elements in the max heap:
            if (!maxHeap.empty()){
                int currentFrequency = maxHeap.top();
                maxHeap.pop();
                currentFrequency--;

                if (currentFrequency > 0){
                    myQueue.push({currentFrequency, globalTime + n});
                };
            }

            if (!myQueue.empty() && myQueue.front().second == globalTime){
                maxHeap.push(myQueue.front().first);
                myQueue.pop();
            }

        }

        return globalTime;
    }
};

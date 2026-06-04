class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        // Pair: First - Frequency, Second - Remaining time til it can be used again
        queue<pair<int, int>> myQueue;
        priority_queue<int> maxHeap;
        unordered_map<int, int> frequencyTable;

        for (int chars : tasks){
            frequencyTable[chars]++;
        }

        // Increments by 1 each loop
        int globalTime = 0;

        int ready_time = 0;

        // Populate max heap with the tasks values
        for (auto& values : frequencyTable){
            maxHeap.push(values.second);
        }

        while (!maxHeap.empty() || !myQueue.empty()){


            if (!maxHeap.empty()){
                    int currentFrequency = maxHeap.top();
                    maxHeap.pop();

                    currentFrequency--;


                    if (currentFrequency > 0){
                        myQueue.push({currentFrequency, globalTime + n});
                    }

            }
            

            // If value at front of queue is ready, push new value from heap to queue, pop from queue.
            if (!myQueue.empty() && globalTime == myQueue.front().second){
                maxHeap.push(myQueue.front().first);
                myQueue.pop();
            }


            globalTime++;
        }
        

        return globalTime;
    }
};

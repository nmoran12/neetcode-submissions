class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {

        priority_queue<int> maxHeap;
        
        // Pair: {remaining frequency, readyTime}
        queue<pair<int, int>> myQueue;
        unordered_map<char, int> hashMap;

        int cycleStep = 0;

        // Push cpu task and its frequency into the max heap
        for (int i = 0; i < tasks.size(); i++){
            hashMap[tasks[i]]++;
        }

        // Then take the frequency of each cpu task and push into the max heap
        for (auto pair : hashMap){
            maxHeap.push(pair.second);
        }


        while (!maxHeap.empty() || !myQueue.empty()){
            cycleStep++;

            // Check the queue, if the front task is available, then push it back into the max heap.
            while (!myQueue.empty() && myQueue.front().second <= cycleStep){
                maxHeap.push(myQueue.front().first);
                myQueue.pop();
            }

            if (!maxHeap.empty()){
            int frequency = maxHeap.top();
            frequency--;
            maxHeap.pop();

            if (frequency > 0){
            // Push remaining frequency and readyTime into queue
            myQueue.push({frequency, cycleStep + n + 1});
            };
            };
        }
        

        return cycleStep;
    }
};

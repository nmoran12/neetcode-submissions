class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        priority_queue<int> maxHeap;
        int x = 0;
        int y = 0;
        int i = 0;
        // left child = 2 * i + 1
        // right child = 2 * i + 2

        int k = 2;

        // Add all the values to the max heap
        for (int i = 0; i < stones.size(); i++){
            maxHeap.push(stones[i]);
        }

        // We continue until there is no more than one stone remaining, hence size > 1
        while (maxHeap.size() > 1){

            // Put largest value into y, pop it
            int y = maxHeap.top();
            maxHeap.pop();

            // Put new largest value into x (which is second largest overall since largest had been popped earlier), pop this
            int x = maxHeap.top();
            maxHeap.pop();

            // We have already removed x and y from maxHeap, so dont have to remove again
            // Just add y = y - x back if x != y
            if (x != y){
                maxHeap.push(y - x);
            }
        }

        if (maxHeap.empty()){
            return 0;
        }


        return maxHeap.top();
    }
};

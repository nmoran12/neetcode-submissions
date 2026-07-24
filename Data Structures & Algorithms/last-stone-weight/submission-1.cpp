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

        for (int i = 0; i < stones.size(); i++){
            maxHeap.push(stones[i]);
        }

        while (maxHeap.size() > 1){

            int y = maxHeap.top();
            maxHeap.pop();

            int x = maxHeap.top();
            maxHeap.pop();

            if (x != y){
                maxHeap.push(y - x);
            }
        }


        return maxHeap.top();
    }
};

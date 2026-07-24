class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {

        priority_queue<int> maxHeap;

        // Get all stones and push into max heap
        for (int i = 0; i < stones.size(); i++){
            maxHeap.push(stones[i]);
        }

        int stoneX = 0;
        int stoneY = 0;

        while (maxHeap.size() > 1){

            stoneY = maxHeap.top();
            maxHeap.pop();
            stoneX = maxHeap.top();
            maxHeap.pop();

            if (stoneY == stoneX){
                continue;
            }

            if (stoneY > stoneX){
                stoneY = stoneY - stoneX;
                maxHeap.push(stoneY);
            }

        }

        if (maxHeap.empty()){
            return 0;
        } else {
            return maxHeap.top();
        }
    }
};

class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {

        priority_queue<int> maxHeap;

        // Get all stones and push into max heap
        for (int i = 0; i < stones[i]; i++){
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
                std::erase(stones, stoneY);
                std::erase(stones, stoneX);
            }

            if (stoneY > stoneX){
                stoneY = stoneY - stoneX;
                std::erase(stones, stoneX);
                maxHeap.push(stoneY);
            }

        }
        
        return stones;
    }
};

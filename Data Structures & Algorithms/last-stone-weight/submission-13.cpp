class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {

        unordered_map<int, int> maxHeap;

        // Get all stones and push into max heap
        for (int i = 0; i < stones[i]; i++){
            maxHeap.insert(stones[i]);
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
                maxHeap.insert(stoneY);
            }

        }
        
        return maxHeap.top();
    }
};

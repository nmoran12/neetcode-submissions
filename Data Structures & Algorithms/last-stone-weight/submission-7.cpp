class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        // Declare max heap
        priority_queue<int> myHeap;
        vector<int> twoStones;

        // Push stones into max heap
        for (int nums : stones){
            myHeap.push(nums);
        }

        // Two heaviest stones is root + left child
        for (int i = 0; i < stones.size(); i++){

            for (int j = 0; j < 2; j++){
                int first = maxHeap.top();
                maxHeap.pop();
                int second = maxHeap.top();
                maxHeap.pop();
                if (second < first){
                    maxHeap.push(first - second);
                }
            }
        }

        maxHeap.push(0);
        return maxHeap.top();
        
    }
};

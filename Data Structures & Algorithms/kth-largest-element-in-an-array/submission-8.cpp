class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {

        std::priority_queue<int, std::vector<int>, std::greater<int>> minHeap;

        for (int values : nums){
            if (minHeap.size() > k){
                minHeap.pop();
            }

                        minHeap.push(values);
        }
        
        return minHeap.top();
    }
};

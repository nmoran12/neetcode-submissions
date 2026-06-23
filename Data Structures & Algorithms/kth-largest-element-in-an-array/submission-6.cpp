class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {

        std::priority_queue<int, std::vector<int>, std::greater<int>> minHeap;

        for (int values : nums){
            minHeap.push(values);
        }

        while (minHeap.size() > k){
            minHeap.pop();
        }
        
        return minHeap.top();
    }
};

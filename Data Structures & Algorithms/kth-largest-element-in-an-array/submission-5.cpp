class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {

        std::priority_queue<int, std::vector<int>, std::greater<int>> minHeap;

        for (int i = 0; i < k; i++){
            minHeap.push(nums[i]);
        }
        
        return minHeap.top();
    }
};

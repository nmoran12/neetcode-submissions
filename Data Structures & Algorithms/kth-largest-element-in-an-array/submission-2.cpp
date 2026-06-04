class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {

        // Min Heap:
        std::priority_queue<int, std::vector<int>, std::greater<int>> minHeap;

        // Add k number of initial values so we have a full heap to start working with
        for (int j = 0; j < k; j++){
            minHeap.push(nums[j]);
        }

        // Loop through nums, adding largest k values to minHeap.
        for (int i = k; i < nums.size(); i++){

            if (minHeap.top() <= nums[i]){
                if (minHeap.size() == k){
                    minHeap.pop();
                };
                    minHeap.push(nums[i]);
            };
        }
        
        return minHeap.top();
    }
};

class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> frequency;
        std::priority_queue<std::pair<int, int>, std::vector<pair<int, int>>, std::greater<pair<int, int>>> minHeap;
        vector<int> results;

        for (int numbers : nums){

            frequency[numbers]++;
        }

        for (auto& [nums, frequency] : frequency){
            minHeap.push({nums, frequency});
            if (maxHeap.size() > k){
                minHeap.pop();
            }
        }

        while (!minHeap.empty()){
            results.push_back(minHeap.top().second());
            minHeap.pop();
        }
        

        return results;
    }
};

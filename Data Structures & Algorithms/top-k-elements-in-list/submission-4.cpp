class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> frequency;
        std::priority_queue<std::pair<int, int>, std::vector<int>, std::greater<int>> minHeap;
        vector<int> results;

        for (int numbers : nums){

            frequency[numbers]++;
        }

        for (auto& [number, frequency] : frequency){
            minHeap.push({frequency, number});
        }

        for (int i = 0; i < k; i++){
            minHeap.top();

            results.push_back(minHeap.second());
        }
        

        return results;
    }
};

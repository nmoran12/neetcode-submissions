class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> hashSet;
        vector<vector<int>> buckets(nums.size() + 1);
        vector<int> results;
        pair<int, int> newPair;

        // forgot to loop through nums to insert each value with its frequency
        for (int i  = 0; i < nums.size(); i++){
            hashSet[nums[i]]++;
        }


        for (auto& pair : hashSet){
            int key = pair.first;
            int value = pair.second;

            buckets[value].push_back(key);
        }


        for (int i = buckets.size() - 1; i >= 0; i--){
            for (int j = 0; j < buckets[i].size(); j++){
                results.push_back(buckets[i][j]);

                if (results.size() == k){
                    return results;
                }
            }

        }


        return results;
        
    }
};

class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {

        unordered_map<int, int> hashMap;
        vector<vector<int>> buckets(nums.size() + 1);
        vector<int> results;


        for (int i = 0; i < nums.size(); i++){
            hashMap[nums[i]]++;
        }


        for (auto& pair : hashMap){
            int first = pair.first;
            int second = pair.second;


            buckets[second].push_back(first);
        }

        for (int i = buckets.size() - 1; i >= 0; i--){

            for (int j = 0; j < buckets[i].size(); j++){
                results.push_back(buckets[i][j]);


                if (results.size() > k - 1){
                    return results;
                }
            }



        }



        return results;
    }
};

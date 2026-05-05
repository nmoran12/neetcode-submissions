class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        

        unordered_map<int, int> hashMap;
        // FORGOT: to declare the size of the bucket, so we must do (nums.size() + 1)
        vector<vector<int>> buckets(nums.size() + 1);
        vector<int> results;


        for (int i = 0; i < nums.size(); i++){
            // This is redundant due to the hashMap[nums]++, so we can remove it: hashMap.insert(nums[i]); 

            hashMap[nums[i]]++;
        }

        for (auto& pair : hashMap){
            // Close, but wrong, 'pair' in C++ has .first and .second for accessing {first, second} in the pair, so use those.
            //int first = pair.key;
            //int second = pair.value;

            // should be:
            int first = pair.first;
            int second = pair.second;

            // incorrect: buckets.push_back(hashMap[i][j]);

            // correct: we put the number into the index that matches its frequency
            // e.g. if number 5 occurs 3 times, we put number 5 at index 3
            buckets[second].push_back(first);
        }


        for (int i = buckets.size() - 1; i >= 0; i--){
            // must have a smaller inner loop to add values from buckets -> results.

            // An index can have multiple values in it, e.g. if 2, 5, 7 have frequency 3, they can all be index 3,
            // so this loops through one entire index for all the values in it.
            for (int j = 0; j < buckets[i].size(); j++){
            results.push_back(buckets[i][j]);

            if (results.size() > k - 1){
                return results;
            };
            };



        }
    }
};

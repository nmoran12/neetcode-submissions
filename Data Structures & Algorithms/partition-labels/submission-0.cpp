class Solution {
public:
    vector<int> partitionLabels(string s) {

        vector<int> hashMap(26);

        // Go through hash map and map every last index to each char
        for (int i = 0; i < s.length(); i++){
            hashMap[s[i] - 'a'] = i;
        }

        vector<int> result;
        int sizeOfPartition = 0;
        int endOfPartition = 0;

        for (int i = 0; i < s.length(); i++){
            sizeOfPartition++;
            endOfPartition = max(endOfPartition, hashMap);

            if (i == endOfPartition){
                result.push_back(sizeOfPartition);
                sizeOfPartition = 0;
            }
        }

        return result;

        
    }
};

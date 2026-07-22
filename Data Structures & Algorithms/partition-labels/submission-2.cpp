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

        // Loop through string
        for (int i = 0; i < s.length(); i++){
            // Increment size of partition each time we loop again
            sizeOfPartition++;

            // Our current partition must include every instance of a char that is within it
            // If a char's last index is beyond the current partition's end, we must expand the partition to include it
            endOfPartition = max(endOfPartition, hashMap[s[i] - 'a']);

            // We have reached the end of all the overlapping intervals
            if (i == endOfPartition){
                result.push_back(sizeOfPartition);
                sizeOfPartition = 0;
            }
        }

        return result;

        
    }
};

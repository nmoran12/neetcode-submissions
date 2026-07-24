class Solution {
public:
    vector<int> partitionLabels(string s) {

        vector<int> hashMap(26);

        vector<int> result;
        int sizeOfPartition = 0;
        int endOfPartition = 0;

        for (int i = 0; i < s.length(); i++){
            hashMap[s[i] - 'a'] = i;
        }

        for (int i = 0; i < s.length(); i++){
            sizeOfPartition++;

            endOfPartition = max(endOfPartition, hashMap[s[i] - 'a']);

            if (i > endOfPartition){
                result.push_back(sizeOfPartition);
                sizeOfPartition = 0;

            }



        }
        
        return result;
    }
};

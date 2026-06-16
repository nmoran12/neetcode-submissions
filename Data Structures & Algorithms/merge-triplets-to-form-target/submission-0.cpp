class Solution {
public:
    bool mergeTriplets(vector<vector<int>>& triplets, vector<int>& target) {
        map<int, int> freqTable;
        bool results1 = false;
        bool results2 = false;
        bool results3 = false;

        for (int i = 0; i < triplets.size(); i++){

            if (triplets[i][0] > target[0] || triplets[i][1] > target[1] || triplets[i][2] > target[2]){
                continue;
            }

            if (triplets[i][0] == target[0]){
                results1 = true;
            }
            
            if (triplets[i][1] == target[1]){
                results2 = true;
            }
            
            if (triplets[i][2] == target[2]){
                results3 = true;
            }

        }

                    return results1 && results2 && results3;
    }
};

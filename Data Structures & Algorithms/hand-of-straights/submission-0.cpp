class Solution {
public:
    bool isNStraightHand(vector<int>& hand, int groupSize) {

        map<int, int> freqTable;

        for (int card : hand){
            freqTable[card]++;
        }

        for (auto& [card, count] : freqTable){
            if (count > 0){
                int needed_groups = count;

            for (int i = 0; i < groupSize; i++){

                int current_card = card + i;

                if (freqTable[current_card] < needed_groups){
                    return false;
                }

                freqTable[current_card] -= needed_groups;
            }

            }
        }

        return true;
        
    }
};

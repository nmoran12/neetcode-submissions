class Solution {
public:
    bool isNStraightHand(vector<int>& hand, int groupSize) {
        if (hand.size() % groupSize != 0) return false;

        // Put into frequency table, and maps are already sorted, so don't need to sort again
        map<int, int> freqTable;

        // Fill frequency table with the count of each value
        for (int card : hand){
            freqTable[card]++;
        }


        // Loop through freqTable
        for (auto& [card, count] : freqTable){
            // If a value's count is > 0, 
            if (count > 0){

                // then set needed_groups to count (because that is how many groups we will need to make with that number at start of each group)
                int needed_groups = count;

            // For size of groupSize, loop and check if each consecutive number ahead has count smaller than needed_groups.
            for (int i = 0; i < groupSize; i++){

                // The current card we are looking at is 'card here' and then add 'i' to it as we move
                int current_card = card + i;

                // For a map, freqTable[current_card] finds the KEY at that position, then returns the VALUE
                // So if we have value 2 with frequency 3, its {2, 3}, so it finds {2} and then returns the {3}.
                if (freqTable[current_card] < needed_groups){
                    return false;
                }

                // If valid, decrement needed_groups from the count of that card, cos we used up that many counts of it.
                freqTable[current_card] -= needed_groups;
            }

            }
        }

        // Return true outside it.
        return true;
        
    }
};

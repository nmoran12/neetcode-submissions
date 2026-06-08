class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        if (s1.length() > s2.length()) return false;

        unordered_map<int, int> frequencyTable_s1;
        unordered_map<int, int> frequencyTable_s2;
        vector<int> substring; // Unused, but kept from your layout

        for (int i = 0; i < s1.length(); i++){
            frequencyTable_s1[s1[i]]++;
            frequencyTable_s2[s2[i]]++;
        }

        if (frequencyTable_s1 == frequencyTable_s2){
            return true;
        }

        for (int right = s1.length(); right < s2.length(); right++){
            // 1. Add the incoming right character
            frequencyTable_s2[s2[right]]++;
            
            // 2. Target the outgoing left character directly
            int leftPointer = right - s1.length();
            char leftChar = s2[leftPointer];
            
            // 3. Decrement its count
            frequencyTable_s2[leftChar]--;
            
            // FIX: Erase the key if its frequency drops to 0
            if (frequencyTable_s2[leftChar] == 0) {
                frequencyTable_s2.erase(leftChar);
            }

            if (frequencyTable_s1 == frequencyTable_s2){
                return true;
            }
        }

        return false;
    }
};

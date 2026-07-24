class Solution {
public:

    void helper(string digits, unordered_map<int, char>& myDigits, int i, vector<int>& subset, vector<vector<int>>& results, vector<bool> used(digits.size(), false)){
        // Base Case 1: If size of subset = digit size, i.e. we have made our full subset, push subset to results
        if (subset.size() == digits.size()){
            results.push_back(subset);
            return;
        }

        for (int nums : digits){
            myDigits[nums]++;
        }

        for (int i = 0; i < digits.size(); i++){
            // Base Case 2: if we have already used the nums, continue
            if (used[i] == true){
                continue;
            }

            // CHOOSE:
            used[i] = true;
            subset.push_back(digits[i]);

            // EXPLORE:
            helper(digits, myDigits, i, subset, results);

            // UNDO:
            subset.pop_back();
            used[i] = false;
        }



    }


    vector<string> letterCombinations(string digits) {
        unordered_map<int, char> myDigits;
        vector<int> subset;
        vector<vector<int>> results;
        vector<bool> used(digits.size(), false);


        helper(digits, myDigits, 0, subset, results);


        return myDigits;
    }
};

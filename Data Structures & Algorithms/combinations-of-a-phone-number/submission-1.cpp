class Solution {
public:

    void helper(string digits, unordered_map<int, char>& myDigits, int i, vector<int>& subset, vector<vector<int>>& results){
        // Base Case 1: If size of subset = digit size, i.e. we have made our full subset, push subset to results
        if (subset.size() == digits.size()){
            results.push_back(subset);
            return;
        }

        for (int nums : digits){
            myDigits[nums]++;
        }

        // Choose:
        subset.push_back(digits[i]);

        // Explore:
        helper(digits, myDigits, i, subset, results);
        subset.pop_back();

        // Undo:
        helper(digits, myDigits, i + 1, subset, results);




    }


    vector<string> letterCombinations(string digits) {
        unordered_map<int, char> myDigits;
        vector<int> subset;
        vector<vector<int>> results;


        helper(digits, myDigits, 0, subset, results);


        return myDigits;
    }
};

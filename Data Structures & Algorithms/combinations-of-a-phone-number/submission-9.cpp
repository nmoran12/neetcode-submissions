class Solution {
public:

    void helper(string digits, unordered_map<char, string>& myDigits, int i, string& currentString, vector<string>& results){

        // Base Case 1: If current string length equals digit.legnth, add to results and return
        if (currentString.length() == digits.size()){
            results.push_back(currentString);
            return;
        }

        char currentDigits = digits[i];

        string letters = myDigits[currentDigits];

        for (char letter : letters){

            // CHOOSE:
            currentString.push_back(letter);

            // EXPLORE:
            helper(digits, myDigits, i + 1, currentString, results);

            // UNDO:
            currentString.pop_back();
        }



    }


    vector<string> letterCombinations(string digits) {
        unordered_map<char, string> myDigits = {
            {2, "abc"},
            {3, "def"},
            {4, "ghi"},
            {5, "jkl"},
            {6, "mno"},
            {7, "pqrs"},
            {8, "tuv"},
            {9, "wxyz"}
        };
        vector<string> results;
        string currentString = "";


        helper(digits, myDigits, 0, currentString, results);


        return results;
    }
};

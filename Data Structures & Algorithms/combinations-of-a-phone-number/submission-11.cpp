class Solution {
public:
    void helper(
        string& digits,
        unordered_map<char, string>& myDigits,
        int i,
        string& currentString,
        vector<string>& results
    ) {
        if (currentString.length() == digits.size()) {
            results.push_back(currentString);
            return;
        }

        char currentDigit = digits[i];
        string letters = myDigits[currentDigit];

        for (char letter : letters) {
            currentString.push_back(letter);

            helper(digits, myDigits, i + 1, currentString, results);

            currentString.pop_back();
        }
    }

    vector<string> letterCombinations(string digits) {
        if (digits.empty()) {
            return {};
        }

        unordered_map<char, string> myDigits = {
            {'2', "abc"},
            {'3', "def"},
            {'4', "ghi"},
            {'5', "jkl"},
            {'6', "mno"},
            {'7', "pqrs"},
            {'8', "tuv"},
            {'9', "wxyz"}
        };

        vector<string> results;
        string currentString = "";

        helper(digits, myDigits, 0, currentString, results);

        return results;
    }
};

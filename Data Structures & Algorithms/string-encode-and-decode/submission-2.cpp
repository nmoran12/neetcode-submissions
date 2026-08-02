class Solution {
public:

    string encode(vector<string>& strs) {
        string result = "";

        for (const string& str : strs){
            // Combine Length + # + string
            result += to_string(str.size()) + "#" + str;
        }

        return result;
    }

    // Converts single string back to list of strings
    // e.g. "applebananapie" -> "apple, banana, pie"
    vector<string> decode(string s) {

        vector<string> result;
        int i = 0;

        // 1. Locate the '#' delimiter starting from index i
        while (i < s.size()){
            int j = i;
            while (s[j] != '#'){
                j++;
            }

            // 2. Get length prefix
            int length = stoi(s.substr(i, j - i));

            // 3. Move j past the '#' to the beginning of the actual word
            j++;

            // 4. Extract the exact payload based on length
            string content = s.substr(j, length);
            result.push_back(content);

            // 5. Jump pointer 'i' to the start of the next encoded string
            i = j + length;
        }

        return result;
    }
};

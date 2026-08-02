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

    vector<string> decode(string s) {

        vector<string> result;
        int i = 0;

        while (i < s.size()){
            int j = i;
            while (s[j] != '#'){
                j++;
            }

            int length = stoi(s.substr(i, j - i));

            j++;

            string content = s.substr(j, length);
            result.push_back(content);

            i = j + length;
        }

        return result;
    }
};

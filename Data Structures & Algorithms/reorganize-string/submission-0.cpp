class Solution {
public:
    string reorganizeString(string s) {

        unordered_map<char, int> frequency;

        // Take chars from string and add them to hash map, with frequency
        for (auto vals : s){
            frequency[vals]++;
        }

        priority_queue<pair<int, char>> myHeap;

        for (int i = 0; i < frequency.size(); i++){
            myHeap.insert({frequency.first, frequency.second});
        }

        int prev;
        string result = "";

        int previousCount = 0;
        char previousChar = ' ';

        while (!myHeap.empty()){
            auto current = myHeap.top();
            myHeap.pop();

            // Add char to result
            result += current.first;
            // Decrement its frequency
            current.second--;

            // previous character has now waited 1 turn, so we can do it again
            if (previous.first > 0){
                maxHeap.push({previousCount, previousChar});
            }

            // Store current character outside the heap
            previous = current;
        }



        if (result.size() != s.size()){
            return "";
        }
        
        return result;
    }
};
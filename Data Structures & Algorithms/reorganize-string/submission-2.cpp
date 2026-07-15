class Solution {
public:
    string reorganizeString(string s) {
        unordered_map<char, int> frequency;

        // Count the frequency of each character.
        for (char value : s) {
            frequency[value]++;
        }

        // Stores {frequency, character}.
        priority_queue<pair<int, char>> myHeap;

        // Add every character and its count to the max heap.
        for (auto entry : frequency) {
            myHeap.push({entry.second, entry.first});
        }

        string result = "";

        // Character currently being held outside the heap.
        int previousCount = 0;
        char previousChar = ' ';

        while (!myHeap.empty()) {
            auto current = myHeap.top();
            myHeap.pop();

            // Use the current character.
            result += current.second;
            current.first--;

            // The previous character has now waited one turn.
            if (previousCount > 0) {
                myHeap.push({previousCount, previousChar});
            }

            // Hold the current character outside the heap.
            previousCount = current.first;
            previousChar = current.second;
        }

        // Some characters could not be placed.
        if (result.size() != s.size()) {
            return "";
        }

        return result;
    }
};
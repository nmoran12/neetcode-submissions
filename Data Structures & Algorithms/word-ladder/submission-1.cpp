class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        unordered_set<string> wordSet(wordList.begin(), wordList.end());

        // If 'endWord' is not in the list, the answer is impossible, return 0
        if (wordSet.find(endWord) == wordSet.end()){
            return 0;
        }

        int wordLength = beginWord.size();

        // Stores: pattern -> all words matching that pattern
        unordered_map<string, vector<string>> patternToWords;

        queue<pair<string, int>> myQueue;
        unordered_set<string> visited;

        for (string word : wordList){ // Loop through each word
            for (int i = 0; i < wordLength; i++){ // Loop through each char in that word
                string pattern = word; // Make a copy of the word
                pattern[i] = '*'; // Replace one character with '*'

                // Add 'hot' to the list of words that match the pattern '*ot'
                // Do same for 'h*t', 'ho*', same for all other words and patterns.
                patternToWords[pattern].push_back(word);
            }
        }

        // Queue stores: Current Word, Number of Words used so far
        // So it would start with: {hit, 1}, for example
        myQueue.push({beginWord, 1});
        visited.insert(beginWord);

        // Start of BFS Loop
        while (!myQueue.empty()){
            // Get next thing to process, pop it
            auto [word, count] = myQueue.front();
            myQueue.pop();

            // If we have reached the end word, return num. of words in path
            if (word == endWord){
                return count;
            }

            // Find neighbours from matching patterns
            // Take current word -> create patterns -> find matching words
            // -> mark visited -> push into queue to be processed
            for (int i = 0; i < wordLength; i++){
                string pattern = word;
                pattern[i] = '*';

                for (string neighbour : patternToWords[pattern]){
                    // Search 'visited' to find neighbour, if you reach end of visited without
                    // finding it, then neighbour is not in visited
                    if (visited.find(neighbour) == visited.end()){
                        visited.insert(neighbour);
                        myQueue.push({neighbour, count + 1});
                    }
                }
            }
        }


        return 0;        
    }
};

class WordDictionary {
public:
    struct TrieNode {
        bool isEndOfWord;
        TrieNode* children[26];

        TrieNode() {
            isEndOfWord = false;
            for (int i = 0; i < 26; i++) {
                children[i] = nullptr;
            }
        }
    };

    TrieNode* root;

    WordDictionary() {
        root = new TrieNode();
    }
    
    void addWord(string word) {
        TrieNode* curr = root;
        for (char ch : word) {
            int index = ch - 'a';
            if (curr->children[index] == nullptr) {
                curr->children[index] = new TrieNode();
            }
            curr = curr->children[index];
        }
        curr->isEndOfWord = true; // Dropped flag correctly here
    }
    
    bool search(string word) {
        // We call a recursive helper function starting at index 0 from the root
        return dfsSearch(word, 0, root);
    }

private:
    // Recursive helper to handle the wildcard branching logic
    bool dfsSearch(const string& word, int stringIdx, TrieNode* curr) {
        // Base Case: If we matched all characters, check if it's a valid word
        if (stringIdx == word.length()) {
            return curr->isEndOfWord;
        }

        char ch = word[stringIdx];

        // CASE A: The Wildcard Dot
        if (ch == '.') {
            // We must try to go down every single valid pointer path available
            for (int i = 0; i < 26; i++) {
                if (curr->children[i] != nullptr) {
                    // Move to the next char index using the valid child node
                    if (dfsSearch(word, stringIdx + 1, curr->children[i])) {
                        return true; 
                    }
                }
            }
            return false; // None of the 26 paths worked out
        } 
        
        // CASE B: A Regular Character (Your standard template logic)
        else {
            int index = ch - 'a';
            if (curr->children[index] == nullptr) {
                return false;
            }
            return dfsSearch(word, stringIdx + 1, curr->children[index]);
        }
    }
};

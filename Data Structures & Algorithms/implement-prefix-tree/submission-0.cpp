class PrefixTree {
public:

    struct TrieNode{
            // Declare to have 26 potential children (one for each letter of alphabet)
            TrieNode* children[26];
            // Declare checker for if we are at the end of a word
            bool isEndOfWord;


            TrieNode(){

            // set this to false by default
            isEndOfWord = false;

            // set each 26 children to nullptr i.e. empty
            for (int i = 0; i < 26; i++){
                children[i] = nullptr;
                }
            }
        };

    TrieNode* root;

    PrefixTree(){
        root = new TrieNode();
    }
    
    void insert(string word) {

        TrieNode* curr = root;
        
        for (char c : word){
            int index = c - 'a';

            if (curr->children[index] == nullptr){
                curr->children[index] = new TrieNode();
            }
            curr = curr->children[index];


        }


        curr->isEndOfWord = true;
    }
    
    bool search(string word) {
        TrieNode* curr = root;

        for (char c : word){
            int index = c - 'a';

            if (curr->children[index] == nullptr){
                return false;
            }
            curr = curr->children[index];
        }
        

        return curr->isEndOfWord;
    }
    
    bool startsWith(string prefix) {
        TrieNode* curr = root;

        for (char c : prefix){
            int index = c - 'a';

            if (curr->children[index] == nullptr){
                return false;
            }
            curr = curr->children[index];

        }

        return true;
    }
};

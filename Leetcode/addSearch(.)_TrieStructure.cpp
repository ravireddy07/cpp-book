class TrieNode{
    public:
        vector<TrieNode*> next;
        bool isWord = false;
        TrieNode(){
            next.resize(26, NULL);
        }
};

class WordDictionary {
public:
    /** Initialize your data structure here. */
    TrieNode* root;
    WordDictionary() {
        root = new TrieNode();
    }
    
    /** Adds a word into the data structure. */
    void addWord(string word) {
        TrieNode* current = root;
        for(char ch:word){
            if(!current->next[ch - 'a']){
                current->next[ch - 'a'] = new TrieNode();
            }
            current = current->next[ch - 'a'];
        }
        current->isWord = true;
    }
    
    /** Returns if the word is in the data structure. A word could contain the dot character '.' to represent any one letter. */
    bool search(string word) {
        return searchHelper(word, root);
    }
private:
    
    bool searchHelper(string word, TrieNode* current) {
        for(int i = 0; i < word.size(); i++){
            char ch = word[i];
            if(ch != '.'){
                if(!current->next[ch - 'a']) 
                    return false;
                current = current->next[ch - 'a'];
            }
            else{
                for(int j = 0; j < 26; j++){
                    if(current->next[j] && searchHelper(word.substr(i + 1), current->next[j])){
                        return true;
                    }
                }
                return false;
            }
        }
        return current->isWord;
    }
};
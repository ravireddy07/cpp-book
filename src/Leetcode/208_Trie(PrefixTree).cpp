// https://leetcode.com/problems/implement-trie-prefix-tree/

/*
Examples:
addWord("bad")
addWord("dad")
addWord("mad")
search("pad") -> false
search("bad") -> true
search(".ad") -> true
search("b..") -> true
*/

class Trie
{
public:
    struct node
    {
        char c;
        int ends;
        string word;
        struct node *child[26];
    };

    node *newNode(char c)
    {
        node *temp = new node;
        temp->c = c;
        temp->ends = 0;
        temp->word = "";
        for (int i = 0; i < 26; i++)
            temp->child[i] = NULL;
        return temp;
    }

    /** Initialize your data structure here. */
    node *root = newNode('/');

    /** Inserts a word into the trie. */
    void insert(string s)
    {
        node *curr = root;
        int idx, i = 0;
        while (s[i])
        {
            idx = s[i] - 'a';
            if (curr->child[idx] == NULL)
                curr->child[idx] = newNode(s[i]);
            curr = curr->child[idx];
            i++;
        }
        curr->ends++;
        curr->word = s;
    }

    /** Returns if the word is in the trie. */
    bool search(string s)
    {
        node *curr = root;
        int idx, i = 0;
        while (s[i])
        {
            idx = s[i] - 'a';
            if (curr->child[idx] == NULL)
                return false;
            curr = curr->child[idx];
            i++;
        }
        if (curr->ends > 0)
            return true;
        return false;
    }

    /** Returns if there is any word in the trie that starts with the given prefix. */
    bool startsWith(string prefix)
    {
        node *curr = root;
        int idx, i = 0;
        for (int i = 0; i < prefix.length(); i++)
        {
            idx = prefix[i] - 'a';
            if (!curr->child[idx])
                return false;
            curr = curr->child[idx];
        }
        return true;
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */
class Trie {
    struct TrieNode 
    {
        map<char, TrieNode*>child_table;
        int end;
        TrieNode(): end(0) {}
    };
        
public:
    Trie() {
        root = new TrieNode();
    }

    // Inserts a word into the trie.
    void insert(string s) {
        TrieNode *curr = root;
        for (int i = 0; i < s.size(); i++)
        {
            if (curr->child_table.count(s[i]) == 0)
                curr->child_table[s[i]] = new TrieNode();
                
            curr = curr->child_table[s[i]];                
        }
        curr->end = 1;
    }

    // Returns if the word is in the trie.
    bool search(string key) {
        return find(key, 1);
    }

    // Returns if there is any word in the trie
    // that starts with the given prefix.
    bool startsWith(string prefix) {
        return find(prefix, 0);
    }

private:
    TrieNode* root;
    bool find(string s, int exact_match)
    {
        TrieNode *curr = root;
        for (int i = 0; i < s.size(); i++)
        {
            if (curr->child_table.count(s[i]) == 0)
                return false;
            else
                curr = curr->child_table[s[i]];
        }
        
        if (exact_match)
            return (curr->end) ? true : false;
        else
            return true;
    }
};
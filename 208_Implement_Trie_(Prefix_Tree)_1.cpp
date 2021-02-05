class Trie {
private:
    struct TrieNode {
        unordered_map<char, TrieNode*> children;
        bool endnode;
        TrieNode() : children(), endnode(false) {}
    };
    TrieNode* root;
    int TrieFind(string s) {
        TrieNode* cur = root;
        for (auto c : s) {
            if (cur->children.count(c) == 0) {
                return -1;
            }
            cur = cur->children[c];
        }
        if (cur->endnode) {
            return 0;
        }
        else {
            return 1;
        }
    }
public:

    /** Initialize your data structure here. */
    Trie() {
        root = new TrieNode();
    }
    
    /** Inserts a word into the trie. */
    void insert(string word) {
        TrieNode *cur = root;
        for (auto c : word) {
            if (cur->children.count(c) == 0) {
                cur->children[c] = new TrieNode();
            }
            cur = cur->children[c];
        }
        cur->endnode = true;
    }
    
    /** Returns if the word is in the trie. */
    bool search(string word) {
        int ret = TrieFind(word);
        if (ret == 0) return true;
        return false;
    }
    
    /** Returns if there is any word in the trie that starts with the given prefix. */
    bool startsWith(string prefix) {
        int ret = TrieFind(prefix);
        if (ret != -1) return true;
        return false;
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */
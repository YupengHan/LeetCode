class TreeAncestor {
private:
    vector<int> mp; // my_parent;
    vector<int> max_d; // searching for max depth;
    int mnum; // nums of node
public:
    TreeAncestor(int n, vector<int>& parent) {
        mnum = n;
        mp = parent;
        max_d.insert(max_d.begin(), 0);
        
        for (int i = 1; i < mnum; i++) {
            int p = mp[i];
            max_d.insert(max_d.end(), max_d[p] + 1);
        }
        
    }
    
    int getKthAncestor(int node, int k) {
        if (k == 0) {
            return node;
        }
        
        if (k > max_d[node]) {
            return -1;
        }
        return getKthAncestor(mp[node], k-1);
        
        
    }
};

/**
 * Your TreeAncestor object will be instantiated and called as such:
 * TreeAncestor* obj = new TreeAncestor(n, parent);
 * int param_1 = obj->getKthAncestor(node,k);
 */
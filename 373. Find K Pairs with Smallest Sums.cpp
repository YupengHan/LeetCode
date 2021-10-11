class Node {
public:
    int val, i, j;
    Node (int _val, int _i, int _j) {
        val = _val;
        i = _i;
        j = _j;
    }
};
struct mp {
public:
    bool operator() (Node& a, Node& b) {
        return a.val > b.val;
    }
};

class Solution {
public:
    vector<vector<int>> kSmallestPairs(vector<int>& nums1, vector<int>& nums2, int k) {
        int m = nums1.size();
        int n = nums2.size();
        vector<vector<int>> ret;
        set<vector<int>> visited;
        priority_queue<Node, vector<Node>, mp> mQ;
        mQ.push(Node(nums1[0]+nums2[0],0, 0));

        while (ret.size() < k && !mQ.empty()) {
            Node c_node = mQ.top();
            // cout << c_node.i << " " << c_node.j << " " << c_node.val << " " << mQ.size() << endl;
            mQ.pop();
            ret.push_back({nums1[c_node.i], nums2[c_node.j]});
            
            if (c_node.i+1 < m && !visited.count({c_node.i+1, c_node.j})) {
                mQ.push(Node(nums1[c_node.i+1]+nums2[c_node.j],c_node.i+1, c_node.j));
                visited.insert({c_node.i+1, c_node.j});
            }
            if (c_node.j+1 < n && !visited.count({c_node.i, c_node.j+1})) {
                mQ.push(Node(nums1[c_node.i]+nums2[c_node.j+1],c_node.i, c_node.j+1));
                visited.insert({c_node.i, c_node.j+1});
            }
        }
        return ret;

    }
};
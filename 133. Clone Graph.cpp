/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
*/

class Solution {
public:
    Node* cloneGraph(Node* node) {
        if (node == nullptr) return nullptr;

        unordered_map<Node*, Node*> visited;
        queue<Node*> m_q;
        visited[node] = new Node(node->val);
        m_q.push(node);
        while(!m_q.empty()) {
            Node* c_o_node = m_q.front();
            m_q.pop();
            for (auto o_n : c_o_node->neighbors) {
                if (visited.find(o_n) == visited.end()) {
                    visited[o_n] = new Node(o_n->val);
                    m_q.push(o_n);
                }
                visited[c_o_node]->neighbors.push_back(visited[o_n]);
            }
        }

        return visited[node];


    }
};
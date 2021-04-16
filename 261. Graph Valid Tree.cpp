class Solution {
public:
    bool validTree(int n, vector<vector<int>>& edges) {
        vector<vector<int>> m_graph(n, vector<int>);
        vector<int> m_degree(n, 0);
        for (auto e:edges) {
            m_graph[e[0]].push_back(e[1]);
            m_graph[e[1]].push_back(e[0]);
            m_degree[e[0]] = m_degree[e[0]] + 1;
            m_degree[e[1]] = m_degree[e[1]] + 1;
        }

        vector<bool> visited(n, false);

        queue<int> m_q;
        for (int i = 0; i < n; ++i) {
            if (m_degree[i] == 1) {
                m_q.push(i);
            }
        }
        while(!m_q.empty()) {
            int c_node = m_q.front();
            m_q.pop();
            if (visited[c_node]) {
                return false;
            }
            visited[c_node] = true;
            m_degree[c_node] = 0;
            for (auto to : m_graph[c_node]) {
                m_degree[to] = m_degree[to] - 1;
                if (m_degree[to] == 1) {
                    m_q.push(to);
                }
            }

        }
        for (int i = 0; i < n; ++i) {
            if (!visited[i]) return false;
        }

        return true;
    }
};
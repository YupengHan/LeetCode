class Solution {
public:
    int countComponents(int n, vector<vector<int>>& edges) {
        vector<vector<int>> linkEdge (n);
        vector<bool> visited(n, false);
        for (auto e:edges) {
            linkEdge[e[0]].push_back(e[1]);
            linkEdge[e[1]].push_back(e[0]);
        }

        int ans = 0;
        int stNode = 0;
        


        
        while(stNode != n) {
            ans++;
            queue<int> myQueue;
            myQueue.push(stNode);
            while(!myQueue.empty()) {
                int curNode = myQueue.front();
                    
                myQueue.pop();
                visited[curNode] = 1;
                while(visited[stNode]) {
                    stNode++;
                }
                for (int to : linkEdge[curNode]) {
                    if (!visited[to]) {
                        myQueue.push(to);
                    }
                }

            }

        }

        return ans;
            
    }
};
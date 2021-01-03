class Solution {
private:
    int not_visit = 0;
    int working = 1;
    int visited = 2;

public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        // build graph
        vector<vector<int>> graph(numCourses);
        for (auto edge : prerequisites) {
            graph[edge[0]].push_back(edge[1]);
        }

        vector<int> Visit_map(numCourses, 0);

        for (int at = 0; at < numCourses; at++) {
            if (Visit_map[at] == not_visit) {
                if (!dfs(at, Visit_map, graph)) return false;    
            }
        }
        return true;
    }

    bool dfs(int at, vector<int>& Visit_map, vector<vector<int>>& graph) {
        if (Visit_map[at] == working) return false;
        Visit_map[at] = working;
        for (auto edge_to : graph[at]) {
            if (Visit_map[edge_to] == working) return false;
            if (Visit_map[edge_to] == not_visit) {
                if (!dfs(edge_to, Visit_map, graph)) return false;
            }

        }
        Visit_map[at] = visited;
        return true;
    }
};


class Solution {
private:
    int not_processed=0;
    int processing=1;
    int processed=2;
public:
    bool canFinish(int numCourses, vector<vector<int>>& prereq) {
        vector<int> visited(numCourses,0);
        
        vector<vector<int>> graph(numCourses);
        
        for(int i=0;i<prereq.size();i++){
            graph[prereq[i][0]].push_back(prereq[i][1]);
        }
        for(int i=0;i<numCourses;i++){
            if(visited[i]==not_processed){
                if(!dfs(i,graph,visited)){  //return false if cycle exist
                    return false;  
                }
            }
        }
        return true;
    }
    bool dfs(int node,vector<vector<int>>& graph,vector<int>& visited){
        if(visited[node]==processing){
            return false;
        }
        if(visited[node]==processed){
            return true;
        }
        visited[node]=processing;
        for(int i=0;i<graph[node].size();i++){
            if(!dfs(graph[node][i],graph,visited)){
                return false;
            } 
        }
        visited[node]=processed;
        return true;  //means the graph is acyclic
    }
};
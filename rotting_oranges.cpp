class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int row = grid.size();
        int col = grid[0].size();
        
        // cout << row << col;
        vector<int> time ((row*col), 100);
        
        for (int i = 0; i < row; i++) {
            for (int j = 0; j < col; j++) {
                int time_map_id = i*grid[0].size() + j;
                if (grid[i][j] == 2) {
                    dfs(i,j,grid,time, 0);
                }
                else if (grid[i][j] == 0) {
                    time[time_map_id] = 0;
                }
                
            }
        }

        int ret_max = 0;
        for (int i = 0; i < row*col; i++) {
            // cout << "i: " << i << "time[i]: " << time[i] << endl;
            // if(time[i] != 100) {
            //     ret_max = max(ret_max, time[i]);
            // }
            ret_max = max(ret_max, time[i]);
            
        }

        if (ret_max == 100) {
            return -1;
        }
        
        return ret_max;
        
        
        
    }

    void dfs(int i, int j, vector<vector<int>>& grid, vector<int>& time, int level) {
        if (i < 0 || i >= grid.size() || j < 0 || j >= grid[0].size() || grid[i][j] == 0) {
            return;
        }
        
        int time_map_id = i*grid[0].size() + j;
        // cout << time_map_id << endl;
        if (time[time_map_id] > level) {
            time[time_map_id] = level;
            dfs(i-1,j,grid,time,level+1);
            dfs(i,j-1,grid,time,level+1);
            dfs(i+1,j,grid,time,level+1);
            dfs(i,j+1,grid,time,level+1);    
        }
    }
};

/*
class Point{
public:
    int i;
    int j;
    int time;
    Point(int y,int x,int t){
        i = y;
        j = x;
        time = t;
    }
};

class Solution {
public:
    bool isValid(int i,int j,int m,int n){
        if(i<0 || i>=m || j<0 || j>=n){
            return false;
        }
        
        return true;
    }
    
    int orangesRotting(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        int fresh = 0;
        queue<Point> q;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j] == 1) fresh++;
                else if(grid[i][j] == 2){
                    Point p(i,j,0);
                    q.push(p);
                } 
            }
        }
        if(fresh==0) return 0;
        
        int min = 0;
        while(!q.empty()){
            Point p = q.front();
            q.pop();
            int i = p.i;
            int j = p.j;
            int t = p.time;
            min = max(min,t);
            if(isValid(i+1,j,m,n) && grid[i+1][j]==1){
                Point n(i+1,j,t+1);
                q.push(n);
                fresh--;
                grid[i+1][j] = 2;
            }
            if(isValid(i,j+1,m,n) && grid[i][j+1]==1){
                Point n(i,j+1,t+1);
                q.push(n);
                fresh--;
                grid[i][j+1] = 2;
            }
            if(isValid(i-1,j,m,n) && grid[i-1][j]==1){
                Point n(i-1,j,t+1);
                q.push(n);
                fresh--;
                grid[i-1][j] = 2;
            }
            if(isValid(i,j-1,m,n) && grid[i][j-1]==1){
                Point n(i,j-1,t+1);
                q.push(n);
                fresh--;
                grid[i][j-1] = 2;
            }
        }
        if(fresh != 0){
            return -1;
        }
        
        return min;
    }
};

*/


/*
更NB的

class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int n=grid.size(),m=grid[0].size(),fresh=0;
        queue<pair<int,int>> q;
        for(int i=0; i<n; ++i)
        {
            for(int j=0; j<m; ++j)
            {
                if(grid[i][j]==2)
                    q.push({i,j});
                else if(grid[i][j]==1)
                    fresh++;
            }
        }
        if(!fresh)
            return 0;
        int minutes=0,l=q.size();
        cout<<l;
        while(!q.empty())
        {
            int x=q.front().first;  int y=q.front().second; q.pop();
            if((x-1)>=0 && grid[x-1][y]==1)
            {
                grid[x-1][y]=2;
                fresh--;
                q.push({x-1,y});
            }
            if((x+1)<n && grid[x+1][y]==1)
            {
                grid[x+1][y]=2;
                fresh--;
                q.push({x+1,y});
            }
            if((y-1)>=0 && grid[x][y-1]==1)
            {
                grid[x][y-1]=2;
                fresh--;
                q.push({x,y-1});
            }
            if((y+1)<m && grid[x][y+1]==1)
            {
                grid[x][y+1]=2;
                fresh--;
                q.push({x,y+1});
            }
            l--;
            if(!l)
            {
                minutes++;
                l=q.size();
                cout<<l;
            }
        }
        return (fresh==0)?minutes-1:-1;
    }
};
*/


class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int n=grid.size(),m=grid[0].size(),fresh=0;
        queue<pair<int,int>> q;
        for(int i=0; i<n; ++i)
        {
            for(int j=0; j<m; ++j)
            {
                if(grid[i][j]==2)
                    q.push({i,j});
                else if(grid[i][j]==1)
                    fresh++;
            }
        }
        if(!fresh)
            return 0;
        int minutes=0,l=q.size();
        cout<< l << endl;
        while(!q.empty())
        {
            int x=q.front().first;  int y=q.front().second; q.pop();
            if((x-1)>=0 && grid[x-1][y]==1)
            {
                grid[x-1][y]=2;
                fresh--;
                q.push({x-1,y});
            }
            if((x+1)<n && grid[x+1][y]==1)
            {
                grid[x+1][y]=2;
                fresh--;
                q.push({x+1,y});
            }
            if((y-1)>=0 && grid[x][y-1]==1)
            {
                grid[x][y-1]=2;
                fresh--;
                q.push({x,y-1});
            }
            if((y+1)<m && grid[x][y+1]==1)
            {
                grid[x][y+1]=2;
                fresh--;
                q.push({x,y+1});
            }
            l--;
            if(!l)
            {
                minutes++;
                l=q.size();
                cout << "inloop" << endl;
                
            }
            cout<< l << " " << minutes << " "<< x << " " << y << endl;
        }
        return (fresh==0)?minutes-1:-1;
    }
};
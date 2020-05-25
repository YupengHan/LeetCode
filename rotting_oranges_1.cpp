class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();

        queue<pair<int, int>> rot_queue;
        int fresh_cnt = 0;
        int time_spend = -1;

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == 1) {
                    fresh_cnt++;
                }
                else if (grid[i][j] == 2) {
                    rot_queue.push({i,j});
                }
            }
        }

        if (fresh_cnt == 0) {
            cout << fresh_cnt << endl;
            return 0;
        }

        while(!rot_queue.empty()) {
            int x = rot_queue.front().first, y = rot_queue.front().second;
            // cout << x << " " << y << endl;
            rot_queue.pop();
            if (x>0 && grid[x-1][y] == 1) {
                grid[x-1][y] = 2;
                rot_queue.push({x-1,y});
                fresh_cnt--;
            }
            if (x+1<m && grid[x+1][y] == 1) {
                grid[x+1][y] = 2;
                rot_queue.push({x+1,y});
                fresh_cnt--;
            }
            if (y>0 && grid[x][y-1] == 1) {
                grid[x][y-1] = 2;
                rot_queue.push({x,y-1});
                fresh_cnt--;
            }
            if (y+1<n && grid[x][y+1] == 1) {
                grid[x][y+1] = 2;
                rot_queue.push({x,y+1});
                fresh_cnt--;
            }
            time_spend++;
            cout << rot_queue.size() <<endl;
        }

        if (fresh_cnt > 0) {
            return -1;
        }
        
        return time_spend;
        
        
    }
};

/*
    急速算法的关键在于如何控制time!!!!
    nb的点在于,可以通过
    if(!l) {
        l = q.size()
        minutes++
    }
    只有在当前expand结束的时候才增加时间
*/

/*

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
        // cout<< l << endl;
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
            // cout << "before " << l << " " << minutes << " "<< x << " " << y << endl;
            if(!l)
            {
                minutes++;
                l=q.size();
                // cout << "inloop" << endl;
                
            }
            // cout<< "after " <<  l << " " << minutes << " "<< x << " " << y << endl;
            // cout << "------------------------------" <<endl;
        }
        return (fresh==0)?minutes-1:-1;
    }
};
*/
// class Solution {
// public:
//     int minCost(vector<int>& houses, vector<vector<int>>& cost, int m, int n, int target) {
//         int mcc = 100000000;
//         int ret = mcc;
//         int s = 1;
//         vector<vector<vector<int>>> dp(target+1, vector<vector<int>>(m+1, vector<int>(n+1, mcc)));
//         fill(begin(dp[0][0]), end(dp[0][0]), 0);
//         for (int k = 1; k <= target; k++) {
//             for (int i = k; i <= m; i++) {
//                 int hi = houses[i-1];
//                 int hj = (i>1) ? houses[i-2] : 0;
//                 auto& [si,ei] = (hi!= 0) ? [hi, hi] : [1, n];
//                 auto& [sj,ej] = (hj!= 0) ? [hj, hj] : [1, n];
//                 for (int ci = si; ci <= ei; ci++) {
//                     int v = (ci == hi) ? 0 : cont[i-1][ci-1];
//                     for (int cj = sj; cj <= ej; ci++) {
//                         dp[k][i][ci] = min(dp[k][i][ci], dp[k - (ci != cj)][i-1][cj] + v);
//                     }
                    
//                 }
                
//             }
//         }
//         ret = *min_element(begin(dp[target][m]), end(dp[target][m]));

//         return ret >= mcc ? -1 : ret;
//     }
// };

class Solution {
public:
    vector<int> houses;
    vector<vector<int>> costs;
    int numColors;
    int MAXCOST = 1000000000;
    
    int dp[100][21][101];
    
    int solve(int m, int color, int target){
        // number of neighborhoods>0
        if(target==0 || (m==0 && target != 1))
            return -1;
        // already painted house can't be recolored
        if(houses[m]!=0 && houses[m]!=color)
            return -1;
        if(m==0)
            return costs[0][color-1];
        if(dp[m][color][target] != -2) return dp[m][color][target];
        int ans = MAXCOST;
        // same neighborhood
        int ansS = solve(m-1,color,target);
        if(ansS != -1) ans = min(ans,ansS);
        // different neighborhood
        int ansD;
        for(int i=1;i<=numColors;i++){
            if(i!=color){
                ansD = solve(m-1,i,target-1);
                if(ansD != -1) ans = min(ans,ansD);
            }
        }
        if(ans!=MAXCOST)
            ans = ans + costs[m][color-1];
        else
            ans = -1;
        dp[m][color][target] = ans;
        return dp[m][color][target];
    }

    int minCost(vector<int>& Houses, vector<vector<int>>& Cost, int m, int n, int target) {
        numColors = n;
        houses = Houses;
        costs = Cost;
        //init with -2;
        // [100][21][101]
        for(int i=0;i<100;i++){
            for(int j=0;j<21;j++){
                for(int k=0;k<101;k++){
                    dp[i][j][k] = -2;
                }
            }
        }
        // no cost for already painted house.
        for(int i=0;i<m;i++)
            if(houses[i]!=0)
                costs[i][houses[i]-1] = 0;
        int ans = MAXCOST;
        for(int i=1;i<=numColors;i++){
            int temp = solve(m-1,i, target);
            if(temp!=-1) ans = min(ans,temp);
        }
        if(ans==MAXCOST) return -1;
        return ans;
    }
};
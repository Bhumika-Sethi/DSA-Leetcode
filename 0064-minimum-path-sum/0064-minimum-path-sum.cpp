class Solution {
public:
    int minimumPathSum(int n, int m, vector<vector<int>>& grid, vector<vector<int>>& dp){
        if(n<0 || m<0){
            return 100000000;
        }
        if(n==0 && m==0){
            return grid[0][0];
        }
        if(dp[n][m]!=-1){
            return dp[n][m];
        }
        int up = grid[n][m] + minimumPathSum(n-1,m,grid,dp);
        int left = grid[n][m] + minimumPathSum(n,m-1,grid,dp);

        return dp[n][m] = min(up,left);

    }
    int minPathSum(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<int>> dp(n,vector<int>(m,-1));
        return minimumPathSum(n-1,m-1,grid,dp);
    }
};
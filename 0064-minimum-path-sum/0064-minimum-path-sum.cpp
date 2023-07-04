class Solution {
    
    
    int gridd(int i, int j, vector<vector<int>>& grid, vector<vector<int>>& dp){
        if(i==0 && j==0){
            return grid[0][0];
        }
        
        int up = 1e9;
        int left = 1e9;
        
        if(dp[i][j]!=-1){
            return dp[i][j];
        }
        
        if(i-1>=0){
            up = grid[i][j] + gridd(i-1,j,grid,dp);
        }
        if(j-1>=0){
            left = grid[i][j] + gridd(i,j-1,grid,dp);
        }
        return dp[i][j] = min(up,left);
    }
    
    
public:
    int minPathSum(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<int>> dp(n,vector<int>(m,-1));
        return gridd(n-1,m-1,grid,dp);
    }
};
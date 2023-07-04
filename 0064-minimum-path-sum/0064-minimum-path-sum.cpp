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
        vector<vector<int>> dp(n,vector<int>(m,0));
        
        
        for(int i = 0; i<n; i++){
            for(int j = 0; j<m; j++){
                if(i==0 && j==0){
                    dp[0][0] = grid[0][0];
                }
                else{
                    int up = grid[i][j];
                    int left = grid[i][j];

                    if(i-1>=0){
                        up += dp[i-1][j];
                    }
                    else{
                        up += 1e9;
                    }
                    if(j-1>=0){
                        left += dp[i][j-1];
                    }
                    else{
                        left += 1e9;
                    }
                    dp[i][j] = min(up,left);
                }
            }
        }
        return dp[n-1][m-1];
    }
};
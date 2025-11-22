class Solution {
public:
    int countUniquePathsWithObstacles(int n, int m, vector<vector<int>>& obstacleGrid,vector<vector<int>>& dp){
        if(n<0 || m<0){
            return 0;
        }
        if(obstacleGrid[n][m]==1){
            return 0;
        }
        if(n==0 && m==0){
            return 1;
        }
        if(dp[n][m]!=-1){
            return dp[n][m];
        }
        int up = countUniquePathsWithObstacles(n-1,m,obstacleGrid,dp);
        int down = countUniquePathsWithObstacles(n,m-1,obstacleGrid,dp);
        return up + down;
    }
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int n = obstacleGrid.size();
        int m = obstacleGrid[0].size();
        if(obstacleGrid[0][0]==1 || obstacleGrid[n-1][m-1]==1){
            return 0;
        }
        vector<vector<int>> dp(n,vector<int>(m,-1));
        dp[0][0] = 1;
        for(int i = 0; i<n; i++){
            for(int j = 0; j<m; j++){
                if(obstacleGrid[i][j]==1){
                    dp[i][j]=0;
                }
            }
        }
        for(int i = 0; i<n; i++){
            for(int j =0; j<m; j++){
                if(i==0 && j==0){
                    dp[i][j] = 1;
                }
                else{
                    if(obstacleGrid[i][j]==1){
                        continue;
                    }
                    int up = 0, left = 0;
                    if(i-1>=0){
                        up = dp[i-1][j];
                    }
                    if(j-1>=0){
                        left = dp[i][j-1];
                    }
                    dp[i][j] = up + left;
                }
            }
        }
        return dp[n-1][m-1];
    }
};
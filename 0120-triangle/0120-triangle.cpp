class Solution {
public:
    int minPathSum(int i, int j, vector<vector<int>>& triangle, vector<vector<int>>& dp){
        if(i==triangle.size()-1){
            return triangle[i][j];
        }
        if(dp[i][j]!=-1){
            return dp[i][j];
        }
        int down = triangle[i][j] + minPathSum(i+1,j,triangle,dp);
        int rightdia = triangle[i][j] + minPathSum(i+1,j+1,triangle,dp);
        return dp[i][j] = min(down,rightdia);
    }
    int minimumTotal(vector<vector<int>>& triangle) {
       int n = triangle.size();
       int m = triangle[n-1].size();
       vector<vector<int>> dp(n,vector<int>(m,-1)); 
       for(int j = 0; j<m; j++){
        dp[n-1][j] = triangle[n-1][j];
       }

       for(int i = n-2; i>=0; i--){
        for(int j = i; j>=0; j--){
            int down = triangle[i][j] + dp[i+1][j];
            int rightdia = triangle[i][j] + dp[i+1][j+1];
            dp[i][j] = min(down,rightdia);
        }
       }
       return dp[0][0];
    }
};
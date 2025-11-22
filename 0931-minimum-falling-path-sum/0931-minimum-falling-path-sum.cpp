class Solution {
public:
    int minPathSum(int n, int m, vector<vector<int>>& matrix, vector<vector<int>>& dp){
        if(n<0 || m<0 || m>=matrix[0].size()){
            return 10000000;
        }
        if(n==0){
            return dp[n][m] = matrix[n][m];
        }
        if(dp[n][m]!=-1){
            return dp[n][m];
        }
        int up = matrix[n][m] + minPathSum(n-1,m,matrix,dp);
        int leftDia = matrix[n][m] + minPathSum(n-1,m-1,matrix,dp);
        int rightDia = matrix[n][m] + minPathSum(n-1,m+1,matrix,dp);
        return dp[n][m] = min(up,min(leftDia,rightDia));
    }
    int minFallingPathSum(vector<vector<int>>& matrix) {
        int n = matrix.size();
        int m = matrix[0].size();
        int minSum = 100000000;
        vector<vector<int>> dp(n,vector<int>(m,0));
        for(int j = 0; j<matrix[0].size(); j++){
            dp[0][j] = matrix[0][j];
        }

        for(int i = 1; i<n; i++){
            for(int j = 0; j<m; j++){
                int up = matrix[i][j] + dp[i-1][j];
                int leftDia = 100000000;
                if(j-1>=0){
                    leftDia = matrix[i][j] + dp[i-1][j-1];
                }
                int rightDia = 10000000;
                if(j+1<m){
                    rightDia = matrix[i][j] + dp[i-1][j+1];
                }
                dp[i][j] = min(up,min(leftDia, rightDia));
            }
        }
        for(int j = 0; j<matrix[0].size(); j++){
            minSum = min(minSum,dp[n-1][j]);
        }
        return minSum;
    }
};
class Solution {
public:
    int uniquepaths(int i, int j, int n, int m, vector<vector<int>>& dp){
        if(i>=n || j>=m){
            return 0;
        }
        if(i==n-1 && j==m-1){
            return 1;
        }
        if(dp[i][j]!=-1){
            return dp[i][j];
        }
        int down = 0;
        int right = 0;
        if(i<n){
            down += uniquepaths(i+1,j,n,m,dp);
        }
        if(j<m){
            right += uniquepaths(i,j+1,n,m,dp);
        }
        return dp[i][j] = down+right;
    }
    int uniquePaths(int m, int n) {
        vector<vector<int>> dp(m+1,vector<int>(n+1,-1));
        return uniquepaths(0,0,m,n,dp);
    }
};
class Solution {
    int rec(int i, int j, string& str1, string& str2, vector<vector<int>>& dp){
        if(i==str1.size()){
            return str2.size() - j; 
        }
        if(j==str2.size()){
            return str1.size() - i;
        }
        
        if(dp[i][j]!=-1){
            return dp[i][j];
        }
        int match = 1e9;
        int notMatch = 1e9;
        if(str1[i]==str2[j]){
            match = 0 + rec(i+1,j+1,str1,str2,dp);
        }
        else{
            notMatch = 1 + min(rec(i+1,j+1,str1,str2,dp),min(rec(i+1,j,str1,str2,dp),rec(i,j+1,str1,str2,dp)));
        }
        return dp[i][j] = min(match,notMatch);
    }
public:
    int minDistance(string word1, string word2) {
        int n = word1.size();
        int m = word2.size();
        vector<vector<int>> dp(n+1,vector<int>(m+1,0));
        
        for(int j = 0; j<m; j++){
            dp[n][j] = m - j;
        }
        
        for(int i = 0; i<n; i++){
            dp[i][m] = n - i;
        }
        
        for(int i = n-1; i>=0; i--){
            for(int j = m-1; j>=0; j--){
                int match = 1e9;
                int notMatch = 1e9;
                   if(word1[i]==word2[j]){
                         match = 0 + dp[i+1][j+1];
                    }
                    else{
                         notMatch = 1 + min(dp[i+1][j+1],min(dp[i+1][j],dp[i][j+1]));
                    }
                dp[i][j] = min(match,notMatch);
            }
        }
        
        return dp[0][0];
    }
};
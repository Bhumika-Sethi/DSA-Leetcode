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
        
        if(str1[i]==str2[j]){
            return dp[i][j] = 0 + rec(i+1,j+1,str1,str2,dp);
        }
        else{
            return dp[i][j] = 1 + min(rec(i+1,j+1,str1,str2,dp),min(rec(i+1,j,str1,str2,dp),rec(i,j+1,str1,str2,dp)));
        }
    }
public:
    int minDistance(string word1, string word2) {
        int n = word1.size();
        int m = word2.size();
        vector<vector<int>> dp(n,vector<int>(m,-1));
        return rec(0,0,word1,word2,dp);
    }
};
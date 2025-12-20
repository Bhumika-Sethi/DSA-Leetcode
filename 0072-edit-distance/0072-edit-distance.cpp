class Solution {
public:
    int minOper(int ind1, int ind2, string& word1, string& word2, vector<vector<int>>& dp){
        if(ind2<0){
            return ind1+1;
        }
        if(ind1<0){
            return ind2+1;
        }

        if(dp[ind1][ind2] != -1){
            return dp[ind1][ind2];
        }

        // matching
        if(word1[ind1]==word2[ind2]){
            return dp[ind1][ind2] = minOper(ind1-1,ind2-1,word1,word2,dp);
        }

        // notMatching
        int del = 1 + minOper(ind1-1,ind2,word1,word2,dp);
        int ins = 1 + minOper(ind1,ind2-1,word1,word2,dp);
        int repl = 1 + minOper(ind1-1,ind2-1,word1,word2,dp);

        return dp[ind1][ind2] = min(min(del,ins),repl);
    }

    int minDistance(string word1, string word2) {
        int n = word1.size();
        int m = word2.size();
        vector<vector<int>> dp(n,vector<int>(m,-1));
        return minOper(n-1,m-1,word1,word2,dp);
    }
};
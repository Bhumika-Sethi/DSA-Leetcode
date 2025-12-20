class Solution {
public:
    int minOper(int ind1, int ind2, string& word1, string& word2, vector<vector<int>>& dp){
        if(ind2==0){
            return ind1;
        }
        if(ind1==0){
            return ind2;
        }

        if(dp[ind1][ind2] != -1){
            return dp[ind1][ind2];
        }

        // matching
        if(word1[ind1-1]==word2[ind2-1]){
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
        vector<vector<int>> dp(n+1,vector<int>(m+1,-1));
        for(int ind1 = 0; ind1<=n; ind1++){
            dp[ind1][0] = ind1;
        }

        for(int ind2 = 0; ind2<=m; ind2++){
            dp[0][ind2] = ind2;
        }

        for(int ind1 = 1; ind1<=n; ind1++){
            for(int ind2 = 1; ind2<=m; ind2++){
                if(word1[ind1-1]==word2[ind2-1]){
                    dp[ind1][ind2] = dp[ind1-1][ind2-1];
                }
                else{
                    int del = 1 + dp[ind1-1][ind2];
                    int ins = 1 + dp[ind1][ind2-1];
                    int repl = 1 + dp[ind1-1][ind2-1];
                    dp[ind1][ind2] = min(min(del,ins),repl);
                }
            }
        }

        return dp[n][m];
    }
};
class Solution {
public:
    int lps(int ind1, int ind2, string s, string r,vector<vector<int>>& dp){
        if(ind1<0 || ind2<0){
            return 0;
        }
        if(dp[ind1][ind2]!=-1){
            return dp[ind1][ind2];
        }
        // matching condition
        if(s[ind1]==r[ind2]){
            return dp[ind1][ind2] = 1 + lps(ind1-1,ind2-1,s,r,dp);
        }

        // not matching condition
        else{
            return dp[ind1][ind2] = max(lps(ind1-1,ind2,s,r,dp),lps(ind1,ind2-1,s,r,dp));
        }

    }
    int longestPalindromeSubseq(string s) {
        // What is palidrome, the one which is same from front as well as back.
        //  So, what we'll do is reverse the string and then find conglest common subsequence
        // The answer we'll get would be longest common palidrome
        string r = s;
        int n = s.size();
        int m = r.size();
        reverse(r.begin(),r.end());
        vector<vector<int>> dp(n+1,vector<int>(m+1,0));
        for(int ind1 = 1; ind1<=n; ind1++){
            dp[ind1][0] = 0;
            for(int ind2 = 1; ind2<=m; ind2++){
                // matching condition
                if(s[ind1-1]==r[ind2-1]){
                    dp[ind1][ind2] = 1 + dp[ind1-1][ind2-1];
                }

                // not matching condition
                else{
                    dp[ind1][ind2] = max(dp[ind1-1][ind2],dp[ind1][ind2-1]);
                }
            }
        }
        return dp[n][m];
    }
};
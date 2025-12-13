class Solution {
public:
    int minInsertions(string s) {
        // Just get to know the longest common palidrome and just 
        // insertions needed = s.size() - lps();

        int n = s.size();
        string r = s;
        reverse(r.begin(),r.end());
        int m = r.size();

        vector<vector<int>> dp(n+1,vector<int>(m+1,0));

        for(int ind1 = 1; ind1<=n; ind1++){
            dp[ind1][0] = 0;
            for(int ind2 = 1; ind2<=m; ind2++){
                if(s[ind1-1]==r[ind2-1]){
                    dp[ind1][ind2] = 1 + dp[ind1-1][ind2-1];
                }
                else{
                    dp[ind1][ind2] = max(dp[ind1-1][ind2],dp[ind1][ind2-1]);
                }
            }
        }
        return (n) - (dp[n][m]);
    }
};
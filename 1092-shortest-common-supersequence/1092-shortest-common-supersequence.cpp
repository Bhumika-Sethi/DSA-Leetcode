class Solution {
public:
    string shortestCommonSupersequence(string str1, string str2) {
        // Find lcs
        // m + n - lcs

        int n = str1.size();
        int m = str2.size();

        vector<vector<int>> dp(n+1,vector<int>(m+1,0));

        for(int ind1 = 1; ind1<=n; ind1++){
            for(int ind2 = 1; ind2<=m; ind2++){
                if(str1[ind1-1]==str2[ind2-1]){
                    dp[ind1][ind2] = 1 + dp[ind1-1][ind2-1];
                }
                else{
                    dp[ind1][ind2] = max(dp[ind1-1][ind2],dp[ind1][ind2-1]);
                }
            }
        }
        int i = n;
        int j = m;
        string str = "";
        while(i>0 && j>0){
            if(str1[i-1]==str2[j-1]){
                str += str1[i-1];
                i--;
                j--;
            }
            else{
                if(dp[i-1][j]>dp[i][j-1]){
                    str += str1[i-1];
                    i--;
                }
                else{
                    str += str2[j-1];
                    j--;
                }
            }
        }
        // Important condition
        while(i>0){
            str+=str1[i-1];
            i--;
        }
        // Important
        while(j>0){
            str+=str2[j-1];
            j--;
        }
        reverse(str.begin(),str.end());
        return str;
    }
};
class Solution {
public:
    bool wildcardMatch(int ind1, int ind2, string& s1, string& s2,vector<vector<int>>& dp){
        // Both exhausted
        if(ind2<0 && ind1<0){
            return true; 
        }
        // When the pattern string is exhausted and text is still remaining
        if(ind2<0 && ind1>=0){
            return false;
        }
        // When text is exhausted and pattern string is still remaining
        else if(ind1<0 && ind2>=0){
            if(s2[ind2]!='*'){
                return false;
            }
            else{
                while(ind2>=0 && s2[ind2]=='*'){
                    ind2--;
                }
                if(ind2<0){
                    return true;
                }
                else{
                    return false;
                }
            }
        }
        if(dp[ind1][ind2] != -1){
            return dp[ind1][ind2];
        }
        // Matching
        if(s1[ind1]==s2[ind2] || s2[ind2]=='?'){
            return dp[ind1][ind2] = wildcardMatch(ind1-1,ind2-1,s1,s2,dp);
        }
        // 
        else if(s2[ind2]=='*'){
            // take
            bool take = wildcardMatch(ind1-1, ind2,s1,s2,dp);
            // notTake
            bool notTake = wildcardMatch(ind1,ind2-1,s1,s2,dp);
            return dp[ind1][ind2] = take | notTake;
        }
        return dp[ind1][ind2] = false;
    }
    bool isMatch(string s, string p) {
        int n = s.size();
        int m = p.size();
        vector<vector<int>> dp(n,vector<int>(m,-1));
        return wildcardMatch(n-1,m-1,s,p,dp);
    }
};
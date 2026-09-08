class Solution {
public:
    int numDecode(int ind, string& s, vector<int>& dp){
        if(ind<0){
            return 1;
        }
        if(ind==0){
            if(s[ind]>='1' && s[ind]<='9'){
                return 1;
            }
            else{
                return 0;
            }
        }
        if(dp[ind]!=-1){
            return dp[ind];
        }
        int ans = 0;
        if(s[ind]>='1' && s[ind]<='9'){
            ans += numDecode(ind-1,s,dp);
        }
        if(s[ind-1]=='1' ||( s[ind-1]=='2' && s[ind]<='6')){
            ans+=numDecode(ind-2,s,dp);
        }
        return dp[ind] = ans;
    }
    int numDecodings(string s) {
        int n = s.size();
        if(s.contains("00") || s.starts_with('0')){
            return 0;
        }
        vector<int> dp(n+1,-1);
        return numDecode(n-1,s,dp);
    }
};
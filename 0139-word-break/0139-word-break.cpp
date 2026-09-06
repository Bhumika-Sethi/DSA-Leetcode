class Solution {
public:
    
    bool wordsFind(string s, vector<string>& words){
        for(int i = 0; i<words.size(); i++){
            if(s==words[i]){
                return true;
            }                                              
        }
        return false;
    }

    bool wb(int ind, int n, string s, vector<string>& words, vector<int>& dp){
        if(ind==n){
            return true;
        }
        if(dp[ind]!=-1){
            return dp[ind];
        }
        for(int i = 0; i<=n; i++){
            if(wordsFind(s.substr(ind,i),words)==true && wb(ind+i,n,s,words,dp)){
                return dp[ind] = true;
            }
        }
        return dp[ind] = false;
    }
    bool wordBreak(string s, vector<string>& wordDict) {
        int n = s.size();
        int m = wordDict.size();
        vector<int> dp(n+1,-1);
        return wb(0,n,s,wordDict,dp);
    }
};
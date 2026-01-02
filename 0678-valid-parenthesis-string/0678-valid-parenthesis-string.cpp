class Solution {
public:

    bool checkParanthesis(int ind, int balance, int n, string& s,vector<vector<int>>& dp){
        // IMP
        if(balance<0){
            return false;
        }
        if(ind==n){
            return balance == 0 ? true : false; 
        }
        if(dp[ind][balance]!=-1){
            return dp[ind][balance];
        }
        if(s[ind]=='('){
            return dp[ind][balance] = checkParanthesis(ind+1,balance+1,n,s,dp);
        }
        else if(s[ind]==')'){
            return dp[ind][balance] = checkParanthesis(ind+1,balance-1,n,s,dp);
        }
        else{
            bool opening = checkParanthesis(ind+1,balance+1,n,s,dp);
            bool closing = checkParanthesis(ind+1,balance-1,n,s,dp);
            bool none = checkParanthesis(ind+1,balance,n,s,dp);
            if(opening || closing || none){
                return dp[ind][balance] = true;
            }
            else{
                return dp[ind][balance] = false;
            }
        }
        
    }

    bool checkValidString(string s) {
        int n = s.size();
        int balance = 0;
        vector<vector<int>> dp(n,vector<int>(n,-1));
       return checkParanthesis(0,balance,n,s,dp); 
    }
};
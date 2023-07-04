class Solution {
    int coinss(int i, vector<int>& coins, int amount, vector<vector<int>>& dp){
        if(amount==0){
            return 0;
        }
        if(i==coins.size()){
            return 1e9;
        }
        if(dp[i][amount]!=-1){
            return dp[i][amount];
        }
        int notTake = 0 + coinss(i+1,coins,amount,dp);
        int take = 1e9;
        if(amount-coins[i]>=0){
            take = 1 + coinss(i,coins,amount-coins[i],dp);
        }
        return dp[i][amount] = min(take,notTake);
    }
    
public:
    int coinChange(vector<int>& coins, int amount) {
        int n = coins.size();
        vector<vector<int>> dp(n,vector<int>(amount+1,-1));
        int ans = coinss(0,coins,amount,dp);
        if(ans>=1e8){
            return -1;
        }
        else{
            return ans;
        }
    }
};
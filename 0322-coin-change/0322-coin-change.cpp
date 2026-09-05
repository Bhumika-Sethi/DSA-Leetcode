class Solution {
public:
    int coinChange(int i, vector<int>& coins, int n, int amount,vector<vector<int>>& dp) {
        if(amount==0){
            return 0;
        }
        if(amount<0){
            return 1e9;
        }
        if(i==n){
            return 1e9;
        }
        if(dp[i][amount]!=-1){
            return dp[i][amount];
        }
        int take =1e9;
        if(amount>=coins[i]){
            take = 1 + coinChange(i,coins,n,amount-coins[i],dp);
        }
        int notTake = coinChange(i+1,coins,n,amount,dp);
        return dp[i][amount] = min(take,notTake);
    }
    int coinChange(vector<int>& coins, int amount) {
        int n = coins.size();
        vector<vector<int>> dp(n+1,vector<int>(amount+1,-1));
        int res = coinChange(0,coins,coins.size(),amount,dp);
        int ans = res>=1e9 ? -1: res; 
        return ans;
    }
};
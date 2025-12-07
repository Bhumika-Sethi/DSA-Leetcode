class Solution {
public:
    int minCoins(int ind, int amount, vector<int>& coins, vector<vector<int>>& dp){
        if(amount==0){
            return 0;
        }
        if(ind<0){
            return 100000000;
        }
        if(dp[ind][amount]!=-1){
            return dp[ind][amount];
        }
        int pick = 100000000;
        if(amount-coins[ind]>=0){
            pick = 1 + minCoins(ind,amount-coins[ind],coins,dp);
        }
        int notPick = 0 + minCoins(ind-1,amount,coins,dp);
        return dp[ind][amount] = min(pick,notPick);
    }
    int coinChange(vector<int>& coins, int amount) {
        int n = coins.size();
        vector<vector<int>> dp(n,vector<int>(amount+1,-1));
        int ans = minCoins(n-1,amount,coins,dp);
        if(ans>=100000000){
            return -1;
        }
        else{
            return ans;
        }
    }
};
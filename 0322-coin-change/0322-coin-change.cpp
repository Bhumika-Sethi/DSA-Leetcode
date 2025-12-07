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
        vector<vector<int>> dp(n+1,vector<int>(amount+1,0));
        for(int sum = 0; sum<=amount; sum++){
            dp[0][sum] = 100000000;
        }
        for(int ind = 1; ind<=n; ind++){
            dp[ind][0] = 0;
            for(int sum = 1; sum<=amount; sum++){
                int pick = 100000000;
                if(sum-coins[ind-1]>=0){
                    pick = 1 + dp[ind][sum-coins[ind-1]];
                }
                int notPick = 0 + dp[ind-1][sum];
                dp[ind][sum] = min(pick,notPick);
            }
        }
        int ans = dp[n][amount];
        if(ans>=100000000){
            return -1;
        }
        else{
            return ans;
        }
    }
};
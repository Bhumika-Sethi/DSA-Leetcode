class Solution {
public:
    int coinChange(int ind, int sum, vector<int>& coins, vector<vector<int>>& dp){
        if(sum==0){
            return 1;
        }
        if(ind==0){
            if(sum%coins[ind]==0){
                return 1;
            }
            else{
                return 0;
            }
        }
        if(dp[ind][sum]!=-1){
            return dp[ind][sum];
        }
        int pick = 0;
        if(sum-coins[ind]>=0){
            pick = coinChange(ind,sum-coins[ind],coins,dp);
        }
        int notPick = coinChange(ind-1,sum,coins,dp);
        return dp[ind][sum] = pick + notPick;
    }
    int change(int amount, vector<int>& coins) {
        int n = coins.size();
        vector<vector<int>> dp(n,vector<int>(amount+1,-1));
        return coinChange(n-1,amount,coins,dp);
    }
};
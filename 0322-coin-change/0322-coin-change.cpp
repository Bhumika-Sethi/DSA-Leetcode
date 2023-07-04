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
        vector<vector<int>> dp(n+1,vector<int>(amount+1,0));
        for(int i = 0; i<=n; i++){
            dp[i][0] = 0;
        }
        
        for(int j = 1; j<=amount; j++){
            dp[n][j] = 1e9;
        }
        
        for(int i = n-1; i>=0; i--){
            for(int j = 1; j<=amount; j++){
                int notTake = 0 + dp[i+1][j];
                int take = 1e9;
                if(j-coins[i]>=0){
                    take = 1 + dp[i][j-coins[i]];
                }
                dp[i][j] = min(take,notTake);
            }
        }
        
        int ans = dp[0][amount];
        if(ans>=1e8){
            return -1;
        }
        else{
            return ans;
        }
    }
};
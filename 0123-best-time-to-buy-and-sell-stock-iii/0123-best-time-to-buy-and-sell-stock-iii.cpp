class Solution {
public:
    int BuySellWithMaxTransLimit(int ind, int buy, int transaction, int n, vector<int>& prices,vector<vector<vector<int>>>& dp){
        if(transaction==0){
            return 0;
        }
        if(ind==n){
            return 0;
        }
        if(dp[ind][buy][transaction]!=-1){
            return dp[ind][buy][transaction];
        }
        if(buy){
            int take = -prices[ind] + BuySellWithMaxTransLimit(ind+1,0,transaction,n,prices,dp);
            int notTake = BuySellWithMaxTransLimit(ind+1,1,transaction,n,prices,dp);
            return dp[ind][buy][transaction] = max(take,notTake);
        }
        else{
            int take = prices[ind] + BuySellWithMaxTransLimit(ind+1,1,transaction-1,n,prices,dp);
            int notTake = BuySellWithMaxTransLimit(ind+1,0,transaction,n,prices,dp);
            return dp[ind][buy][transaction] = max(take,notTake);
        }
    }
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        int buy = 1;
        int transaction = 2;
        vector<vector<vector<int>>> dp(n,vector<vector<int>>(2,vector<int>(3,-1)));
        return BuySellWithMaxTransLimit(0,buy,transaction,n,prices,dp);
    }
};
class Solution {
public:
    int buySellFee(int ind, int buy, int n, int fee, vector<int>& prices, vector<vector<int>>& dp){
        if(ind==n){
            return 0;
        }
        if(dp[ind][buy]!=-1){
            return dp[ind][buy];
        }
        if(buy){
            int take = -prices[ind] + buySellFee(ind+1,0,n,fee,prices,dp);
            int notTake = buySellFee(ind+1,1,n,fee,prices,dp);
            return dp[ind][buy] = max(take,notTake);
        }
        else{
            // Fee is the cost not profit, so it would be deduced
            int take = prices[ind] - fee + buySellFee(ind+1,1,n,fee, prices,dp);
            int notTake = buySellFee(ind+1,0,n,fee,prices,dp);
            return dp[ind][buy] = max(take,notTake);
        }
    }
    int maxProfit(vector<int>& prices, int fee) {
        int n = prices.size();
        int buy = 1;
        vector<vector<int>> dp(n,vector<int>(2,-1));
        return buySellFee(0,buy,n,fee,prices,dp);
    }
};
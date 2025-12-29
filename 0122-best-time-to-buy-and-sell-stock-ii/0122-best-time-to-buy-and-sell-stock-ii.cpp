class Solution {
    int buySell(int ind,int buy, int n, vector<int>& prices, vector<vector<int>>& dp){
        if(ind==n){
            return 0;
        }
        if(dp[ind][buy]!=-1){
            return dp[ind][buy];
        }
        if(buy==1){
            int take = -prices[ind] + buySell(ind+1,0,n,prices,dp);
            int notTake = buySell(ind+1,1,n,prices,dp);
            return dp[ind][buy] = max(take,notTake);
        }
        else{
            int take = prices[ind] + buySell(ind+1,1,n,prices,dp);
            int notTake = buySell(ind+1,0,n,prices,dp);
            return dp[ind][buy] = max(take,notTake);
        }
    }
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        int buy = 1;
        int profit = 0;
        vector<vector<int>> dp(n+1,vector<int>(2,0));

        for(int ind = n-1; ind>=0; ind--){
            for(int buy = 0; buy<=1; buy++){
                if(buy==1){
                    int take = -prices[ind] + dp[ind+1][0];
                    int notTake = dp[ind+1][1];
                    dp[ind][buy] = max(take,notTake);
                }
                else{
                    int take = prices[ind] + dp[ind+1][1];
                    int notTake = dp[ind+1][0];
                    dp[ind][buy] = max(take,notTake);
                }
            }
        }
        profit = max(profit,dp[0][buy]);
        return profit;
    }
};
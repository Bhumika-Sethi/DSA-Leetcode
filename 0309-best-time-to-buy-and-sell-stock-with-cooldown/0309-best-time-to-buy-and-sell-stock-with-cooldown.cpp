class Solution {
public:
    int buySellCoolDown(int ind, int buy, int n, vector<int>& prices,vector<vector<int>>& dp){
        if(ind>=n){
            return 0;
        }
        if(dp[ind][buy]!=-1){
            return dp[ind][buy];
        }
        if(buy==1){
            int take = -prices[ind] + buySellCoolDown(ind+1,0,n,prices,dp);
            int notTake = buySellCoolDown(ind+1,1,n,prices,dp);
            return dp[ind][buy] = max(take,notTake);
        }
        else{
            int take = prices[ind] + buySellCoolDown(ind+2,1,n,prices,dp);
            int notTake = buySellCoolDown(ind+1,0,n,prices,dp);
            return dp[ind][buy] = max(take,notTake);
        }
    }
    int maxProfit(vector<int>& prices) {
       int n = prices.size();
       int buy = 1;
       vector<vector<int>> dp(n+1,vector<int>(2,0));
       for(int ind = n-1; ind>=0; ind--){
        for(int buy = 0; buy<=1; buy++){
            if(buy==1){
                int take = -prices[ind] + dp[ind+1][0];
                int notTake = dp[ind+1][1];
                dp[ind][buy] = max(take,notTake);
            }
            else{
                int take = prices[ind];
                if(ind+2<=n) {take += dp[ind+2][1];}
                int notTake = dp[ind+1][0];
                dp[ind][buy] = max(take,notTake);
            }
        }
       }
       return max(dp[0][buy],0); 
    }
};
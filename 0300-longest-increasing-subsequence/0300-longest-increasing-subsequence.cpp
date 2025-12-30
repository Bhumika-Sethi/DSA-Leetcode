class Solution {
public:
    int LIS(int ind, int prev_ind, int n, vector<int>& nums, vector<vector<int>>& dp){
        if(ind == n){
            return 0;
        }
        if(dp[ind][prev_ind+1]!=-1){
            return dp[ind][prev_ind+1];
        }

        // two cases - 
        // take
        int take = 0;
        // notTake
        int notTake = 0;
        // in case of take the arr[ind]>arr[prev_ind] || if it is the first time we are taking the element
        if(prev_ind==-1 || nums[ind]>nums[prev_ind]){
            take = 1 + LIS(ind+1,ind,n,nums,dp);
        }
        notTake = LIS(ind+1,prev_ind,n,nums,dp);
        // take max of take and notTake
        return dp[ind][prev_ind+1] = max(take,notTake);
    }
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>> dp(n+1,vector<int>(n+1,0));
        for(int ind = n-1; ind>=0; ind--){
            for(int prev_ind = ind-1; prev_ind>=-1; prev_ind--){
                int take = 0;
                if(prev_ind==-1 || nums[ind]>nums[prev_ind]){
                    take = 1 + dp[ind+1][ind+1];
                }
                int notTake = dp[ind+1][prev_ind+1];
                dp[ind][prev_ind+1] = max(take,notTake);
            }
        }
        return dp[0][0];
    }
};
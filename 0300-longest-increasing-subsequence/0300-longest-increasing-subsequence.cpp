class Solution {
    int lis(int curr_ind, int prev_ind, int n, vector<int>& nums, vector<vector<int>>& dp){
        if(curr_ind==n){
            return 0;
        }
        if(dp[curr_ind][prev_ind+1]!=-1){
            return dp[curr_ind][prev_ind+1];
        }
        int take = 0;
        if(prev_ind==-1 || nums[prev_ind]<nums[curr_ind]){
            take = 1 + lis(curr_ind+1,curr_ind,n,nums,dp);
        }
        int notTake = lis(curr_ind+1,prev_ind,n,nums,dp);
        return dp[curr_ind][prev_ind+1] = max(take,notTake);
    }
public:
    int lengthOfLIS(vector<int>& nums) {
        int curr_ind = 0;
        int prev_ind = -1;
        int n = nums.size();
        vector<vector<int>> dp(n+1,vector<int>(n+1,-1));
        return lis(curr_ind,prev_ind,n,nums,dp);
    }
};
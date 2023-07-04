class Solution {

    bool targetSum(int i, int target, vector<int>& nums, vector<vector<int>>& dp){
        if(target==0){
            return true;
        }
        if(i==nums.size()){
            return false;
        }
        if(dp[i][target]!=-1){
            return dp[i][target];
        }
        int notTake = targetSum(i+1,target,nums,dp);
        int take = false;
        if(target-nums[i]>=0){
            take = targetSum(i+1,target-nums[i],nums,dp);
        }
        return dp[i][target] = take | notTake;
    }
    
    public:
    bool canPartition(vector<int>& nums) {
        int sum = 0, n = nums.size();
        for(auto it : nums){
            sum += it;
        }
        if(sum%2==1){
            return false;
        }
        int target = sum/2;
        vector<vector<int>> dp(n,vector<int>(target+1,-1));
        return targetSum(0,target,nums,dp);
    }
};
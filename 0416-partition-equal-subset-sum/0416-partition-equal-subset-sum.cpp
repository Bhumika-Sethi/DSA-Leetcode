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
        vector<vector<bool>> dp(n+1,vector<bool>(target+1,0));
        
        for(int i = 0; i<=n; i++){
            dp[i][0] = true;
        }
        
        for(int j = 1; j<=target; j++){
            dp[n][j] = false;
        }
        
        
        for(int i = n-1; i>=0; i--){
            for(int j = 1; j<=target; j++){
                int notTake = dp[i+1][j];
                int take = false;
                if(j-nums[i]>=0){
                    take = dp[i+1][j-nums[i]];
                }
                dp[i][j] = take | notTake;
            }
        }
        return dp[0][target];
    }
};
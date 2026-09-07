class Solution {
public:
    int combSum(int n, vector<int>& nums, int target, vector<int>& dp){
        if(target==0){
            return 1;
        }
        if(target<0){
            return 0;
        }
        if(dp[target] != -1){
            return dp[target];
        }
        int totalWays = 0;
        for(int i = 0; i<n; i++){
            totalWays += combSum(n,nums,target-nums[i],dp);
        }
        return dp[target] = totalWays;
    }
    int combinationSum4(vector<int>& nums, int target) {
        int n = nums.size();
        vector<int> dp(target+1,-1);
        return combSum(n,nums,target,dp);
    }
};
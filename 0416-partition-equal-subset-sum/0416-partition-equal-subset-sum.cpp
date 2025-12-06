class Solution {
public:
    bool subsetSumEqual(int ind, int sum, vector<int>& nums,vector<vector<int>>& dp){
        if(sum==0){
            return true;
        }
        if(ind<0){
            return false;
        }
        int pick = 0;
        int notPick = 0;
        if(dp[ind][sum]!=-1){
            return dp[ind][sum];
        }
        if(sum-nums[ind]>=0){
            pick = subsetSumEqual(ind-1,sum-nums[ind],nums,dp);
        }
        notPick = subsetSumEqual(ind-1,sum,nums,dp);
        return dp[ind][sum] = pick|notPick;
    }
    bool canPartition(vector<int>& nums) {
        int sum = 0;
        int n = nums.size();
        for(int i = 0; i<nums.size(); i++){
            sum +=nums[i];
        }
        if(sum%2!=0){
            return false;
        }
        int target = sum/2;
        vector<vector<int>> dp(n,vector<int>(target+1,-1));
        return subsetSumEqual(n-1,sum/2,nums,dp);
    }
};
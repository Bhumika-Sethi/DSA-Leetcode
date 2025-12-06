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
        vector<vector<int>> dp(n+1,vector<int>(target+1,0));
        for(int i = 0; i<=n; i++){
            dp[i][0] = 1;
        }

        for(int ind = 1; ind<=n; ind++){
            dp[ind][0] = 1;
            for(int sum = 1; sum<=target; sum++){
                int pick = 0;
                int notPick = 0;
                if(sum-nums[ind-1]>=0){
                    pick = dp[ind-1][sum-nums[ind-1]];
                }
                notPick = dp[ind-1][sum];
                dp[ind][sum] = pick|notPick;
            }
        }

        return dp[n][target];
    }
};
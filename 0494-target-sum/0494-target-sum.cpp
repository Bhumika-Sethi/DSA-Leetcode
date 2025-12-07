class Solution {
public:
    int countSubsetSum(int ind, int sum, vector<int>& nums,vector<vector<int>>& dp){
        if(ind==0){
            if(sum==0 && nums[0]==0){
                return 2;
            }
            else if(sum==0){
                return 1;
            }
            else if(sum==nums[0]){
                return 1;
            }
            else{
                return 0;
            }
        }

        if(dp[ind][sum]!=-1){
            return dp[ind][sum];
        }
        int pick = 0;
        if(sum-nums[ind]>=0){
            pick = countSubsetSum(ind-1,sum-nums[ind],nums,dp);
        }

        int notPick = countSubsetSum(ind-1,sum,nums,dp);
        return dp[ind][sum] = pick + notPick;
    }
    int findTargetSumWays(vector<int>& nums, int target) {
        // diff = s1 - s2
        // target = s1 - s2
        // sum = s1 + s2
        // s1 = (target+sum)/2
        int n = nums.size();
        int sum = 0;
        for(int i = 0; i<n; i++){
            sum += nums[i];
        }
        int s1 = (target+sum)/2;
        if((target+sum)<0 || (target+sum)%2==1){
            return 0;
        }
        vector<vector<int>> dp(n,vector<int>(s1+1,-1));
        return countSubsetSum(n-1,s1,nums,dp);
    }
};
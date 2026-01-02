class Solution {
public:
    bool jump(int ind, int n, vector<int>& nums, vector<int>& dp){
        if(ind==n-1){
            return true;
        }
        if(dp[ind]!=-1){
            return dp[ind];
        }
        for(int i = 1; i<=nums[ind]; i++){
            if(jump(ind+i,n,nums,dp)){
                return dp[ind] = true;
            }
        }
        return dp[ind] = false;
    }
    bool canJump(vector<int>& nums) {
        int n = nums.size();
        vector<int> dp(n,-1);
        return jump(0,n,nums,dp);
    }
};
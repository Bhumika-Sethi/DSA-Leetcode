class Solution {
public:
    bool isPossible(int ind, int n, vector<int>& nums, vector<int>& dp){
        if(ind>=n-1){
            return true;
        }
        if(dp[ind]!=-1){
            return dp[ind];
        }
        for(int jump=1; jump<=nums[ind]; jump++){
            if(isPossible(ind+jump,n,nums,dp)){
                return true;
            }
        }
        return dp[ind] = false;
    }
    bool canJump(vector<int>& nums) {
        int i = 0, n = nums.size();
        vector<int> dp(n+1,-1);
        return isPossible(i,n,nums,dp);
    }
};
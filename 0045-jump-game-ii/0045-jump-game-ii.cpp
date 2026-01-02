class Solution {
public:
    int minJumps(int ind, vector<int>& nums, vector<int>& dp){
        if(ind>=nums.size()){
            return 1000000007;
        }
        if(ind==nums.size()-1){
            return 0;
        }

        int mini = 1000000007;
        if(dp[ind]!=-1){
            return dp[ind];
        }
        for(int i = 1; i<=nums[ind]; i++){
            mini = min(mini,1+minJumps(ind+i,nums,dp));
        }
        return dp[ind] = mini;

    }
    int jump(vector<int>& nums) {
        int n = nums.size();
        vector<int> dp(n,-1);
        return minJumps(0,nums,dp);
    }
};
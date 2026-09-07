class Solution {
public:
    int robbing(int ind, int prev_ind, int n, vector<int>& nums,vector<vector<int>>& dp){

        if(ind>=n){
            return 0;
        }

        if(dp[ind][prev_ind+1]!=-1){
            return dp[ind][prev_ind];
        }

        int take  = 0;
        if(prev_ind==-1 || (prev_ind%n)!=ind+1){
            take =  nums[ind] + robbing(ind+2,ind,n,nums,dp);
        }
        int notTake = robbing(ind+1,prev_ind,n,nums,dp);
        return dp[ind][prev_ind+1] = max(take,notTake);
    }
    int rob(vector<int>& nums) {
        int n = nums.size();

        vector<vector<int>> dp(n+1,vector<int>(n+1,-1));
        return robbing(0,-1,n,nums,dp);
    }
};
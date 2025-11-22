class Solution {

    int maxMoneyRobbed(int n, vector<int>& houses, vector<int>& dp){
        if(n==0){
            return houses[0];
        }
        if(n<0){
           return 0; 
        }
        if(dp[n]!=-1){
            return dp[n];
        }
        int pick = houses[n] + maxMoneyRobbed(n-2,houses,dp);
        int notPick = 0 + maxMoneyRobbed(n-1,houses,dp);

        return dp[n] =  max(pick,notPick);
    }

public:
    int rob(vector<int>& nums) {
        vector<int> temp1;
        vector<int> temp2;
        if(nums.size()==1){
            return nums[0];
        }
        for(int i = 0; i<nums.size()-1; i++){
            temp1.push_back(nums[i]);
        }

        for(int i = 1; i<nums.size(); i++){
            temp2.push_back(nums[i]);
        }
        int n = temp1.size();
        int m = temp2.size();


        vector<int> dp1(n,-1);
        vector<int> dp2(m,-1);

        return max(maxMoneyRobbed(n-1,temp1,dp1),maxMoneyRobbed(m-1,temp2,dp2));
    }
};
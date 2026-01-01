class Solution {
public:
    int findNumberOfLIS(vector<int>& nums) {
        int n = nums.size();
        vector<int> dp(n,1), occurance(n,1);
        int cnt = 0;
        int maxLen = 0;
        for(int ind = 0; ind<n; ind++){
            for(int prev_ind = 0; prev_ind<ind; prev_ind++){
                if(nums[ind]>nums[prev_ind] && dp[ind]<dp[prev_ind]+1){
                    dp[ind] = dp[prev_ind] + 1;
                    occurance[ind] = occurance[prev_ind];
                }
                else if(nums[ind]>nums[prev_ind] && dp[ind]==dp[prev_ind]+1){
                    occurance[ind]+= occurance[prev_ind];
                }
            }
            maxLen = max(maxLen, dp[ind]);
        }

        for(int i = 0; i<occurance.size(); i++){
            if(dp[i]==maxLen){
                cnt+= occurance[i];
            }
        }
        return cnt;
    }
};
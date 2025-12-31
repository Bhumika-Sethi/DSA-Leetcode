class Solution {
public:
    vector<int> largestDivisibleSubset(vector<int>& nums) {
        int n = nums.size();
        sort(nums.begin(),nums.end());
        vector<int> dp(n,0);
        vector<int> hash(n);
        for(int i = 0; i<n; i++){
            hash[i] = i;
        }
        int last_ind = 0;
        int maxLen = 0;
        for(int ind = 1; ind<n; ind++){
            for(int prev_ind = 0; prev_ind<ind; prev_ind++){
                if(nums[ind]%nums[prev_ind]==0 && dp[ind]<(dp[prev_ind]+1)){
                    dp[ind] = dp[prev_ind] + 1;
                    hash[ind] = prev_ind;
                }
            }
            if(maxLen<dp[ind]){
                maxLen = dp[ind];
                last_ind = ind;
            }
        }

        vector<int> sol;
        sol.push_back(nums[last_ind]);

        while(hash[last_ind]!=last_ind){
            last_ind = hash[last_ind];
            sol.push_back(nums[last_ind]);
        }
        return sol;
    }
};
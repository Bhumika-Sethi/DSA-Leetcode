class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int zeros = 0;
        int maxLen = 0;
        int l = 0;
        int r = 0;
        int n = nums.size();
        while(r<n){
            if(nums[r]==0){
                zeros++;
            }
            while(zeros>k){
                if(nums[l]==0){
                    zeros--;
                }
                l++;
            }
            int len = r-l+1;
            maxLen = max(len,maxLen);
            r++;
        }
        return maxLen;
    }
};
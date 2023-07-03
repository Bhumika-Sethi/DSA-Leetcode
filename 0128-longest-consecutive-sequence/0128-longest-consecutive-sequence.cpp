class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        int n = nums.size();
        if(n==0){
            return 0;
        }
        sort(nums.begin(),nums.end());
        int maxi = 1;
        int cnt=  1;
        for(int i = 1; i<n; i++){
            if(nums[i]==nums[i-1]){
                continue;
            }
            if(nums[i]==nums[i-1]+1){
                cnt++;
            }
            else{
                cnt = 1;
            }
            maxi = max(cnt,maxi);
        }
        return maxi;
    }
};
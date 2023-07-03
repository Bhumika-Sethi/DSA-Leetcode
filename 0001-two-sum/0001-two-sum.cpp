class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        int n = nums.size();
        map<int,int> mp;
        for(int i = 0; i<n; i++){
            int moreNeeded = target - nums[i];
            if(mp.find(moreNeeded)!=mp.end()){
                return {mp[moreNeeded],i};
            }
            mp[nums[i]] = i;
            
        }
        return {};
    }
};
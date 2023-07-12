class Solution {
    
    void subsetsWithoutDup(int ind, int n, vector<int>& nums, vector<int>& v, vector<vector<int>>& ans){
        ans.push_back(v);
        
        for(int i = ind; i<n; i++){
            if(i>ind && nums[i-1]==nums[i]){
                continue;
            }
            v.push_back(nums[i]);
            subsetsWithoutDup(i+1,n,nums,v,ans);
            v.pop_back();
        }
    }
    
    
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector<vector<int>> ans;
        vector<int> v;
        int n = nums.size();
        sort(nums.begin(),nums.end());
        
        subsetsWithoutDup(0,n,nums,v,ans);
        
        return ans;
    }
};
class Solution {
public:
    void subsetsWithoutDup(int i, vector<int>& ds, vector<vector<int>>& ans, int n, vector<int>& nums){
        ans.push_back(ds);
        for(int ind = i; ind<n; ind++){
            if(ind!=i && nums[ind]==nums[ind-1]){
                continue;
            }
            ds.push_back(nums[ind]);
            subsetsWithoutDup(ind+1,ds,ans,n,nums);
            ds.pop_back();
        }
    }

    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector<vector<int>> ans;
        vector<int> ds;
        sort(nums.begin(),nums.end());
        subsetsWithoutDup(0,ds,ans,nums.size(),nums);
        return ans;
    }
};
class Solution {
    void permutation(int ind, int n,vector<int>& nums, vector<int>& ds, vector<vector<int>>& ans){
        if(ind==n){
            ans.push_back(ds);
            return;
        }
        
        for(int i = ind; i<n; i++){
            swap(nums[i],nums[ind]);
            ds.push_back(nums[ind]);
            permutation(ind+1,n,nums,ds,ans);
            swap(nums[i],nums[ind]);
            ds.pop_back();
        }
    }
public:
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> ans;
        vector<int> ds;
        int n = nums.size();
        permutation(0,n,nums,ds,ans);
        return ans;
    }
};
class Solution {
public:
    void allPossibleSubsets(int i, vector<int>& nums, int n,  vector<int> ds,set<vector<int>>& ans) {
        if(i==n){
            ans.insert(ds);
            return;
        }
        ds.push_back(nums[i]);
        allPossibleSubsets(i+1,nums,n,ds,ans);
        ds.pop_back();
        allPossibleSubsets(i+1,nums,n,ds,ans);
    }
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<int> ds;
        set<vector<int>> ans;
        allPossibleSubsets(0,nums,nums.size(),ds,ans);
        vector<vector<int>> allSubset(ans.begin(),ans.end());
        return allSubset;
    }
};
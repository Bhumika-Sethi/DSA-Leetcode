class Solution {
public:

    void combinationSum(int i, int sum,vector<int>& ds,vector<vector<int>>& ans,int n,vector<int>& candidates, int target){
        if(sum>target){
            return;
        }
        if(sum==target){
            ans.push_back(ds);
            return;
        }
        if(i==n){
           if(sum==target){
                ans.push_back(ds);
                return;
            } 
            return; 
        }
        // take
        ds.push_back(candidates[i]);
        combinationSum(i,sum+candidates[i],ds,ans,n,candidates,target);
        ds.pop_back();
        // not take
        combinationSum(i+1,sum,ds,ans,n,candidates,target);

    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> ans;
        vector<int> ds;
        int sum = 0;
        combinationSum(0,0,ds,ans,candidates.size(),candidates,target); 
        return ans;
    }
};
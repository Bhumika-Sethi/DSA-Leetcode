class Solution {
public:
    void combSum(int i, int sum, vector<int>& ds, vector<vector<int>>& ans, int n, int target){
        if(sum==target && ds.size()==n){
            ans.push_back(ds);
            return;
        }
        if(sum>target || n<ds.size()){
            return;
        }
        for(int ind=i; ind<=9; ind++){
            ds.push_back(ind);
            combSum(ind+1,sum+ind,ds,ans,n,target);
            ds.pop_back();
        }
    }
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<vector<int>> ans;
        vector<int> ds;
        combSum(1,0,ds,ans,k,n);
        return ans;
    }
};
class Solution {
    
    void sum(int i, int target, int n, vector<int>& v, vector<vector<int>>& ans, vector<int>& arr){
        if(target==0){
            ans.push_back(v);
            return;
        }
        if(i==n){
            return;
        }
        
        sum(i+1,target,n,v,ans,arr);
        if(target-arr[i]>=0){
            v.push_back(arr[i]);
            sum(i,target-arr[i],n,v,ans,arr);
            v.pop_back();
        }  
    }
    
    
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> ans;
        vector<int> v;
        int n = candidates.size();
        sum(0,target,n,v,ans,candidates);
        return ans;
    }
};
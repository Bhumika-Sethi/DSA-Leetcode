class Solution {
public:
    
    void sum2(int ind, int target, int n, vector<int>& nums, vector<int>& v, vector<vector<int>>& ans){
        
        if(target==0){
            ans.push_back(v);
            return;
        }
        
       for(int i = ind; i<n; i++){
           if(i>ind && nums[i]==nums[i-1]){
                   continue;
             }
           if(target-nums[i]>=0){
               target -= nums[i];
               v.push_back(nums[i]);
               sum2(i+1,target,n,nums,v,ans);
               target += nums[i];
               v.pop_back();
           }
           
       }
    }
    
    
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<vector<int>> ans;
        vector<int> v;
        sort(candidates.begin(),candidates.end());
        int n = candidates.size();
        sum2(0,target,n,candidates,v,ans);
        return ans;
    }
};
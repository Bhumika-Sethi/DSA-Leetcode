class Solution {
public:
    void combinationSum(int i, int sum, vector<int>& ds, vector<vector<int>>& ans, int n, vector<int>& candidates, int target){
        //This was missed causing issue previously. whenever target == sum, at that time only push the answer, no need to deep dive into all elements
        if(target==sum){
            ans.push_back(ds);
            return;
        }
        if(sum>target){
            return;
        }
        if(i==n){
            return;
        }
        for(int ind = i; ind<n; ind++){
            if(ind!=i && candidates[ind-1]==candidates[ind]){
                continue;
            }
            ds.push_back(candidates[ind]);
            combinationSum(ind+1,sum+candidates[ind],ds,ans,n,candidates,target);
            ds.pop_back();
        }
    }
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<int> ds;
        vector<vector<int>> ans;
        int sum = 0;
        sort(candidates.begin(),candidates.end());
        combinationSum(0,0,ds,ans,candidates.size(),candidates,target);
        return ans;
    }
};
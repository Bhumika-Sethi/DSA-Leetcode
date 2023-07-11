class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        if(nums.size()==0){
            return 0;
        }
        int n = nums.size();
        sort(nums.begin(),nums.end());
        set<int> st;
        for(int i = 0; i<n; i++){
            st.insert(nums[i]);
        }
        vector<int> ans(st.begin(),st.end());
        int cnt = 1;
        int maxi = 1;
        for(int i = 1; i<ans.size(); i++){
            if(ans[i]==ans[i-1]+1){
                cnt++;
            }
            else{
                cnt = 1;
            }
            maxi = max(maxi,cnt);
        }
        return maxi;
    }
};
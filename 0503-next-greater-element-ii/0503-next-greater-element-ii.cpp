class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        int n = nums.size();
        int ini =  nums.size();
        for(int i = 0; i<n-1; i++){
            nums.push_back(nums[i]);
            // cout<<nums[i]<<endl;
        }
        stack<int> st;
        vector<int> nge;
        for(int i = nums.size()-1; i>=0; i--){
            while(!st.empty() && nums[i]>=st.top()){
                st.pop();
            }
            if(st.empty() && i<n){
                nge.push_back(-1);
            }
            else if(!st.empty() && i<n){
                nge.push_back(st.top());
            }
            st.push(nums[i]);
        }
        reverse(nge.begin(),nge.end());

        return nge;

    }
};
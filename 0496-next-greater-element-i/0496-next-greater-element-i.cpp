class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        int n = nums1.size();
        int m  = nums2.size();
        vector<int> nge;
        vector<int> ans;
        stack<int> st;
        for(int i = m-1; i>=0; i--){
            while(!st.empty() && nums2[i]> st.top()){
                st.pop();
            }
            if(st.empty()){
                nge.push_back(-1);
            }
            else{
                nge.push_back(st.top());
            }
            st.push(nums2[i]);
        }
        reverse(nge.begin(),nge.end());

        for(int i = 0; i<n; i++){
            int toFind = nums1[i];
            for(int j = 0; j<m; j++){
                if(toFind==nums2[j]){
                    ans.push_back(nge[j]);
                }
            }
        }
        return ans;
    }
};
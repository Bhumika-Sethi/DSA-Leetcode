class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        stack<int> st;
        int n = nums2.size();
        map<int,int> ans;
        for(int i = n-1; i>=0; i--){
            if(st.empty()){
                ans[nums2[i]] = -1;
                st.push(nums2[i]);
            }
            else if(st.top()<=nums2[i]){
                while(!st.empty() && st.top()<=nums2[i]){
                    st.pop();
                }
                if(!st.empty()){
                    ans[nums2[i]] = st.top();
                    st.push(nums2[i]);                
                }
                else{
                    ans[nums2[i]] = -1;
                     st.push(nums2[i]);  
                }
            }
            else{
                ans[nums2[i]] = st.top();
                st.push(nums2[i]);                        
            }
        }
        vector<int> anss;
        int m = nums1.size();
        for(int i = 0; i<m; i++){
            if(ans[nums1[i]]){
                anss.push_back(ans[nums1[i]]);
            }
        }
        return anss;
    }
};
class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        deque<int> dq;
        int n = nums.size();
        vector<int> ans;
        for(int i = 0; i<n; i++){
            while(!dq.empty() && i-k>=dq.front()){
                dq.pop_front();
            }

            while(!dq.empty() && nums[dq.back()]<=nums[i]){
                dq.pop_back();
            }
            dq.push_back(i);

            if(i>=k-1){
                if(!dq.empty()){
                    ans.push_back(nums[dq.front()]);
                }
                else{
                    ans.push_back(-1);
                }
            }
        }
        return ans;
    }
};
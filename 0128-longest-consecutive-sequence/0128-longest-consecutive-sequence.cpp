class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> st(nums.begin(),nums.end());
        int maxCnt = 0;

        for(auto numb: st){
            if(st.find(numb-1)==st.end()){
                int cnt = 1;
                while(st.find(numb+1)!=st.end()){
                    cnt++;
                    numb+=1;
                    
                }
                maxCnt = max(cnt,maxCnt);
            }
        }
        return maxCnt;
    }
};
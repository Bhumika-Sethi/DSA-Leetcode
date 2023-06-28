class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        int n = intervals.size();
        vector<vector<int>> ans;
        sort(intervals.begin(),intervals.end());
        ans.push_back(intervals[0]);
        for(int i = 1; i<n; i++){
            int start = intervals[i][0];
            int end = intervals[i][1];
            if(end <= ans.back()[1]){
                continue;
            }
            else if(ans.back()[1]>=start){
                ans.back()[1] = end;
            }
            else if(ans.back()[1]<start){
                ans.push_back({start,end});
            }
        }
        return ans;
    }
};
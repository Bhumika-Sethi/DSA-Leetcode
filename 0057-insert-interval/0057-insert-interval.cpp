class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        int intervalStart = newInterval[0];
        int intervalEnd = newInterval[1];
        int i = 0;
        int n = intervals.size();
        vector<vector<int>> ans;
        // end of interval is less than start of new interval
        while(i<n && intervals[i][1]<intervalStart){
            ans.push_back(intervals[i]);
            i++;
        }
        // end of new interval is greater than equal to start of interval
        while(i<n && intervalEnd>=intervals[i][0]){
            intervalStart = min(intervalStart, intervals[i][0]);
            intervalEnd = max(intervalEnd, intervals[i][1]);
            i++;
        }
        ans.push_back({intervalStart,intervalEnd});

        // end of newInterval is less than start of existing interval
        while(i<n && intervals[i][0]>intervalEnd){
            ans.push_back(intervals[i]);
            i++;
        }
        return ans;
    }
};
class Solution {
public:
    static bool comp(vector<int>& interval1, vector<int>& interval2){
        return (interval1[1]!=interval2[1]) ? interval1[1]<interval2[1]: interval1[0]<interval2[0];
    }
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        int n = intervals.size();
        int nonOverlappingCount = 1;
        sort(intervals.begin(),intervals.end(),comp);
        int EndTime = intervals[0][1];
        for(int i = 1; i<n; i++){
            if(intervals[i][0]>=EndTime){
                EndTime = intervals[i][1];
                nonOverlappingCount++;
            }
        }
        return n-nonOverlappingCount;
    }
};
class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        int n = intervals.size();
       sort(intervals.begin(), intervals.end());
       vector<vector<int>> ans;
       vector<int> currentInterval = intervals[0]; 

       for(int i = 0; i<n; i++){
        // Overlapping - if start time is falling under curent Interval then just take the max of end time and merge it
        if(intervals[i][0]<=currentInterval[1]){
            currentInterval[1] = max(intervals[i][1],currentInterval[1]);
        }
        // non-overlapping means, just put it in answer array and then pick the interval as currentInterval
        else{
            ans.push_back(currentInterval);
            currentInterval = intervals[i];
        }
       }
       ans.push_back(currentInterval);
       return ans;
    }
};
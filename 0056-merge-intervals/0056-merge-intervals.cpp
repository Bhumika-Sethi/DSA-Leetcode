class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        // Optimal - TC - O(N)
        //         - SC - O(1)
        sort(intervals.begin(),intervals.end());
        int n = intervals.size();
        vector<vector<int>> ans;
        // Intuition
        // Insert the element into ans
        // Run a loop from 0 to n
        // Check if last inserted element's end is greater than or equal to front of interval
        // If yes, then check whose end is greater
        // If ans's end is greater than let it be
        // Otherwise, change ans's end to interval's end
        // If the ans end is smaller than interval's front or it is the 1st element then just insert it into answer
        for(int i = 0; i<n; i++){
            if(ans.size()!=0 && ans.back()[1]>=intervals[i][0] && ans.back()[1]<intervals[i][1]){
                ans.back()[1] = intervals[i][1];
            }
            else if(ans.size()==0 || (ans.size()!=0 && ans.back()[1]<intervals[i][0])){
                ans.push_back(intervals[i]);
            }
        }
        return ans;
    }
};
class Solution {
public:
    int minimumEffortPath(vector<vector<int>>& heights) {
        vector<vector<int>> diff(heights.size(),vector<int>(heights[0].size(),INT_MAX));
        priority_queue<pair<int,pair<int,int>>,vector<pair<int,pair<int,int>>>, greater<pair<int,pair<int,int>>>> pq;
        int n = heights.size();
        int m = heights[0].size();
        pq.push({0,{0,0}});
        diff[0][0] = 0;
        int delRow[4] = {0,-1,0,+1};
        int delCol[4] = {-1,0,+1,0};
        while(!pq.empty()){
            int difference = pq.top().first;
            int row = pq.top().second.first;
            int col = pq.top().second.second;
            if(row==n-1 && col==m-1){
                return diff[row][col];
            }
            pq.pop();
            for(int i = 0; i<4; i++){
                int nrow = row + delRow[i];
                int ncol = col + delCol[i];
                if(nrow>=0 && nrow<n && ncol>=0 && ncol<m){
                    int maxDifference = max(difference,abs(heights[nrow][ncol]-heights[row][col]));
                    if(maxDifference<diff[nrow][ncol]){
                        diff[nrow][ncol] = maxDifference;
                        pq.push({diff[nrow][ncol],{nrow,ncol}});
                    }
                }

            }
        }
        return {-1};
    }
};
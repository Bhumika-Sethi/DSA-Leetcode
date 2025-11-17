class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        vector<vector<int>> dist(grid.size(),vector<int>(grid[0].size(),INT_MAX));
        int delRow[8] = {0,-1,-1,-1,0,+1,+1,+1};
        int delCol[8] = {-1,-1,0,+1,+1,+1,0,-1};
        if(grid[0][0]==1){
            return -1;
        }
        queue<pair<int,int>> q;
        q.push({0,0});
        dist[0][0] = 0;
        int n = grid.size();
        int m = grid[0].size();
        while(!q.empty()){
            int row = q.front().first;
            int col = q.front().second;

            q.pop();

            for(int i = 0; i<8; i++){
                int nrow = row + delRow[i];
                int ncol = col + delCol[i];

                if(nrow>=0 && nrow<n && ncol>=0 && ncol<m && grid[nrow][ncol]==0){
                    if(1+dist[row][col]<dist[nrow][ncol]){
                        dist[nrow][ncol] = 1+dist[row][col];
                        q.push({nrow,ncol});
                    }
                }
            }
        }
        if(dist[n-1][m-1]!=INT_MAX){
            return dist[n-1][m-1]+1;
        }
        return -1;
    }
};
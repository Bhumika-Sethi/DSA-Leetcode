class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        queue<pair<pair<int,int>,int>> q;
        int time = 0;
        int cntFresh = 0;
        vector<vector<int>> rottenMatrix = grid;
        for(int i=  0; i<grid.size(); i++){
            for(int j = 0; j<grid[i].size(); j++){
                if(grid[i][j]==2){
                    q.push({{i,j},0});
                }
                else if(grid[i][j]==1){
                    cntFresh++;
                }
            }
        }
        int cntTurned = 0;
        int gridSize = grid.size();
        int gridColSize = grid[0].size();
        int delRow[4] = {0,-1,0,1};
        int delCol[4] = {-1,0,1,0};
        while(!q.empty()){
            int n = q.size();
            for(int i = 0; i<n; i++){
                int row = q.front().first.first;
                int col = q.front().first.second;
                int t = q.front().second;
                time = max(t,time);
                q.pop();
                for(int i = 0; i<4; i++){
                    int nrow = row + delRow[i];
                    int ncol = col + delCol[i];
                    if(nrow>=0 && nrow<gridSize && ncol>=0 && ncol<gridColSize && grid[nrow][ncol]==1 && rottenMatrix[nrow][ncol]!=2){
                        rottenMatrix[nrow][ncol] = 2;
                        cntTurned++;
                        q.push({{nrow,ncol},t+1});
                    }
                }
            }
        }
        if(cntTurned!=cntFresh){
            return -1;
        }
        return time;
    }
};
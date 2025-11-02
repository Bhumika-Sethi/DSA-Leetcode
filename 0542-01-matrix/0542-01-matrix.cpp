class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        queue<pair<int,int>> q;
        vector<vector<int>> dis(mat.size(),vector<int>(mat[0].size(),-1));
        int n = mat.size();
        int m = mat[0].size();
        for(int i = 0; i<n; i++){
            for(int j = 0; j<m; j++){
                if(mat[i][j]==0){
                    q.push({i,j});
                    dis[i][j] = 0;
                }
            }
        }
        int delRow[4] = {0,-1,0,+1};
        int delCol[4] = {-1,0,+1,0};

        while(!q.empty()){
            int row = q.front().first;
            int col = q.front().second;
            q.pop();

            for(int i = 0; i<4; i++){
                int nrow = row + delRow[i];
                int ncol = col + delCol[i];

                if(nrow>=0 && nrow<n && ncol>=0 && ncol<m && mat[nrow][ncol]==1 && dis[nrow][ncol]==-1){
                    dis[nrow][ncol] = dis[row][col] + 1;
                    q.push({nrow,ncol});
                }
            }
        }
        return dis;
    }
};
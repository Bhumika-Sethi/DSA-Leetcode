class Solution {
public:
    void dfs(int r, int c, int n, int m, int row[], int col[],vector<vector<int>>& vis, vector<vector<char>>& grid){
        vis[r][c] = 1;

        for(int i = 0; i<4; i++){
            int nrow = r + row[i];
            int ncol = c + col[i];

            if(nrow>=0 && nrow<n && ncol>=0 && ncol<m && !vis[nrow][ncol] && grid[nrow][ncol]=='1'){
                dfs(nrow,ncol,n,m,row,col,vis,grid);
            }
        }
    }
    int numIslands(vector<vector<char>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<int>> vis(n,vector<int>(m,0));
        int cnt = 0;
        int row[4] = {0,-1,0,1};
        int col[4] = {-1,0,1,0};
        for(int i = 0; i<n; i++){
            for(int j = 0; j<m; j++){
                if(vis[i][j]==0 && grid[i][j]=='1'){
                    cnt++;
                    dfs(i,j,n,m,row,col,vis,grid);
                }
            }
        }
        return cnt;
    }
};
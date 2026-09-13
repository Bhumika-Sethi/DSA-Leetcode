class Solution {
public:

    void dfs(int row, int col, vector<vector<int>>& heights, int drow[],int dcol[], int n, int m, vector<vector<bool>>& ocean){
        ocean[row][col] = 1;

        for(int i = 0; i<4; i++){
            int newRow = drow[i] + row;
            int newCol = dcol[i] + col;
            if(newRow>=0 && newRow<n && newCol>=0 && newCol<m && !ocean[newRow][newCol] && heights[row][col]<=heights[newRow][newCol]){
                dfs(newRow,newCol,heights,drow,dcol,n,m,ocean);
            }
        }
    }


    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        int n = heights.size();
        int m = heights[0].size();
        vector<vector<bool>> pacific(n,vector<bool>(m,false));
        vector<vector<bool>> atlantic(n,vector<bool>(m,false));
        vector<vector<int>> ans;
        int dcol[4] = {-1,0,1,0};
        int drow[4] = {0,-1,0,1};
        for(int r=0; r<n; r++){
            dfs(r,0,heights,drow,dcol,n,m,pacific);
        }

        for(int c=0; c<m; c++){
            dfs(0,c,heights,drow,dcol,n,m,pacific);
        }

        for(int r=0; r<n; r++){
            dfs(r,m-1,heights,drow,dcol,n,m,atlantic);
        }

        for(int c=0; c<m; c++){
            dfs(n-1,c,heights,drow,dcol,n,m,atlantic);
        }
        for(int i = 0; i<n; i++){
            for(int j = 0; j<m; j++){
                if(atlantic[i][j]==1 && pacific[i][j]==1){
                    ans.push_back({i,j});
                }
            }
        }
        return ans;

    }
};
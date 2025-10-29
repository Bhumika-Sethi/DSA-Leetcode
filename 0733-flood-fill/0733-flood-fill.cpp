class Solution {
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        int curr_col = image[sr][sc];
        if (color == curr_col) return image;
        vector<vector<int>> vis = image;
        for(int i = 0; i<image.size(); i++){
            for(int j = 0; j<image[i].size(); j++){
                vis[i][j] = 0;
            }
        }
        queue<pair<int,int>> q;
        q.push({sr,sc});
        image[sr][sc] = color;
        vis[sr][sc] = 1;
        int delRow[4] = {0,-1,0,1};
        int delCol[4] = {-1,0,1,0};
        int n = image.size();
        int m = image[0].size();
        while(!q.empty()){
            int row = q.front().first;
            int col = q.front().second;
            q.pop();

            for(int i = 0; i<4; i++){
                int nrow = row + delRow[i];
                int ncol = col + delCol[i];

                if(nrow>=0 && nrow<n && ncol>=0 && ncol<m && image[nrow][ncol]==curr_col && !vis[nrow][ncol]){
                    vis[nrow][ncol] = 1;
                    q.push({nrow,ncol});
                    image[nrow][ncol] = color;
                }
            }
        }
        return image;
    }
};
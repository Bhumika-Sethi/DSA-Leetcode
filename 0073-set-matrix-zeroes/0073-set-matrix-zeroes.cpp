class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        int n = matrix.size();
        int m = matrix[0].size();
        vector<int> row(n,0), col(m,0);
        for(int i = 0; i<n; i++){
            for(int j = 0; j<m; j++){
                if(matrix[i][j]==0){
                    for(int k = 0; k<m; k++){
                        if(matrix[i][k] != 0){
                            matrix[i][k] = -1e9;
                        }
                    }
                    for(int l = 0; l<n; l++){
                        if(matrix[l][j]!= 0){
                            matrix[l][j] = -1e9;
                        }
                    }
                }
            }
        }
        
        for(int i = 0; i<n; i++){
            for(int j = 0; j<m; j++){
                if(matrix[i][j] == -1e9){
                    matrix[i][j] = 0;
                }
            }
        }
    }
};
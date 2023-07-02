class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int n = matrix.size();
        int m = matrix[0].size();
        for(int i = 0; i<n; i++){
            if(matrix[i][m-1]<target){
                continue;
            }
            else{
                for(int j = 0; j<m; j++){
                    if(matrix[i][j]==target){
                        return true;
                    }
                }
            }
        }
        return false;
    }
};
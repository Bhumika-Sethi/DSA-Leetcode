class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int low = 0;
        int n = matrix.size();
        int m = matrix[0].size();
        int high = m*n - 1;
        
        while(low <= high){
            int middle = (high+low)/2;
            if(matrix[middle/m][middle%m]==target){
                return true;
            }
            else if(matrix[middle/m][middle%m]<target){
                low = middle + 1;
            }
            else{
                high = middle - 1;
            }
        }
        return false;
    }
};




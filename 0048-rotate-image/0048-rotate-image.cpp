class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        //    Optimised -> TC -> O(N*2)
        //              -> SC -> O(1)
        int n = matrix.size();
        int m = matrix[0].size();
        for(int i = 0; i<n; i++){
            // In transpose we start from element after diagonal
            // So that's why j = i+1 till j<m
            int j = i+1;
            while(j<m){
                // transpose the matrix -> row become column become row
                // Inshort, swap row with column
                swap(matrix[i][j],matrix[j][i]);
                j++;
            }
        } 
        // Now reverse the rows to obtain 90degree turn
        for(int i =  0; i<n; i++){
            reverse(matrix[i].begin(),matrix[i].end());
        }
    }
};
class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        // Optimal Solution -> TC - O(N*2)
        //                  -> SC - O(N) -> For returning answer
        // Just doing what is mentioned
        int n = matrix.size();
        int m = matrix[0].size();
        int top = 0, bottom = n-1;
        int left = 0, right = m-1;
        vector<int> ans;
        while(top<=bottom && left<=right){
            // Move Left -> Right (Top is constant->check if it is within limit using if condition)
            if(top<=bottom){
                int j = left;
                while(j<=right){
                    ans.push_back(matrix[top][j++]);
                }
                top++;
            }
            // Mov Top to Bottom(Right is constant->check if it is within limit using if condition)
            if(right>=left){
                int i = top;
                while(i<=bottom){
                    ans.push_back(matrix[i++][right]);
                }
                right--;
            }
            // Move Right to Left(Bottom is constant->check if it is within limit using if condition)
            if(bottom>=top){
                int j = right;
                while(j>=left){
                    ans.push_back(matrix[bottom][j--]);
                }
                bottom--;
            }
            // Move Bottom to Top(Left is constant->check if it is within limit using if condition)
            if(left<=right){
                int i = bottom;
                while(i>=top){
                    ans.push_back(matrix[i--][left]);
                }
                left++;
            }
        }
        return ans;
    }
};
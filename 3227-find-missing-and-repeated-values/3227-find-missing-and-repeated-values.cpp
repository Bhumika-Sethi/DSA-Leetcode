class Solution {
public:
    vector<int> findMissingAndRepeatedValues(vector<vector<int>>& grid) {
        // Better/Optimal approach : TC - O(N)-> O(n*m)
        //             : SC - O(1)
        int missing = -1, repeating = -1;
        int n = grid.size();
        int m = grid[0].size();
        int N = n*m;
        // Use Math
        //SN -  Sum of N natural numbers is (n)(n+1)/2
        // S2N - Sum of square of N natural numbers is (n)(n+1)(2n+1)/6
        // X is repeating number
        // Y is missing number
        // val1 = S - SN = X - Y -eq2
        // val2 = S2 - S2N = X^2 - Y^2
        // val2 = S2 - S2N = (X+Y)(X-Y)
        // val2 = S2 - SN2 = (X+Y)(val1)
        // val2 = (X+Y)(val1)
        // val2/val1 = X + Y -eq1
        // Add equation 1 and 2
        // 2X = val2/val1 + val1
        // X = (val2/val1 + val1)/2
        // Y = X - val1
        long long Sn = 0, S2n = 0;
        Sn = N*(N+1);
        Sn /= 2;
        S2n = N*(N+1);
        S2n *= (2*N+1);
        S2n /= 6;
        long long S = 0;
        long long S2 = 0;

        for(int i = 0; i<n; i++){
            for(int j = 0; j<m; j++){
                S += grid[i][j];
                int sq = grid[i][j]*grid[i][j];
                S2 += sq;
            }
        }
        int val1 = S - Sn;
        int val2 = S2 - S2n;
        int X = (val2/val1 + val1)/2;
        int Y = X - val1;
        repeating  = X;
        missing = Y;
        return {repeating,missing};
    }
};
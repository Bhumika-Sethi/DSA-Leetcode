class Solution {
public:
    int climbStairsclimbStairs(int n, vector<int>& memo) {
        if(n==1){
            return 1;
        }
        if(n==2){
            return 2;
        }
        if(memo[n]!=-1){
            return memo[n];
        }
        return memo[n] = climbStairsclimbStairs(n-1,memo) + climbStairsclimbStairs(n-2,memo);

    }

    int climbStairs(int n){
        vector<int> memo(n+1,-1);

        return climbStairsclimbStairs(n,memo);
    }
};
class Solution {
public:
    int candy(vector<int>& ratings) {
        int n = ratings.size();
        vector<int> leftNeighbor(n,1);
        vector<int> rightNeighbor(n,1);
        int candyCount = 0;
        int leftCandy = 1;
        int rightCandy = 1;
        for(int i = 1; i<n; i++){
            if(ratings[i]>ratings[i-1]){
                leftCandy++;
            }
            else{
                leftCandy = 1;
            }
            leftNeighbor[i] = leftCandy;
        }

        for(int i = n-2; i>=0; i--){
            if(ratings[i]>ratings[i+1]){
                rightCandy++;
            }
            else{
                rightCandy = 1;
            }
            rightNeighbor[i] = rightCandy;
        }

        for(int i = 0; i<n; i++){
            candyCount += max(leftNeighbor[i],rightNeighbor[i]);
        }
        return candyCount;
    }
};
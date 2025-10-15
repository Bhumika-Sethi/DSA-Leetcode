class Solution {
public:
    int maxScore(vector<int>& cardPoints, int k) {
        int sum = 0;
        for(int i = 0; i<k; i++){
            sum += cardPoints[i];
        }
        int n = cardPoints.size();
        int l = k-1, r = n-1;
        int maxSum = sum;
        while(l>=0){
            sum -= cardPoints[l];
            sum += cardPoints[r];
            maxSum = max(maxSum,sum);
            l--;
            r--;
        }
        return maxSum;
    }
};
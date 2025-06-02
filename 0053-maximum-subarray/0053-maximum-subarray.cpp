class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        // Optimal approach - kadane algorithm
        // Printing start and end index as well
        // return maxSum
        // TC - O(N)
        // SC O(1)
        int n = nums.size();
        int sum = 0;
        int maxi = INT_MIN;
        int start = -1;
        int ansStart = -1;
        int ansEnd = -1;
        for(int i  = 0; i<n; i++){
            if(sum==0){
                start = i;
            }
            sum += nums[i];
            if(maxi<sum){
                maxi = sum;
                ansStart = start;
                ansEnd = i;
            }
            if(sum<0){
                sum = 0;
            }
        }
        cout<<"Start Index of maximum subarray sum"<<ansStart<<" ending index of maximum index of maximum subarray sub "<<ansEnd<<endl;
        return maxi;
    }
};
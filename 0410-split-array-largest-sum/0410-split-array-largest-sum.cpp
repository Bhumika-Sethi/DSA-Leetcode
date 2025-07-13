class Solution {
public:
    int possibleToSplitIntoK(int splitSize, int k, vector<int>& nums){
        int n = nums.size();
        int splitPart = 1;
        int sum = 0;
        for(int i = 0; i<n; i++){
            if(sum+nums[i]>splitSize){
                splitPart++;
                sum = nums[i];
            }
            else{
                sum += nums[i];
            }
        }
        return splitPart <= k;
    }
    int splitArray(vector<int>& nums, int k) {
        int n = nums.size();
        int maxi = *max_element(nums.begin(),nums.end());
        int sum = accumulate(nums.begin(),nums.end(),0);
        int low = maxi;
        int high = sum;
        while(low<=high){
            int mid = low + (high-low)/2;
            if(possibleToSplitIntoK(mid,k,nums)){
                high = mid - 1;
            }       
            else{
                low = mid +1;
            }
        }
        return low;
    }
};
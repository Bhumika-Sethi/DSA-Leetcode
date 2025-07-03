class Solution {
public:
    bool DivisorPossibleWithinLimit(vector<int>& nums, int divisor, int threshold){
        int totalSum = 0;
        for(auto it:nums){
            totalSum += (it/divisor);
            if(it%divisor){
                totalSum += 1;
            }
        }
        return totalSum<=threshold;
    }
    int smallestDivisor(vector<int>& nums, int threshold) {
        int n = nums.size();
        int low = 1;
        int high = *max_element(nums.begin(),nums.end());
        int ans = -1;

        while(low<=high){
            int mid = low + (high-low)/2;
            if(DivisorPossibleWithinLimit(nums,mid,threshold)){
                ans = mid;
                high = mid - 1;
            }
            else{
                low = mid + 1;
            }
        }
        return ans;
    }
};
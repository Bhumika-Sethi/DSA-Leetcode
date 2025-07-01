class Solution {
public:

    int lowerBound(vector<int>& nums, int n, int target){
        int low = 0;
        int high = n-1;
        int ans = n;

        while(low<=high){
            int mid = low + (high-low)/2;
            if(nums[mid]>=target){
                ans = mid;
                high = mid - 1;
            }
            else{
                low = mid + 1;
            }
        }
        return ans;
    }

    int upperBound(vector<int>&nums, int n, int target){
        int low = 0;
        int high = n-1;
        int ans = n;

        while(low<=high){
            int mid = low + (high-low)/2;
            if(nums[mid]>target){
                ans = mid;
                high = mid - 1;
            }
            else{
                low = mid + 1;
            }
        }
        return ans;
    }

    vector<int> searchRange(vector<int>& nums, int target) {
        int first = lowerBound(nums,nums.size(),target);
        if(first==nums.size() || nums[first]!=target){
            return {-1,-1};
        }
        int last = upperBound(nums,nums.size(),target);
        return {first,last-1};
    }
};
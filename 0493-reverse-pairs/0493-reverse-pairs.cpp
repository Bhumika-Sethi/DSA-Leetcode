class Solution {
public:
    void merge(int low, int mid, int high, vector<int>& nums){
        int left = low;
        int right = mid + 1;
        vector<int> temp;

        while(left<=mid && right<=high){
            if(nums[left]<=nums[right]){
                temp.push_back(nums[left++]);
            }
            else{
                temp.push_back(nums[right++]);
            }
        }

        while(left<=mid){
            temp.push_back(nums[left++]);
        }
        while(right<=high){
            temp.push_back(nums[right++]);
        }

        for(int i = low; i<=high; i++){
            nums[i] = temp[i-low];
        }
    }
    int reversePairCount(int low, int mid, int high, vector<int>& nums){
        int cnt = 0;
        int left = low;
        int right = mid+1;
        while(left<=mid){
            long long leftval = nums[left];
            long long rightval = (long long)nums[right]; 
            while(right<=high && leftval>2*rightval){
                right++;
                rightval = (long long)nums[right];
            }
            cnt += (right -(mid+1));
            left++;
        }
        return cnt;
    }
    int mergeSort(int low, int high, vector<int>& nums){
        int cnt = 0;
        if(low>=high){
            return cnt;
        }
        int mid = low + (high-low)/2;
        cnt += mergeSort(low,mid,nums);
        cnt += mergeSort(mid+1,high,nums);
        cnt += reversePairCount(low,mid,high,nums);
        merge(low,mid,high,nums);
        return cnt;
    }
    int reversePairs(vector<int>& nums) {
        // Optimal approach - O(2nlogn)
        //                  - O(n)
        // Merge sort 
        int n = nums.size();
        return mergeSort(0,n-1,nums);
    }
};
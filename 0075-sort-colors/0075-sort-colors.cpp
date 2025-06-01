class Solution {
public:
    void sortColors(vector<int>& nums) {
        //Better solution - TC - O(N)
        //                - SC - O(1)
        // two pointer approach - greedy
        // Dutch National flag algorithm
        // all zeros till 0 - low -1
        // all ones till low to mid - 1
        // unsorted array - containing 0,1 and 2's - mid - high
        // all twos from high+1 to n
        int n = nums.size();
        // here mid si at 0 and high at n-1 as the entire array is unsorted
        int low = 0;
        int mid = 0;
        int high = n-1;
        
        while(mid<=high){
            if(nums[mid]==0){
                // ideally low should be containing 1
                // so when we swap, low is containing 0, so increment low, so that low-1 is having 0
                // and now as we swapped low with mid, now arr[low](1) is now stored at arr[mid](1)
                // that means arr[mid] is sorted
                // It should move +1 to point to unsorted array
                swap(nums[low],nums[mid]);
                low++;
                mid++;
            }
            else if(nums[mid]==1){
                // technically mid-1 should be storing 1, so just increment mid by 1
                mid++;
            }
            else if(nums[mid]==2){
                // technically high+1 should be storing 2
                // so swap arr[mid] with arr[high] and decrement high as it is now storing 2, and 2 should be stored from high+1 to n
                // high should store end of unsorted array.
                // we won't be moving mid as we swapped mid and high, high was originally having any number and we gave it 2.
                // So on swapping any unsorted number would be there in place of mid
                swap(nums[mid],nums[high]);
                high--;
            }
        }
    }
};
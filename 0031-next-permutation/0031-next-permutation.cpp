class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        // Simple observation
        // 1. Longest prefix we need to have
                // So, that means a[i]<a[i+1] -> breakpoint
                // Start from the end and compare when a[i]<a[i+1], that means breakpoint there
                // So store the index we need to switch in ind
                // If ind = -1, than that means no breakpoint. In that case just reverse
                // reverse of current array is the ans.
        // 2. Now find the element just greater than ind 
                // the left of breakpoint is sorted in increasing order from back
                // Run the loop from i = n-1 to ind
                // swap ind element with ith element
                // now also after breakpoint array is sorted
        // 3.Reverse the array after breakpoint
                // Because it is increasing from end and decreasing from start
                // So, we need the smallest -> sort in increasing order
                // So just reverse

        // Optimal approach TC -> O(3*N)
        //                  SC -> O(1)
        int n = nums.size();
        int ind = -1;
        // Find from the back the breakpoint(ind) val
        for(int i = n-2; i>=0; i--){
            if(nums[i]<nums[i+1]){
                ind = i;
                break;
            }
        }

        // If still -1
        // Just reverse and return the answer
        if(ind==-1){
            reverse(nums.begin(),nums.end());
            return;
        }

        // Otherwise from back run the loop till ind and swap with just greater element
        for(int i = n-1; i>ind; i--){
            if(nums[i]>nums[ind]){
                swap(nums[i],nums[ind]);
                break;
            }
        }

        // Now to get the smallest from ind+1 to n -> Just reverse
        reverse(nums.begin()+ind+1,nums.end());

    }
};
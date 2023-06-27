class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        // find the break point - increasing and then decreasing is consider as break point
        // traverse from end;
        int n = nums.size();
        int break_point = -1;
        for(int i = n-2; i >= 0; i--){
            if(nums[i]<nums[i+1]){
                break_point = i;
                break;
            }
        }
        
//      If breakpoint is still -1, then this means that the array is in decreasing order, so next permultation would be increasing order array
        if(break_point==-1){
            reverse(nums.begin(),nums.end());
            return;
        }
        
        
//      Again traverse from the end and find the element just greater than nums[index]
        for(int i = n-1; i>break_point; i--){
                if(nums[break_point]<nums[i]){
                    swap(nums[i],nums[break_point]);
//                     don't forget to break out of it.
                    break;
                }
        }
         // Step 3: reverse the right half:
        reverse(nums.begin()+break_point+1,nums.end());
        return;
    }
};
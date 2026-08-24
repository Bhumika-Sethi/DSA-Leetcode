class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int n = nums.size();
        int j = 0;

        //move till we get the first zero number
        //we are doing so because non-zeros are it's correct position, we need to start swapping when we encounter zero
        while(j<n && nums[j]!=0){
            j++;
        }
        //place i at a position next to j
        int i = j+1;
        //now run the loop till i<n
        while(i<n){
             //if current element is non-zero, we need to place it at the front positions relative to zero, so we'll swap with arr[j]->0 at j index
            if(nums[i]!=0){
                swap(nums[i],nums[j]);
                //move j ahead, as next index would be carrying element 0, or the end of array
                j++;
            }
            i++;
        }

    }
};
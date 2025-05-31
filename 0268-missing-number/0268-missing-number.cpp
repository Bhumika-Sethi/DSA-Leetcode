class Solution {
public:
    int missingNumber(vector<int>& nums) {
        //XOR - Optimised soln
        // TC - O(2*N) where N is [0,nums.size()]
        // SC - O(1)
        // first do XOR of N numbers
        int xorNum = 0;
        for(int i = 0; i<=nums.size(); i++){
            xorNum ^= i;
        }
        // now do it with xor of numbers in array, so it will eliminate same numbers and only number left would be the mssing number
        // xor -> number^number = 0
        //     -> 0^number = number
        for(int j = 0; j<nums.size(); j++){
            xorNum ^= nums[j];
        }
        return xorNum;
    }
};
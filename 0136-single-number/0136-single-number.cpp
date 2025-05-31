class Solution {
public:
    int singleNumber(vector<int>& nums) {
    //Optiomal sol - TL - O(N)
    //             - SP - O(1)
    //XOR Operation -> number^number = 0
    //              -> 0^number = number
    int missingNumb = 0;

    for(int i = 0; i<nums.size(); i++){
        missingNumb = missingNumb^nums[i];
    }
    return missingNumb;
    }
};
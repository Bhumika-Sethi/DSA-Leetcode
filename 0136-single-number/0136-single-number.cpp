class Solution {
public:
    int singleNumber(vector<int>& nums) {
    int singleNum = 0;
    //we'll be doing XOR of all the numbers
    //so the only number tha would be remaining would be single number
    //XOR -> number^number -> 0
    //XOR -> 0^number -> number
      for(int i = 0; i<nums.size(); i++){
        singleNum^=nums[i];
      }  
      return singleNum;
    }
};
class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        //max count of 1's stored in maxi
        int maxi = 0;
        //consecutive cnt stored in cnt
        int cnt =  0;
        int n = nums.size();
        for(int i = 0;i<n; i++){
            //if the element is 1, we'll increase the count
            if(nums[i]==1){
                cnt++;
                // if count is greater than maxi then it becomes our maximum count
                if(cnt>maxi){
                    maxi = cnt;
                }
            }
            // else if element is 0 then we'll again start counting consecutive ones's from the begining that is from 0
            else{
                cnt = 0;
            }
        }
        //return max consecutive ones count
        return maxi;
    }
};
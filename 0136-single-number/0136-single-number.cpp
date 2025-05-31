class Solution {
public:
    int singleNumber(vector<int>& nums) {
    //O(N^2) - Bruteforce solution
        for(int i = 0; i<nums.size(); i++){
            int ele = nums[i];
            int cnt = 0;
            for(int j = 0; j<nums.size(); j++){
                if(nums[j]==ele){
                    cnt++;
                }
            }
            if(cnt==1){
                return ele;
            }
        }
        return -1;
    }
};
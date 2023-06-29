class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int n = nums.size();
        vector<int> frequency(n,0);
        for(int i = 0; i<n; i++){
            if(frequency[nums[i]]==1){
                return nums[i];
            }
            else{
                frequency[nums[i]]++;
            }
        }
        return -1;
    }
};
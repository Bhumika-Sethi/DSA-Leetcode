class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        int n = nums.size();
        for(int i = 0; i<n; i++){
            int sum = nums[i];
            for(int j = i+1; j<n; j++){
                sum += nums[j];
                if(target == sum){
                    return {i,j};
                }
                sum -= nums[j];
            }
        }
        return {-1,-1};
    }
};
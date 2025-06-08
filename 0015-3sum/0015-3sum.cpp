class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        // Optimal approach - TC - O(N^2)+O(NlogN)
        //                  - SC - O(nonDuplicateTriplet)
        // Sort the array and eliminate the set space complexity and insertions TC
        sort(nums.begin(),nums.end());
        vector<vector<int>> ans;
        int n = nums.size();
        for(int i = 0; i<n; i++){
            // this we will do to avoid searching for same i again and doing duplication
            // Check for within limit i.e. i<n as well
            while(i!=0 && i<n && nums[i]==nums[i-1]){
                i++;
            }
            int start = i+1;
            int end = n-1;
            // NOTE : We on't be using start <= end as we don't want to take same element twice
             while(start<end){
                if(nums[i] + nums[start] + nums[end]>0){
                    end--;
                }
                else if(nums[i] + nums[start] + nums[end]<0){
                    start++;
                }
                else if(nums[i] + nums[start] + nums[end]==0){
                    vector<int> temp;
                    temp.push_back(nums[i]);
                    temp.push_back(nums[start]);
                    temp.push_back(nums[end]);
                    ans.push_back(temp);
                    start++;
                    end--;
                    // Please ensure checks that they don't cross boundary
                    // Always not that whenever we are incrementing and then doing task, then check for the boundary first
                    while(start<end && nums[start-1]==nums[start]){
                        start++;
                    }
                    while(start<end && nums[end+1]==nums[end]){
                        end--;
                    }
                }
             }
             
        }
        return ans;
    }
};
class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        // Optimal approach - TC - O(N^3)
        //                  - SC - O(N^2) or O(No of quaduplet*4) - to return answer
        vector<vector<int>> ans;
        sort(nums.begin(),nums.end());
        int n = nums.size();
        for(int i = 0; i<n; i++){
            // Written this to avoid i duplication
            // Example : [2,2,2,2,2], target = 8
            // Output : [[2,2,2,2],[2,2,2,2]] -> if we don't write while for i as well
            // Expected Output : [[2,2,2,2]]
            while(i!=0 && i<n && nums[i]==nums[i-1]){
                    i++;
                }
            for(int j = i+1; j<n; j++){
                // k and l will be following 2 pointer approach
                // this we are doing to avoid duplication
                // and we have inserted j!= i+1 condition as -1 index is inaccessible, similarly for j<n as j==n is inaccessible
                while(j!=i+1 && j<n && nums[j]==nums[j-1]){
                    j++;
                }
                int k = j+1;
                int l = n-1;
                // To avoid taking same element we won't do k<=l
                while(k<l){
                    long long achievedSum = nums[i];
                    achievedSum += nums[j];
                    achievedSum += nums[k];
                    achievedSum += nums[l];

                    if(achievedSum<target){
                        k++;
                    }
                    else if(achievedSum>target){
                        l--;
                    }
                    else{
                        vector<int> temp;
                        temp.push_back(nums[i]);
                        temp.push_back(nums[j]);
                        temp.push_back(nums[k]);
                        temp.push_back(nums[l]);
                        // already in sorted order, insert in ans
                        ans.push_back(temp);
                        k++;
                        l--;
                        // To avoid duplication as sum of 2 same elements will be same only
                        while(k<l && nums[k]==nums[k-1]){
                            k++;
                        }
                        while(k<l && nums[l]==nums[l+1]){
                            l--;
                        }
                    }
                }
            }
        }
        return ans;
    }
};
class Solution {
public:
    
     vector<int> twoSum(vector<int>& nums, int target) {
         map<int,int> mp;
         int n = nums.size();
         for(int i = 0; i<n; i++){
             if(mp[target-nums[i]]){
                 return {mp[target-nums[i]]-1,i};
             }
             mp[nums[i]] = i+1;
         }
         return {-1,-1};
     }
    
    
//     vector<int> twoSum(vector<int>& nums, int target) {
//         int n = nums.size();
//         int sum = 0;
//         int i = 0;
//         int j = n-1;
//         sort(nums.begin(),nums.end());
// //         two index not best method if we have to print the index as due to sorting the indexes would get shattered
//        while(i<j){
//            cout<<" the number is "<<nums[i]<<" i is "<<i<<" j is "<<j<<" number is "<<nums[j]<<endl;
//            if(nums[i]+nums[j]==target){
//                return {i,j};
//            }
//            else if(nums[i]+nums[j]<target){
//                i++;
//            }
//            else if(nums[i]+nums[j]>target){
//                j--;
//            }
//        }
//         return {-1,-1};
//     }
};
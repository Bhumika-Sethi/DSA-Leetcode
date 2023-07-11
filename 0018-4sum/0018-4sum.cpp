class Solution {
    
public:

    
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        int n = nums.size();
        set<vector<int>> ans;
        sort(nums.begin(),nums.end());
        for(int i = 0; i<n; i++){
            for(int j = i+1; j<n; j++){
                int k = j+1;
                int l = n-1;
                while(k<l){
                    long long sum = 0;
                    sum += (long long)(nums[i]);
                    sum += (long long)(nums[j]); 
                    sum += (long long)(nums[k]); 
                    sum += (long long)(nums[l]); 
                    
                    if(sum==target){
                        vector<int> v(4);
                        v[0] = nums[i];
                        v[1] = nums[j];
                        v[2] = nums[k];
                        v[3] = nums[l];
                        ans.insert(v);
                        k++;
                        l--;
                    }
                    else if(sum>target){
                        l--;
                    }
                    else{
                        k++;
                    }
                }
            }
        }
        vector<vector<int>> res(ans.begin(),ans.end());
        return res;
    }

    
//      Time Limit Exceeded
//     vector<vector<int>> fourSum(vector<int>& nums, int target) {
//          int n = nums.size();
//         set<vector<int>> ans;
//         for(int i = 0; i<n; i++){
//             for(int j = i+1; j<n; j++){
//                 map<int,int> mp;
//                 for(int k = j+1; k<n; k++){
//                     long long sum = 0;
//                     sum += (long long)(nums[i]);
//                     sum += (long long)(nums[j]); 
//                     sum += (long long)(nums[k]); 
                     
//                     if(mp[target-sum]){
//                         vector<int> v(4);
//                         v[0] = nums[i];
//                         v[1] = nums[j];
//                         v[2] = nums[k];
//                         v[3] = target-sum;
//                         sort(v.begin(),v.end());
//                         ans.insert(v);
//                     }
//                     mp[nums[k]]++;
//                 }
//             }
//         }
//         vector<vector<int>> res(ans.begin(),ans.end());
//         return res;
//     }
    
//      Time Limit Exceeded
//     vector<vector<int>> fourSum(vector<int>& nums, int target) {
//         int n = nums.size();
//         set<vector<int>> ans;
//         for(int i = 0; i<n; i++){
//             for(int j = i+1; j<n; j++){
//                 for(int k = j+1; k<n; k++){
//                     for(int l = k+1; l<n; l++){
//                         long long sum = 0;
//                         sum += (long long)(nums[i]);
//                         sum += (long long)(nums[j]); 
//                         sum += (long long)(nums[k]); 
//                         sum += (long long)(nums[l]); 

//                         if(sum==target){
//                             vector<int> v(4);
//                             v[0] = nums[i];
//                             v[1] = nums[j];
//                             v[2] = nums[k];
//                             v[3] = nums[l];
//                             sort(v.begin(),v.end());
//                             ans.insert(v);
//                         }
//                     }
//                 }
//             }
//         }
//         vector<vector<int>> res(ans.begin(),ans.end());
//         return res;
//     }
};
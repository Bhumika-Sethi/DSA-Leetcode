class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        // BETTER/BEST APPROACH -> TC : O(N)
        //             -> SC : O(N)
        // In map we'll be storing the element and the index
        // First check if element in map, if yes return both the indexes
        // otherwise add the element into the map with its index
        int n = nums.size();
        unordered_map<int,int> mp;
        vector<int> ans;
        for(int i = 0; i<n; i++){
            int targetEle = target - nums[i];
           if(mp.find(targetEle)!=mp.end()){
            return {i,mp[targetEle]};
           }
           mp[nums[i]] = i; 
        }
        return{-1,-1};
    }
};
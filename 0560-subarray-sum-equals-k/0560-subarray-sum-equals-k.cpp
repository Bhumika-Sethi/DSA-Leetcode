class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        // brute force approach -> TC -> O(N)
        //                      -> SC -> O(N)
        // Prefix sum approach
        // Insert for 0 prefix sum -> cnt as 1 in prefix sum map
        // Do prefix sum -> find remaining
        // If x-k, exist in the map, then thst means k also exist in the array
        // So, cnt += prefixSumMap[remaining]
        // Otherwise prefixSumMap[prefixSum]
        int n = nums.size();
        int cnt = 0;
        int prefixSum = 0;
        unordered_map<int,int> prefixSumMap;
        // Very important
        // If we are inserting the element for the first time -> it would need to search subarray with sum = 0. So, that means it is itself k. That's why it's count should be 1
        prefixSumMap[0] = 1;
        for(int i = 0; i<n; i++){
            prefixSum += nums[i];
            int remaining = prefixSum - k;
            cnt+=prefixSumMap[remaining];
            prefixSumMap[prefixSum]++;
        }
       return cnt;
    }
};
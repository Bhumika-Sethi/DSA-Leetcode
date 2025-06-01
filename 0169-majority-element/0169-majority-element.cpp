class Solution {
public:
    int majorityElement(vector<int>& nums) {
        // Optimal solution - Moore’s Voting Algorithm
        // TC - O(N)
        // SC - O(1)
        int n = nums.size();
        // Take first element and set count to 1
        int ele = nums[0];
        int cnt = 1;
        // now run loop from 1 to n
        for(int i = 1; i<n; i++){
            // If current element is equal to ele, then increment counter
            if(ele==nums[i]){
                cnt++;
            }
            // Otherwise decrement count
            else if(ele!=nums[i]){
                cnt--;
                // And check if count == 0, then change the element and increment count for that ele
                if(cnt==0){
                    ele = nums[i];
                    cnt++;
                }
            }
        }
        // Only that element having majority occurance will survive, rest will get cancel out
        return ele;
    }
};
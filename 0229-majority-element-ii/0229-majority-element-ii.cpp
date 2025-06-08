class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        // Better Approach -> HashMap -> TC - O(N)
        //                            -> SC - O(1)
        vector<int> ans;
        int n = nums.size();
        int max_cnt = n/3 +1;
        // Use canceling logic here as well
        // As there would be 2 elements with cnt>max_cnt
        // NOTE : Initialise ele1 and ele2 to INT_MIN 
        // [0,0,0]
        int cnt1 = 0, ele1 = INT_MIN;
        int cnt2 = 0, ele2 = INT_MIN;
        for(int i = 0; i<n; i++){
            if(cnt1==0 && ele2!=nums[i]){
                ele1 = nums[i];
                cnt1++;
            }
            else if(cnt2==0 && ele1!=nums[i]){
                ele2 = nums[i];
                cnt2++;
            }
            else if(ele1==nums[i]){
                cnt1++;
            }
            else if(ele2==nums[i]){
                cnt2++;
            }
            else{
                cnt1--;
                cnt2--;
            }
        }
        // NOTE: At max there can be 2 majority elements(count>n/3)
        //  - min can be zero
        // Example : [3,2,3]
        // For assurance run a loop for that element
        cnt1 = 0; 
        cnt2 = 0;
        for(int i = 0; i<n; i++){
            if(ele1==nums[i]){
                cnt1++;
            }
            if(ele2==nums[i]){
                cnt2++;
            }
        }
        if(cnt1>n/3){
            ans.push_back(ele1);
        }
        if(cnt2>n/3){
            ans.push_back(ele2);
        }
        return ans;
    }
};
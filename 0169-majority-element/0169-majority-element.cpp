class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int n = nums.size();
        int cnt = 0;
        int maj_ele;
        for(int i = 0; i<n; i++){
            if(cnt==0){
                maj_ele = nums[i];
                cnt++;
            }    
            else if(maj_ele!=nums[i]){
                cnt--;
            }
            else{
                cnt++;
            }
        }
        return maj_ele;
    }
};
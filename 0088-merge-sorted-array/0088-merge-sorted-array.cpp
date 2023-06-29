class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int len = n + m;
        int gap = (len)/2 + len%2;
        nums1.resize(n+m);
        int i = m;
        for(auto it : nums2){
            nums1[i++] = it;
        }
        while(gap>0){
            int left = 0;
            int right = left + gap;
            
            while(right<len){
                if(nums1[left]>nums1[right]){
                    swap(nums1[left],nums1[right]);
                }
                left++;
                right++;
            }
            if(gap==1){
                break;
            }
            gap = gap/2 + gap%2;
        }
    }
};
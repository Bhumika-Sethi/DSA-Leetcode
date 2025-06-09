class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        // So, better approach is by not using any extra space
        // TC -> O(N+M) + O(NlogN) + O(MlogM)
        // SC -> O(1)
        // Intuition - As both the arrays are sorted,so start from the right of 1st array and left of 2nd array
        // All the elements smaller should be present in array 1 and greater in array 2
        // After this, just sort both the arrays and store result in array one as it is having space for both the array elements
        int left = m-1;
        int right = 0;
        // Take care of boundaries and swap till the condition of  nums1[left] > nums2[right]
        // Once we reach nums1[left] >= nums2[right]. Stop
        while(left>=0 && right<n && nums1[left]>nums2[right]){
            swap(nums1[left--],nums2[right++]);
        }
        sort(nums1.begin(),nums1.begin()+m);
        sort(nums2.begin(),nums2.end());
        // To accommodate this, nums1 has a length of m + n. Store store all then n elements present in nums2 array into end of nums1
        for(int i = m; i<nums1.size(); i++){
                nums1[i] = nums2[i-m];
        }
    }
};
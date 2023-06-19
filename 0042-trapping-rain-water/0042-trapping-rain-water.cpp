class Solution {
public:
    int trap(vector<int>& height) {
        int left = 0;
        int n = height.size();
        int right = n-1;
        int lmax = 0;
        int rmax = 0;
        int res = 0;
        
        while(left<=right){
            if(height[left]<=height[right]){
                if(height[left]>lmax){
                    lmax = height[left];
                }
                else{
                    res += lmax - height[left];
                }
                left++;
            }
            else{
                if(rmax<height[right]){
                    rmax = height[right];
                }
                else{
                    res += rmax - height[right];
                }
                right--;
            }
        }
        return res;
    }
};
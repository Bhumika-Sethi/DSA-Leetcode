class Solution {
public:
    int trap(vector<int>& height) {
      int n = height.size();
      int waterTrapped = 0;
      int leftMax = 0;
      int rightMax = 0;
      vector<int> prefixMax(n,0), suffixMax(n,0);
      for(int i = 0; i<n; i++){
        leftMax = max(leftMax,height[i]);
        rightMax = max(rightMax,height[n-i-1]);
        prefixMax[i] = max(leftMax,height[i]);
        suffixMax[n-i-1] = max(rightMax,height[n-i-1]);
      } 

      for(int i = 0; i<n; i++){
        waterTrapped += abs(min(prefixMax[i],suffixMax[i])-height[i]);
      }
      return waterTrapped;
    }
};
class Solution {
public:
    int maxProduct(vector<int>& nums) {
        // TC - O(N)
        // SC - O(N)
        // Optimal solution
        int n = nums.size();
        int maxi = INT_MIN;
        int prefixProd = 1;
        int suffixProd = 1;
        // If prefixProd == 0, we would consider a fresh start and change prefix to 1
        // If suffixProd ==0, we would consider a fresh start and change prefix to 1
        for(int i = 0; i<n; i++){
            if(prefixProd==0){
                prefixProd = 1;
            }
            if(suffixProd==0){
                suffixProd = 1;
            }
            prefixProd *= nums[i];
            suffixProd *= nums[n-i-1];
            maxi = max(maxi,max(suffixProd,prefixProd));
        }
        return maxi;
    }
};
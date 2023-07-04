//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
    
    int mul(int i, int j, int* arr, vector<vector<int>>& dp){
        // single 1D matrix - so no multipication possible 
        if(i==j){
            return 0;
        }
        
        if(dp[i][j]!=-1){
            return dp[i][j];
        }
        int mini = 1e9;
        
        
        for(int k = i; k<j; k++){
            int steps = arr[i-1]*arr[k]*arr[j] + mul(i,k,arr,dp) + mul(k+1,j,arr,dp);
            mini = min(mini,steps);
        }
        
        return dp[i][j] = mini;
    }
    
public:
    int matrixMultiplication(int N, int arr[])
    {
        // consider entire block
        // why not i = 0?
        // Because we are doing multipication operation of i-1
        // if i is passed as 0 then we would be accessing negative index
        vector<vector<int>> dp(N,vector<int>(N,-1));
        return mul(1,N-1,arr,dp);
        // code here
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int N;
        cin>>N;
        int arr[N];
        for(int i = 0;i < N;i++)
            cin>>arr[i];
        
        Solution ob;
        cout<<ob.matrixMultiplication(N, arr)<<endl;
    }
    return 0;
}
// } Driver Code Ends
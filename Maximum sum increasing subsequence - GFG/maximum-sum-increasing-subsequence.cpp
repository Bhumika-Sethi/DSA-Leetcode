//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{
		
    int lis(int i, int prev, int* arr, int n,vector<vector<int>> &dp){
        if(i==n){
            return 0;
        }
        if( dp[i][prev+1]!=-1){
            return  dp[i][prev+1];
        }
        int notTake = lis(i+1,prev,arr,n,dp);
        int take = -1e9;
        if(prev==-1 || arr[i]>arr[prev]){
            take =  arr[i] + lis(i+1,i,arr,n,dp);
        }
        return dp[i][prev+1] = max(take,notTake);
    }
	public:
	int maxSumIS(int arr[], int n)  
	{  
	    vector<vector<int>> dp(n+1,vector<int>(n+1,0));
	    for(int i=n-1; i>=0; i--){
	        for(int prev = i-1; prev>=-1; prev--){
	            int notTake = dp[i+1][prev+1];
                int take = -1e9;
                if(prev==-1 || arr[i]>arr[prev]){
                    take =  arr[i] + dp[i+1][i+1];
                }
                dp[i][prev+1] = max(take,notTake);
	        }
	    }
	    return dp[0][0];
	    // Your code goes here
	}  
};

//{ Driver Code Starts.
int main() 
{
   	
   
   	int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;

        int a[n];

        for(int i = 0; i < n; i++)
        	cin >> a[i];

      

	    Solution ob;
	    cout << ob.maxSumIS(a, n) << "\n";
	     
    }
    return 0;
}


// } Driver Code Ends
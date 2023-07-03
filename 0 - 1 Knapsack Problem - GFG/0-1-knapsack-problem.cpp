//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution
{
    public:
    //Function to return max value that can be put in knapsack of capacity W.
    int rec(int i, int W, int wt[], int val[], int n, vector<vector<int>>& dp){
        if(i==n){
            return 0;
        }
        if(dp[i][W]!=-1){
            return dp[i][W];
        }
        int notTake = rec(i+1,W,wt,val,n,dp);
        int take = 0;
        if(wt[i]<=W){
            take = val[i] + rec(i+1,W-wt[i],wt,val,n,dp);
        }
        return dp[i][W] = max(take,notTake);
    }
    int knapSack(int W, int wt[], int val[], int n) 
    { 
        vector<int> curr(W+1,0), next(W+1,0);
        for(int i = n-1; i>=0; i--){
            for(int j = 0; j<=W; j++){
                int notTake = next[j];
                int take = 0;
                if(wt[i]<=j){
                    take = val[i] + next[j-wt[i]];
                }
                curr[j] = max(take,notTake);
            }
            next = curr;
        }
        return curr[W];
       // Your code here
    }
};

//{ Driver Code Starts.

int main()
 {
    //taking total testcases
    int t;
    cin>>t;
    while(t--)
    {
        //reading number of elements and weight
        int n, w;
        cin>>n>>w;
        
        int val[n];
        int wt[n];
        
        //inserting the values
        for(int i=0;i<n;i++)
            cin>>val[i];
        
        //inserting the weights
        for(int i=0;i<n;i++)
            cin>>wt[i];
        Solution ob;
        //calling method knapSack()
        cout<<ob.knapSack(w, wt, val, n)<<endl;
        
    }
	return 0;
}
// } Driver Code Ends
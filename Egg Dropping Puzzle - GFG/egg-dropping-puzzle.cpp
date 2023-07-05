//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
    
    int minSteps(int floor, int eggs, vector<vector<int>>& dp){
        if(eggs==1){
            return floor;
        }
        if(floor==0 || floor==1){
            return floor;
        }
        if(dp[floor][eggs]!=-1){
            return dp[floor][eggs];
        }
        int mini = 1e9;
        for(int k = 1; k<=floor; k++){
         int temp = 1 + max(minSteps(k-1,eggs-1,dp), minSteps(floor-k,eggs,dp));
         mini = min(mini,temp);
        }
        
        return dp[floor][eggs] = mini;
    }
    
    public:
    //Function to find minimum number of attempts needed in 
    //order to find the critical floor.
    int eggDrop(int n, int k) 
    {
        vector<vector<int>> dp(k+1,vector<int>(n+1,-1));
       return minSteps(k,n,dp);
        // your code here
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
        //taking eggs and floors count
        int n, k;
        cin>>n>>k;
        Solution ob;
        //calling function eggDrop()
        cout<<ob.eggDrop(n, k)<<endl;
    }
    return 0;
}

// } Driver Code Ends
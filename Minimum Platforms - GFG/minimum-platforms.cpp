//{ Driver Code Starts
// Program to find minimum number of platforms
// required on a railway station
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution{
    public:
    //Function to find the minimum number of platforms required at the
    //railway station such that no train waits.
    int findPlatform(int arr[], int dep[], int n)
    {
        sort(dep,dep+n);
        sort(arr,arr+n);
        int cnt = 1;
        int maxi = 0;
        int end_time = dep[0];
        int i = 1;
        int j = 0;
        while(i<n){
            if(dep[j]>=arr[i]){
                i++;
                cnt++;
            }
            else if(dep[j]<arr[i]){
                j++;
                cnt--;
            }
            maxi = max(maxi,cnt);
        }
        return maxi;
    	// Your code here
    }
};


//{ Driver Code Starts.
// Driver code
int main()
{
    int t;
    cin>>t;
    while(t--) 
    {
        int n;
        cin>>n;
        int arr[n];
        int dep[n];
        for(int i=0;i<n;i++)
            cin>>arr[i];
        for(int j=0;j<n;j++){
            cin>>dep[j];
        }
        Solution ob;
        cout <<ob.findPlatform(arr, dep, n)<<endl;
    } 
   return 0;
}
// } Driver Code Ends
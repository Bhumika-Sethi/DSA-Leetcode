//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

struct Item{
    int value;
    int weight;
};


// } Driver Code Ends
//class implemented
/*
struct Item{
    int value;
    int weight;
};
*/


class Solution
{
    bool static cmp(Item a, Item b){
        return double(a.value)/double(a.weight) > double(b.value)/double(b.weight);
    }
    
    public:
    //Function to get the maximum total value in the knapsack.
    double fractionalKnapsack(int W, Item arr[], int n)
    {
        sort(arr,arr+n,cmp);
        int current_weight = 0;
        double current_val = 0;
        for(int i = 0; i<n; i++){
            if(current_weight+arr[i].weight<=W){
                current_weight += arr[i].weight;
                current_val += arr[i].value;
            }
            else{
                double value = ((double)arr[i].value/(double)arr[i].weight)*(double)(W-current_weight);
                current_val += value;
                break;
            }
        }
        return current_val;
        // Your code here
    }
        
};


//{ Driver Code Starts.
int main()
{
	int t;
	//taking testcases
	cin>>t;
	cout<<setprecision(2)<<fixed;
	while(t--){
	    //size of array and weight
		int n, W;
		cin>>n>>W;
		
		Item arr[n];
		//value and weight of each item
		for(int i=0;i<n;i++){
			cin>>arr[i].value>>arr[i].weight;
		}
		
		//function call
		Solution ob;
		cout<<ob.fractionalKnapsack(W, arr, n)<<endl;
	}
    return 0;
}
// } Driver Code Ends
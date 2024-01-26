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
    public:
    static bool cmp(Item a, Item b){
        return (a.value/(a.weight*1.0)) > b.value/(b.weight*1.0);
    }
    double fractionalKnapsack(int w, Item arr[], int n)
    {
      sort(arr,arr+n,cmp);
       double sum=0.0;
       for(int i=0; i<n;i++){
           if(w-arr[i].weight>=0){
               sum=sum+arr[i].value;
               w=w-arr[i].weight;
               
           }else{
               sum=sum+(arr[i].value/(arr[i].weight*1.0))*w;
               break;
           }
       }
       return sum;
    }
        
};


//{ Driver Code Starts.
int main()
{
	int t;
	//taking testcases
	cin>>t;
	cout<<setprecision(6)<<fixed;
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
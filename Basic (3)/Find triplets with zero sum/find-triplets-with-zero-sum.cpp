//{ Driver Code Starts
#include<bits/stdc++.h>
#include<stdlib.h>
#include<iostream>
using namespace std;

// } Driver Code Ends
/* You are required to complete the function below
*  arr[]: input array
*  n: size of array
*/

void bubbleSort(int arr[], int n) {
	int count = 1;
	while (count < n) {
		for (int i = 0; i < n - count; i++) {
			if (arr[i] > arr[i + 1])
				swap(arr[i], arr[i + 1]);
		}
		count++;
	}
}

class Solution{
  public:
    //Function to find triplets with zero sum.
    bool findTriplets(int arr[], int n)
    { 
        bubbleSort(arr,n);
        int j,k;
        int triplet;
        for (int i = 0; i < n - 1; i++) {
            j = i + 1;
            k = n - 1; 
            while (j < k) {
                triplet = arr[i] + arr[j] + arr[k];
                if (triplet == 0)
                    return true;
                else if (triplet > 0)
                    k--;
                else if (triplet < 0)
                    j++;
            }
        }
        return false;
    }
};

//{ Driver Code Starts.
int main()
{
    int t;
	cin>>t;
	while(t--){
    	int n;
    	cin>>n;
    	int arr[n]={0};
    	for(int i=0;i<n;i++)
    		cin>>arr[i];
    	Solution obj;
        if(obj.findTriplets(arr, n))
            cout<<"1"<<endl;
        else 
            cout<<"0"<<endl;
	}
    return 0;
}
// } Driver Code Ends
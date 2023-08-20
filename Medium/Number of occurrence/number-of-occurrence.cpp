//{ Driver Code Starts
#include<bits/stdc++.h>

using namespace std;


// } Driver Code Ends
//User function template for C++
class Solution{
public:	
	/* if x is present in arr[] then returns the count
		of occurrences of x, otherwise returns 0. */
	int count(int arr[], int n, int x) {
	    // code here
	    /*------------------------------------------------------------------------------------------
	    if(x>=arr[0] && x<=arr[n-1]){                  //0.2 s
	        for(int i=0;i<n;i++){
	            if(arr[i]==x){
	                int count = 0;
	                while(arr[i]==x){
	                    count++;
	                    i++;
	                }
	                return count;
	            }
	        }
	    }
	    return 0;
	    ------------------------------------------------------------------------------------------*/
	   if(x>=arr[0] && x<=arr[n-1]){                   //0.19 s
	       int i=0,j=n-1;
	       while(i<=j){
	           if(arr[i]!=x) i++;
	           if(arr[j]!=x) j--;
	           if(arr[i]==arr[j] && arr[i]==x) return j-i+1;
	       }
	   }
	   return 0;
	}
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, x;
        cin >> n >> x;
        int arr[n];
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
        }
        Solution ob;
        auto ans = ob.count(arr, n, x);
        cout << ans << "\n";
    }
    return 0;
}

// } Driver Code Ends

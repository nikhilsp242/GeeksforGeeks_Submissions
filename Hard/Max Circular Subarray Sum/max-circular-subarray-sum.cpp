//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution{
    public:
    // arr: input array
    // num: size of array
    //Function to find maximum circular subarray sum.
    int circularSubarraySum(int arr[], int num){
        
        // your code here
        int fullSum = 0;
	    int sum1 = 0, wrapSum = 0;
	    int sum2 = 0, nonWrapSum = 0;
	    int maxElement = INT_MIN; // To handle the case of all negative elements
        for(int i = 0;i<num;i++){
            fullSum += arr[i];
            maxElement = max(maxElement, arr[i]);
            sum1 -= arr[i];
            sum1 > 0 ? wrapSum = max(wrapSum,sum1) : sum1 = 0;
		    sum2 += arr[i];
            sum2 > 0 ? nonWrapSum = max(nonWrapSum,sum2) : sum2 = 0;
        }
        if (nonWrapSum<=0) return maxElement;
        
        wrapSum += fullSum;
        return max(wrapSum, nonWrapSum);
    }
};

//{ Driver Code Starts.

int main()
 {
	int T;
	
	//testcases
	cin>> T;
	
	while (T--)
	{
	    int num;
	    
	    //size of array
	    cin>>num;
	    int arr[num];
	    
	    //inserting elements
	    for(int i = 0; i<num; i++)
	        cin>>arr[i];
	        
	    Solution ob;
	    //calling function
	    cout << ob.circularSubarraySum(arr, num) << endl;
	    
	}
	
	return 0;
}
// } Driver Code Ends
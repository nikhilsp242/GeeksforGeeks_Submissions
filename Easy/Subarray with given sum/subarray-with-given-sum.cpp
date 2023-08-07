//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution
{
    public:
    //Function to find a continuous sub-array which adds up to a given number.
    vector<int> subarraySum(vector<int>arr, int n, long long s)
    {
        // Your code here
        vector<int> ind;
        ind.push_back(-1);
        if(s==0) return ind;
        ind.pop_back();
        long long sum = 0;
        int start = 0;
        
        for(int end=0; end<n;end++){
            sum += arr[end];
            
            while(sum>s){
                sum -= arr[start++];
            }
            
            if(sum==s){
                ind.push_back(start+1);
                ind.push_back(end+1);
                return ind;
            }
        }
        ind.push_back(-1);
        return ind;
    }
};

//{ Driver Code Starts.

int main()
 {
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        long long s;
        cin>>n>>s;
        vector<int>arr(n);
        // int arr[n];
        const int mx = 1e9;
        for(int i=0;i<n;i++)
        {
            cin>>arr[i];
        }
        Solution ob;
        vector<int>res;
        res = ob.subarraySum(arr, n, s);
        
        for(int i = 0;i<res.size();i++)
            cout<<res[i]<<" ";
        cout<<endl;
        
    }
	return 0;
}
// } Driver Code Ends
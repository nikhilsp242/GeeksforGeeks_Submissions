//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution
{
    int MOD = 1000000007;
    public:
    //Function to count the number of ways in which frog can reach the top.
    long long countWays(int n)
    {
        // your code here
        if(n<=2) return n;
            
        long long first = 1;
        long long second = 2;
        long long third = 4;
        
        for(int i=4;i<=n;i++){
            long long fourth = (third + second + first) % MOD;
            first = second ;
            second = third ;
            third = fourth ;
        }
        return third % MOD;
    }
};


//{ Driver Code Starts.
int main()
{
    //taking testcases
	int t;
	cin >> t;
	
	while(t--)
	{
	    //taking number of steps in stair
		int n;
		cin>>n;
		Solution ob;
		//calling function countWays()
		cout << ob.countWays(n) << endl;
	}
    
    return 0;
    
}

// } Driver Code Ends
//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
public:
    string findLargest(int N, int S){
        // code here
        if(S>9*N) return "-1";
        
        if(S==0 && N>1) return "-1";
        
        string largestNumber(N,'0');
        
        for(int i=0;i<N && S>0;i++){
            int digit = min(S,9);
            largestNumber[i] = '0' + digit;
            S -= digit;
        }
        
        return largestNumber ;
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int N, S;
        cin>>N>>S;
        
        Solution ob;
        cout<<ob.findLargest(N, S)<<"\n";
    }
    return 0;
}
// } Driver Code Ends
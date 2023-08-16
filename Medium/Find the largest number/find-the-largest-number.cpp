//{ Driver Code Starts
#include<bits/stdc++.h> 
using namespace std;

// } Driver Code Ends


class Solution{
public:
    
    int find(int N){
        // code here
        string num1 = to_string(N);
        string num2 = to_string(N);
        sort(num2.begin(),num2.end());
        if(num1 == num2)
            return N;
        while(N>0){
            N--;
            num1 = to_string(N);
            num2 = to_string(N);
            sort(num2.begin(),num2.end());
            if(num1 == num2)
                return N;
        }
    }
};


//{ Driver Code Starts.
int main() 
{ 
    int t;
    cin>>t;
    while(t--)
    {
        int N;
        cin>>N;
        Solution ob;
        cout << ob.find(N) << endl;
    }
    return 0; 
}
// } Driver Code Ends
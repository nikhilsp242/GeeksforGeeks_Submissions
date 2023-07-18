//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution{
    public:
    
    //Complete this function
    void printNos(int N)
    {
        //Your code here
        printRec(N,1);
    }
    
    void printRec(int N,int i){     //recursive function to print without loop
        if(i<=N){
            cout << i++ << " ";
            printRec(N,i);
        }
    }
};

//{ Driver Code Starts.
/* Driver program to test printNos */
int main()
{
    int T;
    
    //taking testcases
    cin>>T;
    
    while(T--)
    {
        int N;
        
        //input N
        cin>>N;
        Solution ob;
        //calling printNos() function
        ob.printNos(N);
        cout << "\n";
    }
    return 0;
}

// } Driver Code Ends
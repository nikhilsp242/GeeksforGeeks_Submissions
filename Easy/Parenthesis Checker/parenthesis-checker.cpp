//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution
{
    public:
    //Function to check if brackets are balanced or not.
    bool ispar(string x)
    {
        // Your code here
        stack<char> par;
        for(int i=0;i<x.size();i++){
            if(x[i] == '{' || x[i] == '(' || x[i] == '[') par.push(x[i]);
            else{
                if(par.empty()) return false;
                
                char top = par.top();
                par.pop();
                
                if(x[i] == '}' && top != '{' ) return false;
                if(x[i] == ')' && top != '(' ) return false;
                if(x[i] == ']' && top != '[' ) return false;
            }
        }
        return par.empty();
    }

};

//{ Driver Code Starts.

int main()
{
   int t;
   string a;
   cin>>t;
   while(t--)
   {
       cin>>a;
       Solution obj;
       if(obj.ispar(a))
        cout<<"balanced"<<endl;
       else
        cout<<"not balanced"<<endl;
   }
}
// } Driver Code Ends
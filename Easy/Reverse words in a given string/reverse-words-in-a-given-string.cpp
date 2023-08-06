//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution
{
    public:
    //Function to reverse words in a given string.
    string reverseWords(string S) 
    { 
        // code here
        stack<string> st;
        string word;
        for(int i=0;i<S.size();i++){
            if(S[i]!='.'){
                word += S[i];
            }
            else{
                st.push(word);
                word.clear();
            }
        }
        if(!word.empty()) st.push(word);
        string rev;
        while(!st.empty()){
            rev += st.top() + ".";
            st.pop();
        }
        return rev.substr(0,rev.size()-1);
        
    } 
};

//{ Driver Code Starts.
int main() 
{
    int t;
    cin >> t;
    while (t--) 
    {
        string s;
        cin >> s;
        Solution obj;
        cout<<obj.reverseWords(s)<<endl;
    }
}
// } Driver Code Ends
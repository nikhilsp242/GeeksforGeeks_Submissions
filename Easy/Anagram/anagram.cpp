//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution
{
    public:
    //Function is to check whether two strings are anagram of each other or not.
    bool isAnagram(string a, string b){
        
        // Your code here
        if(a.size()!=b.size()) return false;
        unordered_map<char,int> am,bm;
        for(int i = 0; i<a.size();i++){
            am[a[i]]++;
        }
        for(int i = 0; i<b.size();i++){
            bm[b[i]]++;
        }
        for(const auto& pair : am){
            char c = pair.first;
            if(am[c]!=bm[c]) return false;
        }
        return true;
    }

};

//{ Driver Code Starts.

int main() {
    
    int t;

    cin >> t;

    while(t--){
        string c, d;

        cin >> c >> d;
        Solution obj;
        if(obj.isAnagram(c, d)) cout << "YES" << endl;
        else cout << "NO" << endl;
    }

}

// } Driver Code Ends
//{ Driver Code Starts
// Initial template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function template for C++

class Solution {
    private:
        unordered_map<char, int> romanToInteger = {
            {'I', 1},
            {'V', 5},
            {'X', 10},
            {'L', 50},
            {'C', 100},
            {'D', 500},
            {'M', 1000}
        };
    
    public:
    int romanToDecimal(string &str) {
        int num = 0;
        
        int n = str.size();
        for(int i=0;i<n;i++){
            if(i < n-1 && romanToInteger[str[i]] < romanToInteger[str[i + 1]]){
                num -= romanToInteger[str[i]];
            }
            else {
                num += romanToInteger[str[i]];
            }
        }
        
        return num;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        string s;
        cin >> s;
        Solution ob;
        cout << ob.romanToDecimal(s) << endl;
    }
}
// } Driver Code Ends
//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{
  public:
    vector<int> duplicates(int arr[], int n) {
        // code here
        vector<int> dup;
        int maxnum = arr[0];
        for (int i = 1 ; i < n ; i++){
            maxnum = max(maxnum,arr[i]);
        }
        vector<int> count(maxnum+1,0);
        for (int i = 0 ; i < n ; i++){
            count[arr[i]] += 1;
        }
        for(int i = 0;i<count.size();i++){
            if(count[i]>1) dup.push_back(i);
        }
        if(dup.empty()) dup.push_back(-1);
        return dup;
    }
};


//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t-- > 0) {
        int n;
        cin >> n;
        int a[n];
        for (int i = 0; i < n; i++) cin >> a[i];
        Solution obj;
        vector<int> ans = obj.duplicates(a, n);
        for (int i : ans) cout << i << ' ';
        cout << endl;
    }
    return 0;
}

// } Driver Code Ends
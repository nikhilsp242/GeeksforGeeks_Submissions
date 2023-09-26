//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function template for C++

class Solution{
    public:
    vector<vector<int>> fourSum(vector<int> &A, int K) {
        // Your code goes here
        vector<vector<int>> result;
        int N = A.size();
    
        if (N < 4) {
            return result; 
        }
    
        sort(A.begin(), A.end());
    
        for (int i = 0; i < N - 3; ++i) {
            if (i > 0 && A[i] == A[i - 1]) {
                continue;
            }
    
            for (int j = i + 1; j < N - 2; ++j) {
                if (j > i + 1 && A[j] == A[j - 1]) {
                    continue;
                }
    
                int left = j + 1;
                int right = N - 1;
    
                while (left < right) {
                    int sum = A[i] + A[j] + A[left] + A[right];
    
                    if (sum == K) {
                        result.push_back({A[i], A[j], A[left], A[right]});
    
                        
                        while (left < right && A[left] == A[left + 1]) {
                            left++;
                        }
                        while (left < right && A[right] == A[right - 1]) {
                            right--;
                        }
    
                        left++;
                        right--;
                    } 
                    else if (sum < K) left++;
                    else right--;
        
                }
            }
        }
    
        return result;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, k, i;
        cin >> n >> k;
        vector<int> a(n);
        for (i = 0; i < n; i++) {
            cin >> a[i];
        }
        Solution ob;
        vector<vector<int> > ans = ob.fourSum(a, k);
        for (auto &v : ans) {
            for (int &u : v) {
                cout << u << " ";
            }
            cout << "$";
        }
        if (ans.empty()) {
            cout << -1;
        }
        cout << "\n";
    }
    return 0;
}
// } Driver Code Ends
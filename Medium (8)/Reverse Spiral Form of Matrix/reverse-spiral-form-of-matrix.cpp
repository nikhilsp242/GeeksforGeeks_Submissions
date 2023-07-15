//{ Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++
#include<algorithm>

class Solution {
  public:
    vector<int> reverseSpiral(int R, int C, vector<vector<int>>&a)  {
        // code here
        vector<int> revSpiral;
        int startRow = 0, startColumn = 0;
        int endRow = R-1, endColumn = C-1;
        while(startRow <= endRow && startColumn <= endColumn){
            for(int col = startColumn;col <= endColumn;col++){
                revSpiral.push_back(a[startRow][col]);
            }
            startRow++;
            
            for(int row = startRow;row <= endRow; row++){
                revSpiral.push_back(a[row][endColumn]);
            }
            endColumn--;
            // Check if there's still a valid row to traverse
            if (startRow <= endRow) {
                // Traverse bottom row
                for (int col = endColumn; col >= startColumn; col--) {
                    revSpiral.push_back(a[endRow][col]);
                }
                endRow--;
            }
            // Check if there's still a valid column to traverse
            if (startColumn <= endColumn) {
                // Traverse left column
                for (int row = endRow; row >= startRow; row--) {
                    revSpiral.push_back(a[row][startColumn]);
                }
                startColumn++;
            }
        }
        reverse(revSpiral.begin(),revSpiral.end());    
        return revSpiral;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int R, C;
        cin>>R>>C;
        vector<vector<int>> a(R, vector<int>(C, 0));
        for(int i = 0;i < R*C;i++)
            cin>>a[i/C][i%C];
        Solution ob;
        vector<int>ans=ob.reverseSpiral(R,C,a);
        for(int i=0;i<ans.size();i++)cout<<ans[i]<<" ";
            cout<<endl;
    }
    return 0;
}

// } Driver Code Ends
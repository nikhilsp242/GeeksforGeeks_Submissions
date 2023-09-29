//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    double waterOverflow(int poured, int row, int glass) {
        vector<vector<double>> triangle;
        triangle.push_back({poured*1.0});
        
        for(int i=0;i<=row;i++){
            vector<double> newRow(i+2,0.0);
            
            for(int j=0;j<=i;j++){
                if(triangle[i][j] > 1){
                    double half = (triangle[i][j] - 1) / 2.0;
                    newRow[j] += half;
                    newRow[j+1] += half;
                    triangle[i][j] = 1;
                }
            }
            
            triangle.push_back(newRow);
        }
        
        return triangle[row-1][glass-1];
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int K,R,C;
        
        cin>>K>>R>>C;

        Solution ob;
        cout << fixed << setprecision(6)<< ob.waterOverflow(K,R,C) << endl;
    }
    return 0;
}
// } Driver Code Ends
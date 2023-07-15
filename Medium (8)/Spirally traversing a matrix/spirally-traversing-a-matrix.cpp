//{ Driver Code Starts
#include <bits/stdc++.h> 
using namespace std; 

// } Driver Code Ends
class Solution
{   
    public: 
    //Function to return a list of integers denoting spiral traversal of matrix.
    vector<int> spirallyTraverse(vector<vector<int> > matrix, int r, int c) 
    {
        // code here
        vector<int> spiral;
        int startRow = 0, startColumn = 0;
        int endRow = r-1, endColumn = c-1;
        while(startRow <= endRow && startColumn <= endColumn){
            for(int col = startColumn;col <= endColumn;col++){
                spiral.push_back(matrix[startRow][col]);
            }
            startRow++;
            
            for(int row = startRow;row <= endRow; row++){
                spiral.push_back(matrix[row][endColumn]);
            }
            endColumn--;
            // Check if there's still a valid row to traverse
            if (startRow <= endRow) {
                // Traverse bottom row
                for (int col = endColumn; col >= startColumn; col--) {
                    spiral.push_back(matrix[endRow][col]);
                }
                endRow--;
            }
            // Check if there's still a valid column to traverse
            if (startColumn <= endColumn) {
                // Traverse left column
                for (int row = endRow; row >= startRow; row--) {
                    spiral.push_back(matrix[row][startColumn]);
                }
                startColumn++;
            }
        }
        return spiral;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin>>t;
    
    while(t--) 
    {
        int r,c;
        cin>>r>>c;
        vector<vector<int> > matrix(r); 

        for(int i=0; i<r; i++)
        {
            matrix[i].assign(c, 0);
            for( int j=0; j<c; j++)
            {
                cin>>matrix[i][j];
            }
        }

        Solution ob;
        vector<int> result = ob.spirallyTraverse(matrix, r, c);
        for (int i = 0; i < result.size(); ++i)
                cout<<result[i]<<" ";
        cout<<endl;
    }
    return 0;
}
// } Driver Code Ends
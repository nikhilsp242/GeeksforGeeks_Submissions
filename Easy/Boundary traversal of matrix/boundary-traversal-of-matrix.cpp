//{ Driver Code Starts
#include <bits/stdc++.h> 
using namespace std; 

// } Driver Code Ends

class Solution
{   
    public:
    //Function to return list of integers that form the boundary 
    //traversal of the matrix in a clockwise manner.
    vector<int> boundaryTraversal(vector<vector<int> > matrix, int n, int m) 
    {
        // code here
        vector<int> boundary;
        
        int i=0,j=0;
        
        //left to right
        while(j<m){
            boundary.push_back(matrix[i][j++]);
        }
        j--;
        i++;
        
        if(i>=n) return boundary;
        
        //up to down
        while(i<n){
            boundary.push_back(matrix[i++][j]);
        }
        i--;
        j--;
        
        if(j<0) return boundary;
        //right to left
        while(j>=0){
            boundary.push_back(matrix[i][j--]);
        }
        j++;
        i--;
        
        if(i<=0) return boundary;
        //down to up
        while(i>0){
            boundary.push_back(matrix[i--][j]);
        }
        
        return boundary;
    }
};


//{ Driver Code Starts.
int main() {
    int t;
    cin>>t;
    
    while(t--) 
    {
        int n,m;
        cin>>n>>m;
        vector<vector<int> > matrix(n); 

        for(int i=0; i<n; i++)
        {
            matrix[i].assign(m, 0);
            for( int j=0; j<m; j++)
            {
                cin>>matrix[i][j];
            }
        }

        Solution ob;
        vector<int> result = ob.boundaryTraversal(matrix, n, m);
        for (int i = 0; i < result.size(); ++i)
                cout<<result[i]<<" ";
        cout<<endl;
    }
    return 0;
}
// } Driver Code Ends
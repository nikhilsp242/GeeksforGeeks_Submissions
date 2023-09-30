//{ Driver Code Starts
#include <bits/stdc++.h> 
using namespace std; 

// } Driver Code Ends


class Solution
{   
    public:
    void booleanMatrix(vector<vector<int> > &matrix)
    {
        // code here
        int rows = matrix.size();
        int cols = matrix[0].size();
        
        unordered_set<int> modifyRows;
        unordered_set<int> modifyCols;
        
        for(int i=0;i<rows;i++){
            for(int j=0;j<cols;j++){
                if(matrix[i][j] == 1){
                    if(!modifyRows.count(i)) modifyRows.insert(i);
                    if(!modifyCols.count(j)) modifyCols.insert(j);
                }
            }
        }
        
        for(int i : modifyRows){
            for(int j=0;j<cols;j++){
                matrix[i][j] = 1;
            }
        }
        
        for(int j : modifyCols){
            for(int i=0;i<rows;i++){
                matrix[i][j] = 1;
            }
        }
    }
};


//{ Driver Code Starts.
int main() {
    int t;
    cin>>t;
    while(t--) 
    {
        int row, col;
        cin>> row>> col;
        vector<vector<int> > matrix(row); 
        for(int i=0; i<row; i++)
        {
            matrix[i].assign(col, 0);
            for( int j=0; j<col; j++)
            {
                cin>>matrix[i][j];
            }
        }
        
        Solution ob;
        ob.booleanMatrix(matrix);


        for (int i = 0; i < row; ++i)
        {
            for (int j = 0; j < col; ++j)
            {
                cout<<matrix[i][j]<<" ";
            }
            cout<<endl;
        }
    }
    return 0;
}



// } Driver Code Ends
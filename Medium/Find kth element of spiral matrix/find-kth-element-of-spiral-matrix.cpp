//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;
#define MAX 1000

// } Driver Code Ends   
class Solution
{
    public:
    /*You are required to complete this method*/
    int findK(int a[MAX][MAX],int n,int m,int k)
    {
 		// Your code goes here.
 		int eleNum = 0;
        if(k == 0)
            return a[0][0];
        int startRow = 0, startColumn = 0;
        int endRow = n-1, endColumn = m-1;
        while(startRow <= endRow && startColumn <= endColumn){
            for(int col = startColumn;col <= endColumn;col++){
                eleNum++;
                if(eleNum == k)
                    return a[startRow][col];
            }
            startRow++;
            for(int row = startRow;row <= endRow; row++){
                eleNum++;
                if(eleNum == k)
                    return a[row][endColumn];
            }
            endColumn--;
            for(int col = endColumn;col >= startColumn; col--){
                eleNum++;
                if(eleNum == k)
                    return a[endRow][col];
            }
            endRow--;
            for(int row = endRow;row >= startRow;row--){
                eleNum++;
                if(eleNum == k)
                    return a[row][startColumn];
            }
            startColumn++;
        }
        return -1;
    }
};





//{ Driver Code Starts.
int main()
{
    int T;
    cin>>T;
  
    while(T--)
    {
        int n,m;
        int k=0;
        //cin>>k;
        cin>>n>>m>>k;
        int a[MAX][MAX];
        
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                cin>>a[i][j];
            }
        }
        Solution ob;
        cout<<ob.findK(a,n,m,k)<<endl;
        
       
    }
}
// } Driver Code Ends
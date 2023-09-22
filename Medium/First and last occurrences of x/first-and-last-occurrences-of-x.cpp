//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
    public:
    vector<int> find(int arr[], int n , int x )
    {
        // code here
        int first = INT_MAX , last = INT_MIN;
        // bool found = false;
        
        // for(int i=0;i<n;i++){              //0.59
        //     if(arr[i] == x){
        //         found = true;
        //         first = min(first,i);
        //         last = max(last,i);
        //     }
        // }
        
        // int i=0;
        // while(i<n && arr[i]<=x){            //0.45
        //     if(arr[i]==x){
        //         found = true;
        //         first = min(first,i);
        //         last = max(last,i);
        //     }
        //     i++;
        // }
        // if(!found) return {-1,-1};
        // return {first,last};
        
        int left = 0, right = n-1;   
        
        while(left<=right){
            int mid = left + (right - left) / 2;    //0.43
            
            if(arr[mid] == x){
                first = min(first,mid);
                last = max(last,mid);
                
                int i=mid-1,j=mid+1;
                while(i>=0 && arr[i]==x) first = min(first,i--);
                while(j<n && arr[j]==x) last = max(last,j++);
                return {first,last};
            }
            else if(arr[mid]<x) left = mid+1;
            else right = mid-1;
        }
        return {-1,-1};
    }
};

//{ Driver Code Starts.

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n,x;
        cin>>n>>x;
        int arr[n],i;
        for(i=0;i<n;i++)
        cin>>arr[i];
        vector<int> ans;
        Solution ob;
        ans=ob.find(arr,n,x);
        cout<<ans[0]<<" "<<ans[1]<<endl;
    }
    return 0;
}



// } Driver Code Ends
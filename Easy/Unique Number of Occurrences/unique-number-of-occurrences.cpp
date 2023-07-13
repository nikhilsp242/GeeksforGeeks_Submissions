//{ Driver Code Starts
//Initial Template for C++
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++
#include<vector>
#include<algorithm>
#include<set>

class Solution
{
    public:
    bool isFrequencyUnique(int n, int arr[])
    {
        vector<int> sortArr(arr,arr+n);
        sort(sortArr.begin(),sortArr.end());
        vector<int> freqArr;
        int prev = sortArr[0];
        int freq = 1;
        for(int i = 1;i < n ; i++){
            if(sortArr[i] == prev)
                freq++;
            else{
                prev = sortArr[i];
                freqArr.push_back(freq);
                freq = 1;
            }
        }
        freqArr.push_back(freq);
        /*sort(freqArr.begin(),freqArr.end());
        for(int i = 1;i<freqArr.size();i++){
            if(freqArr[i] == freqArr[i-1])
                return false;
        }
        return true;*/
        set<int> uniqueFreq(freqArr.begin(),freqArr.end());
        return uniqueFreq.size() == freqArr.size();
    }
};

//{ Driver Code Starts.
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        int arr[n];
        for(int i=0;i<n;i++)
            cin>>arr[i];
        Solution ob;
        bool ans=ob.isFrequencyUnique(n,arr);
        if(ans)
            cout<<1<<endl;
        else
            cout<<0<<endl;
    }
}
// } Driver Code Ends
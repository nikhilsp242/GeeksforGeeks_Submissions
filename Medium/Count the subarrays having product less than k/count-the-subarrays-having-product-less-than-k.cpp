//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

                                                                                                //HAS PASSED ALL THE TEST CASES  (1122 / 1122)

// } Driver Code Ends


class Solution{
  public:
    long long countSubArrayProductLessThanK(const vector<int>& a, int n, long long k) {
        //code here
//---------------------------------------------------------------------------------------------------------------------------------------
        /*
        long long num = 0;
        for(int i = 0; i < n; i++){                                                             //passed (1120 / 1122)
            if(a[i]<k){
                int j = i;
                long long prod = 1;
                while(j<n){
                    prod *= a[j++];
                    if(prod<k)
                        num++;
                    else
                        j = n;
                }
            }
        }
        return num;*/
//---------------------------------------------------------------------------------------------------------------------------------------
/*
        long long num = 0 ;
        long long prod = a[0];
        int i = 0,j = 0;
        while(i<n){                                                                            //passed (1120 / 1122)
            if(prod<k && j<n){
                num++;
                prod *= a[++j];
            }   
            else{
                i++;
                j = i;
                prod = a[j];
            }
                
        }
        return num;*/
//---------------------------------------------------------------------------------------------------------------------------------------
        
        long long num = 0;
        long long prod = 1;
        int i = 0, j = 0;

        while (i < n && j < n) {                                                              //passed (1122 / 1122)
            if (prod * a[j] < k) {
                prod *= a[j];
                num += j - i + 1;
                j++;
            } 
            else {
            prod /= a[i];
                i++;
                if (i > j) {
                    j = i;
                    prod = 1;
                }   
            }
        }


        return num;
//---------------------------------------------------------------------------------------------------------------------------------------

    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, i;
        long long int k;
        cin >> n >> k;
        vector<int> arr(n);
        for (i = 0; i < n; i++) cin >> arr[i];
        Solution obj;
        cout << obj.countSubArrayProductLessThanK(arr, n, k) << endl;
    }
    return 0;
}

// } Driver Code Ends

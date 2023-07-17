//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
	public:
		string FirstNonRepeating(string A){
		    // Code here
		    string nonRep;
		    map<char,int> m;
		    queue<char> q;
		    for(int i=0;i<A.size();i++){
		        m[A[i]]++;
		        q.push(A[i]);
		        while(!q.empty()){
		            if(m[q.front()]>1)
		                q.pop();
		            else{
		               nonRep += q.front();
		               break;
		            }
		        }
		        if(q.empty())
		            nonRep += '#';
		    }
		    return nonRep;
		}

};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		string A;
		cin >> A;
		Solution obj;
		string ans = obj.FirstNonRepeating(A);
		cout << ans << "\n";
	}
	return 0;
}
// } Driver Code Ends
//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    // Helper function for DFS
    void dfsUtil(int v, vector<int>& visited, vector<int>& result, vector<int> adj[]) {
        visited[v] = true; // Mark the current node as visited
        result.push_back(v); // Add the current node to the result list
        
        // Traverse all adjacent vertices of the current node
        for (int u : adj[v]) {
            if (!visited[u]) {
                dfsUtil(u, visited, result, adj); // Recursive call for unvisited adjacent vertex
            }
        }
    }
    // Function to return a list containing the DFS traversal of the graph.
    vector<int> dfsOfGraph(int V, vector<int> adj[]) {
        // Code here
        vector<int> result; // List to store the DFS traversal result
        vector<int> visited(V, false); // Mark all vertices as unvisited

        // Start DFS from the 0th vertex
        dfsUtil(0, visited, result, adj);

        return result;
    }
};

//{ Driver Code Starts.
int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int V, E;
        cin >> V >> E;

        vector<int> adj[V];

        for (int i = 0; i < E; i++) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        // string s1;
        // cin>>s1;
        Solution obj;
        vector<int> ans = obj.dfsOfGraph(V, adj);
        for (int i = 0; i < ans.size(); i++) {
            cout << ans[i] << " ";
        }
        cout << endl;
    }
    return 0;
}
// } Driver Code Ends
//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    Node *left;
    Node *right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};
// Function to Build Tree


// } Driver Code Ends
//Function to find the lowest common ancestor in a BST.
class Solution{
    public:
    
        /*
        //-----------------------------------------------------------------------------------------------------
        //helper function to search the nodes
        Node* search(Node* root, int target, vector<Node*>& path) {       // O(n) , n -> number of nodes
            if (root == nullptr) return nullptr;
        
            if (root->data == target) {
                path.push_back(root);
                return root;
            }
        
            path.push_back(root);
        
            Node* leftResult = search(root->left, target, path);
            if (leftResult) return leftResult;
        
            Node* rightResult = search(root->right, target, path);
            if (rightResult) return rightResult;
        
            path.pop_back();
            return nullptr;
        }
        
        Node* LCA(Node* root, int n1, int n2) {
            if (root == nullptr) return nullptr;
        
            vector<Node*> path1, path2;
            Node* lca = search(root, n1, path1);
            if (!lca) return nullptr;
        
            lca = search(root, n2, path2);
            if (!lca) return nullptr;
        
            int i = 0;
            while (i < min(path1.size(), path2.size()) && path1[i] == path2[i]) {
                lca = path1[i];
                i++;
            }
        
            return lca;
        }
        */
        //-----------------------------------------------------------------------------------------------------
        //better approach 
        Node* LCA(Node *root, int n1, int n2)                     // O(h)  , h -> height of the tree
        {
            // code here
            if(!root) return NULL;
            if(root->data < n1 && root->data < n2) return LCA(root->right, n1, n2);
            if(root->data > n1 && root->data > n2) return LCA(root->left, n1, n2);
            return root;
        }
        //-----------------------------------------------------------------------------------------------------

};


//{ Driver Code Starts.

Node* buildTree(string str)
{   
    // Corner Case
    if(str.length() == 0 || str[0] == 'N')
            return NULL;
    
    // Creating vector of strings from input 
    // string after spliting by space
    vector<string> ip;
    
    istringstream iss(str);
    for(string str; iss >> str; )
        ip.push_back(str);
        
    // Create the root of the tree
    Node* root = new Node(stoi(ip[0]));
        
    // Push the root to the queue
    queue<Node*> queue;
    queue.push(root);
        
    // Starting from the second element
    int i = 1;
    while(!queue.empty() && i < ip.size()) {
            
        // Get and remove the front of the queue
        Node* currNode = queue.front();
        queue.pop();
            
        // Get the current node's value from the string
        string currVal = ip[i];
            
        // If the left child is not null
        if(currVal != "N") {
                
            // Create the left child for the current node
            currNode->left = new Node(stoi(currVal));
                
            // Push it to the queue
            queue.push(currNode->left);
        }
            
        // For the right child
        i++;
        if(i >= ip.size())
            break;
        currVal = ip[i];
            
        // If the right child is not null
        if(currVal != "N") {
                
            // Create the right child for the current node
            currNode->right = new Node(stoi(currVal));
                
            // Push it to the queue
            queue.push(currNode->right);
        }
        i++;
    }
    
    return root;
}


int main()
{

    int t;
	scanf("%d ",&t);
    while(t--)
    {
        string s;
        int l , h;
		getline(cin,s);
		scanf("%d ",&l);
		scanf("%d ",&h);
        Node* root = buildTree(s);
        Solution sol;
        int ans = sol.LCA(root, l, h)->data;
        cout<<ans<<endl;
    }
    return 1;
}
// } Driver Code Ends
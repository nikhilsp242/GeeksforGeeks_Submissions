//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    struct Node *left;
    struct Node *right;
};
Node* newNode(int val)
{
    Node* temp = new Node;
    temp->data = val;
    temp->left = NULL;
    temp->right = NULL;
    
    return temp;
}
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
    Node* root = newNode(stoi(ip[0]));
        
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
            currNode->left = newNode(stoi(currVal));
                
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
            currNode->right = newNode(stoi(currVal));
                
            // Push it to the queue
            queue.push(currNode->right);
        }
        i++;
    }
    
    return root;
}
int kthAncestor(Node *root, int k, int node);

int main()
{
    int t;
	scanf("%d ",&t);
    while(t--)
    {
        int k , node;
        scanf("%d ",&k);
        scanf("%d ",&node);
        string s;
		getline(cin,s);
		Node* root = buildTree(s);
		cout<<kthAncestor(root,k,node)<<endl;
    }
    return 0;
}

// } Driver Code Ends


//User function Template for C++
/*
Structure of the node of the binary tree is as
struct Node
{
	int data;
	struct Node *left, *right;
};
*/
// your task is to complete this function

//helper function - 1
/*-----------------------------------------------------------------------------------------------------------------------------
bool find(Node* root, int target, vector<int>& path){                  //Total time taken = 0.32s
    if(!root) return false;
    path.push_back(root->data);
    
    if(root->data==target) return true;
    
    if( find(root->left,target,path) || find(root->right,target,path))
        return true;
        
    path.pop_back();
    
    return false;
}
-----------------------------------------------------------------------------------------------------------------------------*/
//helper function - 2
int search(Node *root,int k,int node,stack<Node*>& st){               //Total time taken = 0.32s
    if(root==nullptr) return -1;

    if(root->data==node){
        if(k<=st.size()){
           for(int i=1;i<k;i++){
            st.pop();
            }
            Node* temp = st.top();
            return temp->data; 
        }
        else return -1;
    }
    if(root->left==nullptr && root->right==nullptr) return -1;   //to stop further recursion //No need to add leaf nodes to stack
    else st.push(root);
    
    int leftPath = search(root->left,k,node,st);
    if(leftPath!=-1) return leftPath;
    
    int rightPath = search(root->right,k,node,st);
    if(rightPath!=-1) return rightPath;
    
    st.pop(); // Backtrack and remove the current node from the stack
    return -1;
}

//-----------------------------------------------------------------------------------------------------------------------------

int kthAncestor(Node *root, int k, int node)
{
    // Code here
    //-------------------------------------------------------------------------------------------------------------------------
    /*
    vector<int> path;                                       //Method - 1 , using helper function - 1.
    find(root, node, path);
    
    int n=path.size();
    if(n>k)
    return path[n-k-1];
    
    return -1;
    */
    //-------------------------------------------------------------------------------------------------------------------------
    stack<Node*> st;                                        //Method - 2 , using helper function - 2.   
    int ancestor = search(root,k,node,st); 
    return ancestor;
    //-------------------------------------------------------------------------------------------------------------------------
    
}
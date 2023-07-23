//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;
/* Link list Node */
struct Node {
    int data;
    struct Node *next;
    Node(int x) {
        data = x;
        next = NULL;
    }
};

struct Node *start = NULL;


// } Driver Code Ends
/*
 
  Node is defined as
  struct Node {
    int data;
    struct Node *next;
    Node(int x) {
        data = x;
        next = NULL;
    }
};

*/
class Solution
{
    public:
    //Function to sort a linked list of 0s, 1s and 2s.
    Node* segregate(Node *head) {
        // Add code here
        /*------------------------------------------------------------------------------------------------------------------
        Node* curr = head;
        map<int,int> mp;
        while(curr){
            mp[curr->data]++;
            curr = curr->next;
        }
        Node* newHead = nullptr;                                 //O(2N)       //Total time taken = 0.15s
        Node* newCurr = nullptr;
        for(const auto& pair : mp){
            int key = pair.first;
            int value = pair.second;
            for(int i = 0;i < value;++i){
                Node* newNode = new Node(key);
                if(newHead==nullptr){
                    newHead = newNode;
                    newCurr = newHead;
                }
                else{
                    newCurr->next = newNode;
                    newCurr = newCurr->next;
                }
            }
        }
        return newHead;
        ------------------------------------------------------------------------------------------------------------------*/
        //better approach
        if (head == nullptr || head->next == nullptr)
        return head;
        
        Node* zeroHead = new Node(0);
        Node* oneHead = new Node(1);
        Node* twoHead = new Node(2);

        Node* zeroTail = zeroHead;
        Node* oneTail = oneHead;
        Node* twoTail = twoHead;
        
        Node* curr = head;
        while (curr != nullptr) {                                   //O(N)         // Total time taken = 0.09s
            if (curr->data == 0) {
                zeroTail->next = curr;
                zeroTail = zeroTail->next;
            } else if (curr->data == 1) {
                oneTail->next = curr;
                oneTail = oneTail->next;
            } else {
                twoTail->next = curr;
                twoTail = twoTail->next;
            }
            curr = curr->next;
        }

        // Connect the three sublists
        zeroTail->next = oneHead->next ? oneHead->next : twoHead->next;
        oneTail->next = twoHead->next;
        twoTail->next = nullptr;

        // Update the head to the correct start of the sorted linked list
        head = zeroHead->next;

        // Free the dummy nodes
        delete zeroHead;
        delete oneHead;
        delete twoHead;

        return head;
    }
};


//{ Driver Code Starts.

// Function to sort a linked list of 0s, 1s and 2s
void printList(struct Node *Node) {
    while (Node != NULL) {
        printf("%d ", Node->data);
        Node = Node->next;
    }
    printf("\n");
}

/* Drier program to test above function*/
void insert(int n1) {
    int n, value, i;
    // scanf("%d",&n);
    n = n1;
    struct Node *temp;
    for (i = 0; i < n; i++) {
        scanf("%d", &value);

        if (i == 0) {
            start = new Node(value);
            temp = start;
            continue;
        } else {
            temp->next = new Node(value);
            temp = temp->next;
            temp->next = NULL;
        }
    }
}

int main() {

    int n;

    int t;
    scanf("%d", &t);

    while (t--) {
        scanf("%d", &n);

        insert(n);
        Solution ob;
        struct Node *newHead = ob.segregate(start);
        printList(newHead);
    }

    return 0;
}
// } Driver Code Ends
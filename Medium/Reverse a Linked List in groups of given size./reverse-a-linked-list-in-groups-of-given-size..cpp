//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


struct node
{
    int data;
    struct node* next;
    
    node(int x){
        data = x;
        next = NULL;
    }
    
};

/* Function to print linked list */
void printList(struct node *node)
{
    while (node != NULL)
    {
        printf("%d ", node->data);
        node = node->next;
    }
    printf("\n");
}


// } Driver Code Ends
/*
  Reverse a linked list
  The input list will have at least one element  
  Return the node which points to the head of the new LinkedList
  Node is defined as 
    struct node
    {
        int data;
        struct node* next;
    
        node(int x){
            data = x;
            next = NULL;
        }
    
    }*head;
*/

class Solution
{
    public:
    struct node *reverse (struct node *head, int k)
    { 
        // Complete this method
        if (head == NULL || k <= 1) return head;

        node* current = head;
        node* prevTail = NULL;
        node* newHead = NULL;

        while (current != NULL) {
            int count = 0;
            node* prev = NULL;
            node* temp = current;
        
            // Reverse k nodes
            while (current != NULL && count < k) {
                node* nextNode = current->next;
                current->next = prev;
                prev = current;
                current = nextNode;
                count++;
            }

            // For the first group, update the newHead
            if (newHead == NULL) newHead = prev;

            // Update the tail of the previous group to the current head
            if (prevTail != NULL) prevTail->next = prev;

            // Save the tail of the current group to use in the next iteration
            prevTail = temp;
        }
        return newHead;
    }
};


//{ Driver Code Starts.

/* Drier program to test above function*/
int main(void)
{
    int t;
    cin>>t;
     
    while(t--)
    {
        struct node* head = NULL;
        struct node* temp = NULL;
        int n;
        cin >> n;
         
        for(int i=0 ; i<n ; i++)
        {
            int value;
            cin >> value;
            if(i == 0)
            {
                head = new node(value);
                temp = head;
            }
            else
            {
                temp->next = new node(value);
                temp = temp->next;
            }
        }
        
        int k;
        cin>>k;
        
        Solution ob;
        head = ob.reverse(head, k);
        printList(head);
    }
     
    return(0);
}


// } Driver Code Ends
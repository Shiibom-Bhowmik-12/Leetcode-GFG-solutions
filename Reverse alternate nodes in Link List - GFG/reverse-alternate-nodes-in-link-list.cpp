// { Driver Code Starts
#include<stdio.h>
#include<stdlib.h>
#include<iostream>
using namespace std;
/* A linked list node */


struct Node
{
    int data;
    struct Node *next;
    
    Node(int x){
        data = x;
        next = NULL;
    }
    
};

struct Node *start = NULL;

/* Function to print nodes in a given linked list */
void printList(struct Node *node)
{
    while (node != NULL)
    {
        printf("%d ", node->data);
        node = node->next;
    }
    printf("\n");
    
}

void insert()
{
    int n,value;
    cin>>n;
    struct Node *temp;
    for(int i=0;i<n;i++)
    {
        cin>>value;
        if(i==0)
        {
            start = new Node(value);
            temp = start;
            continue;
        }
        else
        {
            temp->next = new Node(value);
            temp = temp->next;
        }
    }
}


 // } Driver Code Ends
/*
  reverse alternate nodes and append at the end
  The input list will have at least one element  
  Node is defined as 
  struct Node
  {
      int data;
      struct Node *next;
    
      Node(int x){
        data = x;
        next = NULL;
      }
    
   };

*/
class Solution
{
    public:
    Node *reverse(Node *head){
        Node *prev=NULL;
        Node *curr=head;
        while(curr){
            Node *next=curr->next;
            curr->next=prev;
            prev=curr;
            curr=next;
        }
        return prev;
    }
    
    void rearrange(struct Node *odd)
    {
        //add code here
        if(odd==NULL or odd->next==NULL){
            return;
        }
        
        int d=1;
        Node *es=NULL,*ee=NULL,*os=NULL,*oe=NULL;
        Node *curr=odd;
        while(curr){
            if(d%2==0){
                if(es==NULL){
                    es=ee=curr;
                }
                else{
                    ee->next=curr;
                    ee=ee->next;
                }
            }
            else{
                if(os==NULL){
                    oe=os=curr;
                }
                else{
                    oe->next=curr;
                    oe=oe->next;
                }
            }
            
            d++;
            curr=curr->next;
        }
        
        if(es==NULL or os==NULL){
            return;
        }
        
        ee->next=NULL;
        es=reverse(es);
        oe->next=es;
        
        odd=os;
    }
};



// { Driver Code Starts.
int main()
{
    int t;
    cin>>t;
    while (t--) {
        insert();
        Solution ob;
        ob.rearrange(start);
        printList(start);
    }
    return 0;
}
  // } Driver Code Ends
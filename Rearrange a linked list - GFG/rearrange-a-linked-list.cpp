// { Driver Code Starts
// C program to find n'th Node in linked list
#include <stdio.h>
#include <stdlib.h>
#include<iostream>
using namespace std;

/* Link list Node */
struct Node
{
    int data;
    struct Node* next;
    
    Node(int x){
        data = x;
        next = NULL;
    }
};



 // } Driver Code Ends
/* Node structure

struct Node
{
    int data;
    struct Node* next;
    
    Node(int x){
        data = x;
        next = NULL;
    }
};
*/

class Solution
{
    public:
    void rearrangeEvenOdd(Node *head)
    {
       // Your Code here
       Node *es=NULL,*ee=NULL,*os=NULL,*oe=NULL;
       int x=1;
       
       Node *curr=head;
       while(curr!=NULL){
           if(x%2==0){
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
                   os=oe=curr;
               }
               else{
                   oe->next=curr;
                   oe=oe->next;
               }
           }
           
           x++;
           curr=curr->next;
       }
       
       if(es==NULL or oe==NULL){
           return;
       }
       
       oe->next=es;
       ee->next=NULL;
       head=es;
    }
};


// { Driver Code Starts.

/* Driver program to test above function*/
int main()
{
    int T,i,n,l;

    cin>>T;

    while(T--)
    {
        struct Node *head = NULL;
        struct Node *temp = head;
        cin>>n;
        for(i=1; i<=n; i++)
        {
            cin>>l;

            if (head == NULL)
            {   
                head = temp = new Node(l); 
                
            }
            else
            {  temp->next = new Node(l);
               temp = temp->next;
            }
        }
        Solution ob;
        ob.rearrangeEvenOdd(head);
        while(head != NULL)
        {
            printf("%d ", head->data);
            head = head->next;
        }
        printf("\n");
    }
    return 0;
}
  // } Driver Code Ends
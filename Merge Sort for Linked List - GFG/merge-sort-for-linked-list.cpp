// { Driver Code Starts
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    struct Node* next;
    Node(int x) {
        data = x;
        next = NULL;
    }
};


 // } Driver Code Ends
/* Structure of the linked list node is as
struct Node 
{
    int data;
    struct Node* next;
    Node(int x) { data = x;  next = NULL; }
};
*/


class Solution{
  public:
    //Function to sort the given linked list using Merge Sort.
    Node* sortedMerge(Node* head1, Node* head2)  
    {  
        // code here
        if(head1==NULL){
            return head2;
        }
        
        if(head2==NULL){
            return head1;
        }
        
        Node *start=new Node(-1);
        Node *end=start;
        if(head1->data <= head2->data){
            end->next=head1;
            end=end->next;
            head1=head1->next;
        }
        else{
            end->next=head2;
            end=end->next;
            head2=head2->next;
        }
        
        while(head1!=NULL and head2!=NULL){
            if(head1->data <= head2->data){
                end->next=head1;
                end=end->next;
                head1=head1->next;
            }
            else{
                end->next=head2;
                end=end->next;
                head2=head2->next;
            }
        }
        
        if(head1==NULL){
            end->next=head2;
        }
        
        if(head2==NULL){
            end->next=head1;
        }
        
        return start->next;
    }  

    Node* mergeSort(Node* head) {
        // your code here
        if(head==NULL or head->next==NULL){
            return head;
        }
        
        Node *slow=head,*fast=head->next;
        // Node *prev=NULL;
        while(fast!=NULL and fast->next!=NULL){
            // prev=slow;
            slow=slow->next;
            fast=fast->next->next;
        }
        
        // prev->next=NULL;
        Node *head1=head;
        Node *head2=slow->next;
        slow->next=NULL;
        
        head1=mergeSort(head1);
        head2=mergeSort(head2);
        
        head=sortedMerge(head1,head2);
        return head;
    }
};


// { Driver Code Starts.

void printList(Node* node) {
    while (node != NULL) {
        printf("%d ", node->data);
        node = node->next;
    }
    printf("\n");
}

void push(struct Node** head_ref, int new_data) {
    Node* new_node = new Node(new_data);

    new_node->next = (*head_ref);
    (*head_ref) = new_node;
}

int main() {
    long test;
    cin >> test;
    while (test--) {
        struct Node* a = NULL;
        long n, tmp;
        cin >> n;
        for (int i = 0; i < n; i++) {
            cin >> tmp;
            push(&a, tmp);
        }
        Solution obj;
        a = obj.mergeSort(a);
        printList(a);
    }
    return 0;
}  // } Driver Code Ends
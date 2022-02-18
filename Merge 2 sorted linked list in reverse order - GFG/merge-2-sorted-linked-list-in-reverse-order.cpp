// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

/* Link list Node */
struct Node
{
    int data;
    struct Node* next;
};

void print(struct Node *Node)
{
    while (Node!=NULL)
    {
        cout << Node->data << " ";
        Node = Node->next;
    }
}

struct Node * mergeResult(struct Node *node1,struct Node *node2);

Node *newNode(int data)
{
    Node *temp = new Node;
    temp->data = data;
    temp->next = NULL;
    return temp;
}

int main()
{
    int T;
    cin>>T;
    while(T--)
    {
        int nA;
        cin>>nA;
        int nB;
        cin>>nB;

        struct Node* headA=NULL;
        struct Node* tempA = headA;

        for(int i=0;i<nA;i++)
        {
            int ele;
            cin>>ele;
            if(headA==NULL)
            {
                headA=tempA=newNode(ele);

            }else{
                tempA->next = newNode(ele);
				tempA=tempA->next;
            }
        }

        struct Node* headB=NULL;
        struct Node* tempB = headB;


        for(int i=0;i<nB;i++)
        {
            int ele;
            cin>>ele;
            if(headB==NULL)
            {
                headB=tempB=newNode(ele);

            }else{
                tempB->next = newNode(ele);
				tempB=tempB->next;
            }
        }

        struct Node* result = mergeResult(headA,headB);

        print(result);
        cout<<endl;


    }
}
// } Driver Code Ends


/*

The structure of linked list is the following

struct Node
{
int data;
Node* next;
};

*/
   Node *reverse(Node *head){
        if(head==NULL or head->next==NULL){
            return head;
        }
        
        Node *curr=head;
        Node *prev=NULL;
        while(curr!=NULL){
            Node *next=curr->next;
            curr->next=prev;
            prev=curr;
            curr=next;
        }
        return prev;
    }
    
struct Node * mergeResult(Node *node1,Node *node2)
{
    // your code goes here
    if(node1==NULL){
        return node2;
    }
    
    if(node2==NULL){
        return node1;
    }
    
     Node *head=NULL;
     Node *end=head;
    
    if(node1->data <= node2->data){
        head=end=node1;
        node1=node1->next;
    }
    else{
       head=end=node2;
       node2=node2->next;
    }
    
    while(node1!=NULL and node2!=NULL){
        if(node1->data <= node2->data){
            end->next=node1;
            end=end->next;
            node1=node1->next;
        }
        else{
            end->next=node2;
            end=end->next;
            node2=node2->next;
        }
    }
    
    if(node1==NULL){
        end->next=node2;
    }
    else{
        end->next=node1;
    }
    
    return reverse(head);
}

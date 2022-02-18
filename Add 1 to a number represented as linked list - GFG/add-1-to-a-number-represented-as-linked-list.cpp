// { Driver Code Starts
//Initial template for C++

#include <bits/stdc++.h> 
using namespace std; 

struct Node
{
    int data;
    struct Node* next;
    
    Node(int x){
        data = x;
        next = NULL;
    }
};

void printList(Node* node) 
{ 
    while (node != NULL) { 
        cout << node->data; 
        node = node->next; 
    }  
    cout<<"\n";
} 


 // } Driver Code Ends
//User function template for C++

/* 

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
    
    Node* addOne(Node *head_ref) 
    {
        // Your Code here
        // return head of list after adding one
        Node *temp=new Node(1);
        int carry=0;
        
        Node *start=new Node(-1);
        Node *end=start;
        
        Node *head=reverse(head_ref);
        while(head!=NULL or temp!=NULL or carry!=0){
            int sum=0;
            if(head){
                sum+=head->data;
                head=head->next;
            }
            
            if(temp){
                sum+=temp->data;
                temp=temp->next;
            }
            
            sum+=carry;
            carry=sum/10;
            Node *add=new Node(sum%10);
            end->next=add;
            end=end->next;
        }
        
        end->next=NULL;
        return reverse(start->next);
    }
};

// { Driver Code Starts.

int main() 
{ 
    int t;
    cin>>t;
    while(t--)
    {
        string s;
        cin>>s;
        
        Node* head = new Node( s[0]-'0' );
        Node* tail = head;
        for(int i=1; i<s.size(); i++)
        {
            tail->next = new Node( s[i]-'0' );
            tail = tail->next;
        }
        Solution ob;
        head = ob.addOne(head);
        printList(head); 
    }
    return 0; 
} 
  // } Driver Code Ends
// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

struct Node
{
	char data;
	struct Node *next;
	
	Node(int x){
	    data = x;
	    next = NULL;
	}
	
};

void printlist(Node *head)
{
	if (head==NULL)return;
	while (head != NULL)
	{
		cout << head->data << " ";
		head = head->next;
	}
	cout << endl;
}

void append(struct Node** headRef, char data)
{
	struct Node* new_node = new Node(data);
	struct Node *last = *headRef;

	if (*headRef == NULL)
	{
	    *headRef = new_node;
	    return;
	}
	while (last->next != NULL)
		last = last->next;
	last->next = new_node;
	return;
}

// task is to complete this function
struct Node* arrange(Node *head);

int main()
{
    int T;
    cin>>T;
    while(T--){
        int n;
        char tmp;
        struct Node *head = NULL;
        cin>>n;
        while(n--){
            cin>>tmp;
            append(&head, tmp);
        }
        head = arrange(head);
        printlist(head);
    }
	return 0;
}

// } Driver Code Ends


/*
Structure of the node of the linked list is as
struct Node
{
	char data;
	struct Node *next;
	
	Node(int x){
	    data = x;
	    next = NULL;
	}
	
};
*/
// task is to complete this function
// function should return head to the list after making 
// necessary arrangements
bool v_check(Node *head){
    return (head->data=='a' or head->data=='e' or head->data=='i' or head->data=='o'
            or head->data=='u');
}

struct Node* arrange(Node *head)
{
   //Code here
   if(head==NULL){
       return head;
   }
   
   Node *vs=NULL,*ve=NULL,*cs=NULL,*ce=NULL;
   Node *curr=head;
   while(curr){
    //   char c=curr->data;
       if(v_check(curr)){
           if(vs==NULL){
               vs=ve=curr;
           }
           else{
               ve->next=curr;
               ve=ve->next;
           }
       }
       else{
           if(cs==NULL){
               cs=ce=curr;
           }
           else{
               ce->next=curr;
               ce=ce->next;
           }
       }
       
       curr=curr->next;
   }
   
   if(vs==NULL or cs==NULL){
       return head;
   }
   
   ve->next=cs;
   ce->next=NULL;
   return vs;
}

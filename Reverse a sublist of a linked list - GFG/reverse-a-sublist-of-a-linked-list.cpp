// { Driver Code Starts
//Initial Template for C++

#include<bits/stdc++.h>
using namespace std;

/* Link list node */
struct Node {
	int data;
	struct Node *next;
	Node(int x) {
		data = x;
		next = NULL;
	}
};


 // } Driver Code Ends
//User function Template for C++

/*Link list node 
struct Node {
	int data;
	struct Node *next;
	Node(int x) {
		data = x;
		next = NULL;
	}
};*/

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

   int len(Node *head){
        int c=0;
        Node *curr=head;
        while(curr){
            c++;
            curr=curr->next;
        }
        
        return c;
    }
    
    Node* reverseBetween(Node* head, int left, int right)
    {
        //checking for edge cases
        //if the head is NULL or left==right
        //we return head
        //we dont need to reverse anything.
        if(head==NULL or left==right){
            return head;
        }
        
        //if the left is 1 and the right is equal to length of the LL
        //means the whole LL is to be reversed
        //so we return the reverse of head.
        if(left==1 and right==len(head)){
            return reverse(head);
        }
        
        //if the left=1 and right>left.
        if(left==1){
            Node *curr=head;
            
            //we traverse till the right'th node.
            for(int i=0;i<right-1;i++){
                curr=curr->next;
            }
            
            //we mark the next of right'th node as the f so that we get hold of 
            //that node and make the curr->next as NULL to reverse the LL
            //starting from left=1 till right.
            Node *f=curr->next;
            curr->next=NULL;
            head=reverse(head);//reversing the LL
            curr=head;
            while(curr->next!=NULL){
                curr=curr->next;
            }
            
            //we attach the reversed LL to the remaining list nodes
            curr->next=f;
            return head;
        }
        
        //if the left>1 and right>left
        else{
            Node *curr=head;
            
            //travering till the node before the left'th node
            for(int i=0;i<left-2;i++){
               curr=curr->next;   
            }
            
            //marking the left'th with a node name 'f' so that we can reverse 
            Node *f=curr->next;
            curr->next=NULL;//breaking the link
             
            //traversing the LL to find and mark the right'th node of LL
            curr=f;
            for(int i=0;i<(right-left);i++){//traversing till right'th node
                curr=curr->next;
            }
 

            Node* s=curr->next;
            curr->next=NULL;//breaking the link
            f=reverse(f);//reversing the LL
            curr=head;
            while(curr->next!=NULL){
                curr=curr->next;
            }
            
            //now connectiong the broken links
            curr->next=f;
            curr=curr->next;

            while(curr->next!=NULL){
                curr=curr->next;
            }

            curr->next=s;

            return head;
    }
}
};

// { Driver Code Starts.

/* Function to print linked list */
void printList(struct Node *head)
{
	struct Node *temp = head;
	while (temp != NULL)
	{
		printf("%d ", temp->data);
		temp = temp->next;
	}
}



// Driver program to test above functions
int main()
{
	int T;
	cin >> T;

	while (T--)
	{
		int N, m, n;
		cin >> N>>m>>n;

		Node *head = NULL;
		Node *temp = head;

		for (int i = 0; i < N; i++) {
			int data;
			cin >> data;
			if (head == NULL)
				head = temp = new Node(data);
			else
			{
				temp->next = new Node(data);
				temp = temp->next;
			}
		}

		

        Solution ob;

		Node* newhead = ob.reverseBetween(head, m, n);
		printList(newhead);

		cout << "\n";



	}
	return 0;
}
  // } Driver Code Ends
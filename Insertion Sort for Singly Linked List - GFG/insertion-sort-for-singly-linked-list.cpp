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
    Node *start=NULL;
    void sorted_insert(Node *Node_p){   
        if(start==NULL or start->data >= Node_p->data){
            Node_p->next=start;
            start=Node_p;
        }
        else{
            Node *curr=start;
            while(curr->next!=NULL and curr->next->data < Node_p->data){
                curr=curr->next;
            }

            Node_p->next=curr->next;
            curr->next=Node_p;
        }
    }
    
    Node* insertionSort(struct Node* head_ref)
    {
        //code here
        Node *temp=head_ref;
        while(temp){
            Node *next=temp->next;
            sorted_insert(temp);
            temp=next;
        }
        
        head_ref=start;
        return head_ref;
    }
    
};

// { Driver Code Starts.
int main()
{
	int T;
	cin >> T;

	while (T--)
	{
		int n;
		cin >> n;

		Node *head = NULL;
		Node *temp = head;

		for (int i = 0; i < n; i++) {
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

		head = ob.insertionSort(head);
		printList(head);

		cout << "\n";



	}
	return 0;
}  // } Driver Code Ends
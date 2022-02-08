/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {
        if(head==NULL){
            return head;
        }
        
        Node *curr=head;
        Node *front=head;
        
        //step 1
        while(curr!=NULL){
            front=curr->next;
            Node *temp=new Node(curr->val);
            temp->next=curr->next;
            curr->next=temp;
            curr=front;
        }
        
        //step 2
        curr=head;
        while(curr!=NULL){
            front=curr->next->next;
            if(curr->random!=NULL){
                curr->next->random= curr->random->next;
            }
            curr=front;
        }
        
        
        //step 3
        Node *dummy=new Node(0);
        Node *rep=dummy;
        
        curr=head;
        while(curr!=NULL){
            front=curr->next->next;
            
            rep->next=curr->next;
            rep=rep->next;
            
            curr->next=front;
            curr=front;
        }
        
        return dummy->next;
    }
};
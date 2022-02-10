/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    //function for reversing the given linked list
    ListNode *reverse(ListNode *head){
        ListNode *curr=head;
        ListNode *prev=NULL;
        while(curr!=NULL){
            ListNode *next=curr->next;
            curr->next=prev;
            prev=curr;
            curr=next;
        }
        return prev;
    }
    
    //function for finding the length of the linked list
    int len(ListNode *head){
        int c=0;
        ListNode *curr=head;
        while(curr){
            c++;
            curr=curr->next;
        }
        
        return c;
    }
    
    
    ListNode* reverseBetween(ListNode* head, int left, int right) {
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
            ListNode *curr=head;
            
            //we traverse till the right'th node.
            for(int i=0;i<right-1;i++){
                curr=curr->next;
            }
            
            //we mark the next of right'th node as the f so that we get hold of 
            //that node and make the curr->next as NULL to reverse the LL
            //starting from left=1 till right.
            ListNode *f=curr->next;
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
            ListNode *curr=head;
            
            //travering till the node before the left'th node
            for(int i=0;i<left-2;i++){
               curr=curr->next;   
            }
            
            //marking the left'th with a node name 'f' so that we can reverse 
            ListNode *f=curr->next;
            curr->next=NULL;//breaking the link
             
            //traversing the LL to find and mark the right'th node of LL
            curr=f;
            for(int i=0;i<(right-left);i++){//traversing till right'th node
                curr=curr->next;
            }
 

            ListNode* s=curr->next;
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
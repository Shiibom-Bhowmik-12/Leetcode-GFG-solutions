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
        if(head==NULL or left==right){
            return head;
        }
        
        if(left==1 and right==len(head)){
            return reverse(head);
        }
        
        if(left==1){
            ListNode *curr=head;
            for(int i=0;i<right-1;i++){
                curr=curr->next;
            }
            
            ListNode *f=curr->next;
            curr->next=NULL;
            // curr=head;
            head=reverse(head);
            curr=head;
            while(curr->next!=NULL){
                curr=curr->next;
            }
            
            curr->next=f;
            return head;
        }
        else{
            ListNode *curr=head;
            for(int i=0;i<left-2;i++){
               curr=curr->next;   
            }

            ListNode *f=curr->next;
            curr->next=NULL;

            curr=f;
            for(int i=0;i<(right-left);i++){
                curr=curr->next;
            }

            ListNode* s=curr->next;
            curr->next=NULL;
            f=reverse(f);

            curr=head;
            while(curr->next!=NULL){
                curr=curr->next;
            }

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
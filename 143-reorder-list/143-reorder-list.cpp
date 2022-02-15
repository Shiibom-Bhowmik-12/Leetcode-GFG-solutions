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
        ListNode *prev=NULL;
        ListNode *curr=head;
        
        while(curr!=NULL){
            ListNode *next=curr->next;
            curr->next=prev;
            prev=curr;
            curr=next;
        }
        
        return prev;
    }
    
    void reorderList(ListNode* head) {
        if(head==NULL or head->next==NULL){
            return;
        }
        
        ListNode *slow=head,*fast=head->next;
        while(fast!=NULL and fast->next!=NULL){
            slow=slow->next;
            fast=fast->next->next;
        }
        
        ListNode *head1=head;
        ListNode *head2=reverse(slow->next);
        slow->next=NULL;
        
        ListNode *start=new ListNode(-1);
        ListNode *end=start;
        
        while(head1 or head2){
            if(head1){
              end->next=head1;
              end=end->next;
              head1=head1->next;
            }
            
            if(head2){
                end->next=head2;
                end=end->next;
                head2=head2->next;
            }
        }
        
        end->next=NULL;
        head=start->next;
        // return head;
    }
};
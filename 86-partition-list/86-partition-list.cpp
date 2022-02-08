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
    ListNode* partition(ListNode* head, int x) {
        if(head==NULL or head->next==NULL){
            return head;
        }
        
        ListNode *ms=NULL,*me=NULL,*ls=NULL,*le=NULL;
        ListNode *curr=head;
        while(curr!=NULL){
            if(curr->val < x){
                if(ls==NULL){
                    ls=le=curr;
                }
                else{
                    le->next=curr;
                    le=le->next;
                }
            }
            else if(curr->val >= x){
                if(ms==NULL){
                    ms=me=curr;
                }
                else{
                    me->next=curr;
                    me=me->next;
                }
            }
            
           curr=curr->next;
        }
        
        if(ls==NULL or ms==NULL){
            return head;
        }
        
        le->next=ms;
        me->next=NULL;
        return ls;
    }
};
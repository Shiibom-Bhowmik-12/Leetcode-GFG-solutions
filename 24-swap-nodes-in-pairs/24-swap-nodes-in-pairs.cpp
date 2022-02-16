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
    ListNode* swapPairs(ListNode* head) {
        if(head==NULL or head->next==NULL){
            return head;
        }
        
        ListNode *prev=head;
        ListNode *curr=head->next->next;
        head=head->next;
        head->next=prev;
        while(curr!=NULL and curr->next!=NULL){
            prev->next=curr->next;
            ListNode *next=curr->next->next;
            curr->next->next=curr;
            prev=curr;
            curr=next;
        }
        prev->next=curr;
        return head;
    }
};
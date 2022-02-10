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
    int len(ListNode *head){
        int c=0;
        ListNode *curr=head;
        while(curr){
            c++;
            curr=curr->next;
        }
        return c;
    }
    
    ListNode* reverseKGroup(ListNode* head, int k) {
        int length=len(head);
        if(head==NULL or k<=1 or k>length){
            return head;
        }
        
        ListNode *dummy=NULL;
        ListNode *temp=head;
        ListNode *curr=head;
        int c=1;
        
        while(curr!=NULL and c<=k){
            ListNode *rep=curr;
            curr=curr->next;
            rep->next=NULL;
            rep->next=dummy;
            dummy=rep;
            c++;
        }
        
        temp->next=reverseKGroup(curr,k);
        return dummy;
    }
};
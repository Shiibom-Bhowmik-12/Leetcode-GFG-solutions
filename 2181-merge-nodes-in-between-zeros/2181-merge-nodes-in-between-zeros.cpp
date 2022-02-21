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
    ListNode* mergeNodes(ListNode* head) {
        if(head==NULL){
            return head;
        }
        
        ListNode *dummy=new ListNode(0);
        ListNode *temp=dummy;
        
        ListNode *curr=head->next;
        
        while(curr!=NULL){
            int sum=0;
            
            while(curr->val!=0){
                sum+=curr->val;
                curr=curr->next;
            }
            
            ListNode *node=new ListNode(sum);
            temp->next=node;
            temp=temp->next;
            curr=curr->next;
        }
        
        return dummy->next;
    }
};
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
    ListNode* deleteDuplicates(ListNode* head) {
        if(head==NULL or head->next==NULL){
            return head;
        }
        
        ListNode *curr=head;
        unordered_map<int,int> mp;
        while(curr){
            mp[curr->val]++;
            curr=curr->next;
        }
        
        ListNode *dummy=new ListNode(0);
        ListNode *temp=dummy;
        curr=head;
        while(curr){
            if(mp[curr->val]==1){
                temp->next=curr;
                temp=temp->next;
            }
            curr=curr->next;
        }
        
        temp->next=NULL;
        return dummy->next;
    }
};
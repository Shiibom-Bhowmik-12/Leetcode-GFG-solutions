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
    ListNode* sortList(ListNode* head) {
        vector<int> v;
        
        ListNode *curr=head;
        while(curr!=NULL){
            v.emplace_back(curr->val);
            curr=curr->next;
        }
        
        curr=head;
        sort(v.begin(),v.end());
        int i=0;
        
        while(curr!=NULL){
            curr->val=v[i++];
            curr=curr->next;
        }
        
        return head;
    }
};
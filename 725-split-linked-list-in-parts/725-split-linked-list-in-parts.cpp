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
    vector<ListNode*> splitListToParts(ListNode* head, int k) {
        vector<ListNode *> ans(k);
        int total_length=0;
        
        ListNode *curr=head;
        while(curr){
            total_length++;
            curr=curr->next;
        }
        
        int len=total_length / k;
        int extra_nodes=total_length % k;
        
        curr=head;
        ListNode *prev=NULL;
        int i=0;
        
        while(curr!=NULL and i<k){
            ans[i]=curr;
            
            for(int j=0;j<len+(extra_nodes>0?1:0);j++){
                prev=curr;
                curr=curr->next;
            }
            
            prev->next=NULL;
            i++;
            extra_nodes--;
        }
        
        return ans;
    }
};
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
        
//----------------  T.C - O(N), S.C - O(N) ----------------------------
//         if(head==NULL or head->next==NULL){
//             return head;
//         }
        
//         ListNode *curr=head;
//         unordered_map<int,int> mp;
//         while(curr){
//             mp[curr->val]++;
//             curr=curr->next;
//         }
        
//         ListNode *dummy=new ListNode(0);
//         ListNode *temp=dummy;
//         curr=head;
//         while(curr){
//             if(mp[curr->val]==1){
//                 temp->next=curr;
//                 temp=temp->next;
//             }
//             curr=curr->next;
//         }
        
//         temp->next=NULL;
//         return dummy->next;
//---------------------------------------------------------------------------
        
        
// ********   T.C -> O(N) , S.C -> O(1)    ****************
//-----------------------------------------------------------------------
      ListNode *last = new ListNode(0), *new_head = last;
        
        while (head) {
            
            if (head->next && head->val == head->next->val) {
                while (head->next && head->val == head->next->val)
                    head = head->next;
            }
            
            else {
                last->next = head;
                last = head;
            }
            
            head = head->next;
        }
        
        last->next = NULL;
        return new_head->next;
    }
};
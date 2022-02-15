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
    ListNode *start=NULL;
    
    
     void sorted_insert(ListNode *Node){   
        if(start==NULL or start->val >= Node->val){
            Node->next=start;
            start=Node;
        }
        else{
            ListNode *curr=start;
            while(curr->next!=NULL and curr->next->val < Node->val){
                curr=curr->next;
            }

            Node->next=curr->next;
            curr->next=Node;
        }
    }
    
    ListNode* insertionSortList(ListNode* head) {
        ListNode *temp=head;
        while(temp){
            ListNode *next=temp->next;
            sorted_insert(temp);
            temp=next;
        }
        
        head=start;
        return head;
    }
};
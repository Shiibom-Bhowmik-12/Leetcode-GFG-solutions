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
    
    ListNode *rev(ListNode *head,int k){
        int l=len(head);
        if(head==NULL or k<=1 or k>l){
            return head;
        }
        
        ListNode *dummy=NULL;
        ListNode *temphead=head;
        int i=1;
        while(head!=NULL and i<=k){
            ListNode *temp=head;
            head=head->next;
            temp->next=NULL;
            temp->next=dummy;
            dummy=temp;
            i++;
        }
        
        temphead->next=rev(head,k);
        return dummy;
    }
    
    ListNode* reverseKGroup(ListNode* head, int k) {
        return rev(head,k);
    }
};
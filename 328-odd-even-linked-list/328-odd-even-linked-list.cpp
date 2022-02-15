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
    ListNode* oddEvenList(ListNode* head) {
      if(head==NULL or head->next==NULL){
            return head;
        }
        
        ListNode *eS=NULL,*eE=NULL,*oS=NULL,*oE=NULL;
        ListNode *curr=head;
        int x=1;
        
        while(curr!=NULL){
            if(x%2==0){
                if(eS==NULL){
                    eS=eE=curr;
                }
                else{
                    eE->next=curr;
                    eE=eE->next;
                }
            }
            else{
                if(oS==NULL){
                    oS=oE=curr;
                }
                else{
                    oE->next=curr;
                    oE=oE->next;
                }
            }
            
            curr=curr->next;
            x++;
        }
        
        if(eS==NULL or oS==NULL){
            return head;
        }
        
        oE->next=eS;
        eE->next=NULL;
        head=oS;
        return head;        
    }
};
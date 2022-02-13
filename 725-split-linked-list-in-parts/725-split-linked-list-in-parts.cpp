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
        if(head==NULL or k==0){
            return ans;
        }
        
        int total_length=0;
        
        ListNode *curr=head;
        
        //calculating the length of LL
        while(curr){
            total_length++;
            curr=curr->next;
        }
        
        
        int len=total_length / k;//finding the length of each sublist
        int extra_nodes=total_length % k;//finding the no. of extra nodes which                                            //have to be connected with each list
        
        curr=head;
        ListNode *prev=NULL;
        int i=0;
        
        while(curr!=NULL and i<k){
            ans[i]=curr;
            
            //for the extra nodes we add it to all the list until the count of                 //extra nodes becomes 0.
            for(int j=0;j<len+(extra_nodes>0?1:0);j++){
                prev=curr;
                curr=curr->next;
            }
            
            prev->next=NULL;//making the nex tof each sublist as NULL
            i++;//incrementing the count of no. of sublists
            extra_nodes--;//decrementing the no. of extra nodes.
        }
        
        return ans;//returning the resultant vector containing all the sublists.
    }
};
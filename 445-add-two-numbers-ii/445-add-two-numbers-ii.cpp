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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        if(l1==NULL){
            return l2;
        }
        
        if(l2==NULL){
            return l1;
        }
        
        stack<ListNode *> s1,s2,s3;
        ListNode *curr1=l1;
        
        while(curr1!=NULL){
            s1.push(curr1);
            curr1=curr1->next;
        }
        
        curr1=l2;
        while(curr1!=NULL){
            s2.push(curr1);
            curr1=curr1->next;
        }
        
        int carry=0;
        ListNode *start=new ListNode(0);
        ListNode *end=start;
        while(!s1.empty() or !s2.empty() or carry!=0){
            int sum=0;
            if(!s1.empty()){
                sum+=s1.top()->val;
                s1.pop();
            }
            
            if(!s2.empty()){
                sum+=s2.top()->val;
                s2.pop();
            }
            
            sum+=carry;
            carry=sum/10;
            ListNode *temp=new ListNode(sum%10);
            s3.push(temp);
            // end->next=temp;
            // end=end->next;
        }
        
        while(!s3.empty()){
            end->next=s3.top();
            end=end->next;
            s3.pop();
        }
        return start->next;
    }
};
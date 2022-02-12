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
    ListNode* removeZeroSumSublists(ListNode* head) {
        ListNode* new_head = new ListNode(0);
        new_head->next = head;
        ListNode* cur = new_head;
        while(cur != NULL)
        {
            int sum=0;
            while(head != NULL)
            {
                sum += head->val;
                if(sum == 0)
                {
                   cur->next = head->next; 
                }
                head = head->next;
            }
            //What is happening here???
            cur = cur->next;
            if(cur != NULL)
            {
                head = cur->next;
            }
        }
        return new_head->next; 
    }
};
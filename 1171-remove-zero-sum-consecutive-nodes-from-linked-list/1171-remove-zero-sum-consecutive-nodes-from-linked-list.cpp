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
        // ListNode* new_head = new ListNode(0);
        // new_head->next = head;
//         ListNode* cur = new_head;
//         while(cur != NULL)
//         {
//             int sum=0;
            
//             //calculating the sum
//             //if sum becomes 0 then we skip all the nodes so far traversed
//             while(head != NULL)
//             {
//                 sum += head->val;
//                 if(sum == 0)
//                 {
//                    cur->next = head->next; 
//                 }
//                 head = head->next;
//             }
            
//             //moving on to the next node for performing the above operation 
//             //operation to check if there exists a sum that equals to zero
//             cur = cur->next;
//             if(cur != NULL)
//             {
//                 head = cur->next;
//             }
//         }
//         return new_head->next; 
//----------------         ----------------         ---------------------
        
// Algorithm

// -> Iterate LinkedList from left to right
// -> Process each accumulative value in this datastructure.       
//    (unordered_map<int,ListNode*>um) um[ac] = currentNode;
// -> Given a current accumulative value check if exists in our map (get previous 
//    element).
// -> If they exist um[ac]->next = currentNode->next, then delete intermediate  
//    nodes in our map between um[ac] and currentNode
        
        ListNode* root =new ListNode(0);
        root->next=head;
        unordered_map<int,ListNode*>um;
        um[0]=root;
        int ac=0;
        
        while(head!=NULL){
            ac+=head->val;
            
            //found value
            if(um.find(ac)!=um.end()){
                ListNode* prev= um[ac];
                ListNode* start= prev;
                
                //delete bad references
                int aux = ac;
                while(prev!=head){
                    prev=prev->next;
                    aux+=prev->val;
                    if(prev!=head)um.erase(aux);
                }
                
                start->next = head->next;
            }else{
                um[ac]= head;
            }
            
            head=head->next;
        }
        
        return root->next;      

    }
};
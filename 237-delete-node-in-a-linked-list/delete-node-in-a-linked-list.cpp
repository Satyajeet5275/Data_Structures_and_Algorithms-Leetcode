/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    void deleteNode(ListNode* node) {
        *node=*node->next;
        // ListNode* temp=node;
        // while(temp->next!=NULL)
        // {
        //     if(temp->next->next==NULL)
        //     {
        //         temp->val=temp->next->val;
        //         temp->next=NULL;
        //         break;
        //     }
        //     temp->val=temp->next->val;
        //     temp=temp->next;
        // }
        
    }
};
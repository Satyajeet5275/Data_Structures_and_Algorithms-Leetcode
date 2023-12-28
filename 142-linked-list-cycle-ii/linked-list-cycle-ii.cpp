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
    ListNode *detectCycle(ListNode *head) {
        if(!head || !head->next) return NULL;
        ListNode *slow=head;
        ListNode *fast=head->next;
        map<ListNode*,int> mp;
        while(fast!=NULL && fast->next!=NULL && fast->next->next!=NULL){
            // if(slow==fast) return true;
            mp[slow]++;
            if(mp[slow]>1) return slow;
            slow=slow->next;
            fast=fast->next->next;
        }
        return NULL;
    }
};
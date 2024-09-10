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
    ListNode* insertGreatestCommonDivisors(ListNode* head) {
        ListNode* tmp=head;
        ListNode* tmpnext=head->next;
        while(tmp && tmpnext){
            int gcd=__gcd(tmp->val,tmpnext->val);
            ListNode* mid=new ListNode(gcd);
            tmp->next=mid;
            mid->next=tmpnext;
            tmp=tmpnext;
            tmpnext=tmp->next;
        }
        return head;
    }
};
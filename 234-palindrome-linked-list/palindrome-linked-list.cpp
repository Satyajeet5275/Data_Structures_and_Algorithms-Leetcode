/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode                     (int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    bool isPalindrome(ListNode* head) {
        if(head==NULL || head->next==NULL) return true;
        ListNode *tmp=head;
        stack<int> st;
        while(tmp!=NULL){
            st.push(tmp->val);
            tmp=tmp->next;
        }
        tmp=head;
        while(!st.empty()){
            if(st.top()!=tmp->val) return false;
            tmp=tmp->next;
            st.pop();
        }
        return true;
    }
};
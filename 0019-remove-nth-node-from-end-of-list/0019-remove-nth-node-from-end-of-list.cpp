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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* temp=head;
        int s1=0;
        while(temp!=NULL)
        {
            temp=temp->next;
            s1++;
        }
        temp=head;
        int n1=s1-n;
        int i=1;
        // cout<<s1<<" - "<<n1;

        if(s1==2 && n==1)
        {
            head->next=NULL;
        }

        while(i<n1)
        {
            temp=temp->next;
            i++;
        }
        
        if(s1==n)
        {
            head=head->next;
            return head;
        }
        if(s1==1)
        {
            return NULL;
 
        }
        if(s1>2)
        temp->next=temp->next->next;
        return head;
    }
};
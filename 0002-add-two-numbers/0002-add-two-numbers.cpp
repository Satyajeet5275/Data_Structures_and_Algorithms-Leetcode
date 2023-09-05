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
    // ListNode* reverse(ListNode* n)
    // {
    //     ListNode* curr=n;
    //     ListNode* prev=NULL;
    //     ListNode* forwd=n->next;

    //     while(curr!=NULL)
    //     {
    //         forwd=curr->next;
    //         curr->next=prev;
    //         prev=curr;
    //         curr=forwd;
    //     }
    //     return prev;
    // }
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        // ListNode* n1=reverse(l1);
        // ListNode* n2=reverse(l2);
        ListNode* ans=new ListNode();
        ListNode* temp=new ListNode();
        int carry=0;
        bool b=1;
        while(l1!=NULL || l2!=NULL || carry>0)
        {
            int sum=0;
            if(l1!=NULL && l2!=NULL) sum=l1->val+l2->val;
            else if(l1!=NULL ) sum=l1->val;
            else if(l2!=NULL) sum=l2->val;

            int dig=0;
            if((sum+carry)<10)
            {
                dig=sum+carry;
                carry=0;
            }
            else
            {
                int lno=(sum+carry)%10;
                carry= (sum+carry)/10;
                dig=lno;
            }
            ListNode* newNode=new ListNode(dig);
            if(b)
            {
                ans=newNode;
                b=false;
            }
            temp->next=newNode;
            temp=newNode;
            if(l1!=NULL)   l1=l1->next;

            if(l2!=NULL)  l2=l2->next;
        }

        return ans;
    }
};
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
        vector<ListNode*> ans;
        ListNode* tmp=head;
        int n=0;
        while(tmp!=NULL)
        {
            n++;
            tmp=tmp->next;
        }
        tmp=head;
        if(k>n)
        {
            cout<<"Yes";
            int n1=n;
            while(n1>0)
            {
                ListNode* node=new ListNode(tmp->val);
                ans.push_back(node);
                tmp=tmp->next;
                n1--;
            }
            for(int i=0;i<(k-n);i++)
            {
                ans.push_back(NULL);
            }
        }
        else
        {
            int each=n/k;
            int rem=n%k;
            for(int i=0;i<k;i++)
            {
                int j=each;
                ListNode* node=new ListNode();
                ListNode* curr=node;
                
                while(tmp!=NULL && j>0)
                {
                    ListNode* dm=new ListNode(tmp->val);
                    curr->next=dm;
                    tmp=tmp->next;
                    curr=curr->next;
                    j--;
                }
                if(tmp!=NULL && rem>0)
                {
                    ListNode* dm=new ListNode(tmp->val);
                    curr->next=dm;
                    tmp=tmp->next;
                    rem--;
                }
                ans.push_back(node->next);
            }
        }
        return ans;
    }
};
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
    ListNode* getKthNode(ListNode* head, int k){
        ListNode* temp=head;
        while(k>1){
            if(temp==NULL) return NULL;
            temp=temp->next; 
            k--;
        }
        return temp;
    }
    ListNode* rotateRight(ListNode* head, int k) {
        if(!head || k==0) return head;
        ListNode *tail=head;
        int len=1;
        while(tail->next!=NULL){
            tail=tail->next;
            len++;
        }
        if(k%len==0) return head;
        if(k>len) k=k%len;
        tail->next=head;
        ListNode *kthNode=getKthNode(head,(len-k));
        head=kthNode->next;
        kthNode->next=NULL;
        return head;
    }
};
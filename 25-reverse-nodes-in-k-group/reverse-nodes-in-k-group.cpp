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
    ListNode* reverse(ListNode* head) {
        if(head==NULL){
            return head;
        }
        ListNode* current=head;
        ListNode* previous=NULL;
        while(current!=NULL){
            ListNode* temp = current->next;
            current->next=previous;
            previous=current;
            current=temp;
        }
        return previous;
    }
    ListNode* getKthNode(ListNode* head, int k){
        ListNode* temp=head;
        while(k>1){
            k--;
            if(temp!=NULL) temp=temp->next; 
        }
        return temp;
    }
    ListNode* reverseKGroup(ListNode* head, int k) {
        if(head==NULL) return NULL;
        ListNode *temp=head,*prevNode=NULL,*kthNode=NULL;
        while(temp!=NULL){
            kthNode=getKthNode(temp,k);
            if(kthNode==NULL){
                if(prevNode) prevNode->next=temp;
                break;
            }
            ListNode* nextNode=kthNode->next;
            kthNode->next=NULL;
            reverse(temp);
            if(head==temp) head=kthNode;
            else prevNode->next=kthNode;
            prevNode=temp;
            temp=nextNode;
        }
        return head;
    }
};
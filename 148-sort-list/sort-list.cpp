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
    ListNode* sortList(ListNode* head) {
        if(!head) return NULL;
        vector<int> arr;
        while(head!=NULL){
            arr.push_back(head->val);
            head=head->next;
        }
        sort(arr.begin(),arr.end());
        ListNode *start=new ListNode(arr[0]);
        ListNode *tmp=start;
        for(int i=1;i<arr.size();i++){
            ListNode *curr=new ListNode(arr[i]);
            tmp->next=curr;
            tmp=curr;
        }
        return start;
    }
    // ListNode* sortList(ListNode* head) {
    //     if(!head) return NULL;
    //     ListNode *start=new ListNode(head->val);
    //     ListNode *end=start;
    //     int mini=head->val,maxi=mini;
    //     head=head->next;
    //     while(head!=NULL){
    //         int data=head->val;
    //         ListNode *curr=new ListNode(data);
    //         if(data<=mini){
    //             mini=data;
    //             curr->next=start;
    //             start=curr;
    //         }
    //         else if(data>=maxi){
    //             maxi=data;
    //             end->next=curr;
    //             end=curr;
    //         }
    //         else{
    //             ListNode *tmp=start;
    //             while(tmp->next!=NULL && tmp->next->val<data){
    //                 tmp=tmp->next;
    //             }
    //             curr->next=tmp->next;
    //             tmp->next=curr;
    //         }
    //         head=head->next;
    //     }
    //     return start;
    // }
};
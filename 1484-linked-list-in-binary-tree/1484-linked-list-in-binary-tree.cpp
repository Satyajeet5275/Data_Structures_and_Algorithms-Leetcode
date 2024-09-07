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
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    ListNode* first;
    bool check(ListNode* head, TreeNode* root){
        if(!head) return true;
        if(!root) return false;
        bool nxt,curr=0;
        if(head->val==root->val){
            nxt=check(head->next,root->left) || check(head->next,root->right);
            if(nxt) return true;
        }
        if(head==first) curr=check(first,root->left) || check(first,root->right);
        return curr;
    }
    bool isSubPath(ListNode* head, TreeNode* root) {
        first=head;
        return check(head,root);
    }
};
/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};
*/

class Solution {
public:
    Node* connect(Node* root) {
        if(root==NULL) return NULL;
        queue<Node*> q;
        q.push(root);
        while(!q.empty()){
            int n=q.size();
            vector<Node*> tmp;
            for(int i=0;i<n;i++){
                Node* node=q.front();
                q.pop();
                if(i==n-1) node->next=NULL;
                else 
                {   Node *nextNode=q.front();
                    node->next=nextNode;
                }
                if(node->left) tmp.push_back(node->left);
                if(node->right) tmp.push_back(node->right);
            }
            for(int i=0;i<tmp.size();i++) q.push(tmp[i]);
        }
        return root;
    }
};
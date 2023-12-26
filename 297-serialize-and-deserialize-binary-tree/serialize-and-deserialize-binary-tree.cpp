/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Codec {
public:

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        if(root==NULL) return "";
        queue<TreeNode*> q;
        string res="";
        q.push(root);
        while(!q.empty()){
            TreeNode* root=q.front();
            q.pop();
            if(root==NULL) res+="#,";
            else{
                res.append(to_string(root->val)+",");
                q.push(root->left);
                q.push(root->right);
            }
        }
        return res;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        if(data.size()==0) return NULL;
        stringstream s(data);
        string str;
        getline(s,str,',');
        TreeNode* root=new TreeNode(stoi(str));
        queue<TreeNode*> q;
        q.push(root);
        while(!q.empty()){
            TreeNode* root=q.front();
            q.pop();
            
            getline(s,str,',');
            if(str=="#")    root->left=NULL;
            else{
                TreeNode* leftNode= new TreeNode(stoi(str));
                root->left=leftNode;
                q.push(leftNode);
            }

            getline(s,str,',');
            if(str=="#")    root->right=NULL;
            else{
                TreeNode* rightNode= new TreeNode(stoi(str));
                root->right=rightNode;
                q.push(rightNode);
            }
        }
        return root;
    }
};

// Your Codec object will be instantiated and called as such:
// Codec ser, deser;
// TreeNode* ans = deser.deserialize(ser.serialize(root));
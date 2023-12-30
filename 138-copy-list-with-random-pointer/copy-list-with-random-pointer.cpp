/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {
        map<Node*,Node*> mp;
        Node* temp=head;
        while(temp!=NULL){
            Node *copyNode=new Node(temp->val);
            mp[temp]=copyNode;
            temp=temp->next;
        }
        for(pair<Node*,Node*> it:mp){
            Node *org=it.first;
            Node *copy=it.second;
            copy->next=mp[org->next];
            copy->random=mp[org->random];
        }
        return mp[head];
    }
};
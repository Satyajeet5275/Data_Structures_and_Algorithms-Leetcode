class Solution {
public:
    ListNode* removeZeroSumSublists(ListNode* head) {
        vector<int> arr;
        while(head!=NULL){
            arr.push_back(head->val);
            head=head->next;
        }
        
        bool found = true;
        while(found) {
            found = false;
            int n = arr.size();
            for(int i = 0; i < n; i++){
                int sum = 0;
                for(int j = i; j < n; j++){
                    sum += arr[j];
                    if(sum == 0){
                        arr.erase(arr.begin() + i, arr.begin() + j + 1);
                        found = true;
                        break;
                    }
                }
                if(found) break;
            }
        }
        
        ListNode* dummy = new ListNode(0);
        ListNode* curr = dummy;
        for(auto x: arr) {
            curr->next = new ListNode(x);
            curr = curr->next;
        }
        
        return dummy->next;
    }
};

class Solution {
public:
    ListNode* removeZeroSumSublists(ListNode* head) {
        vector<int> arr;
        while(head!=NULL){
            arr.push_back(head->val);
            head=head->next;
        }
        bool found=true;
        while(found){
            found=false;
            int n=arr.size();
            for(int i=0;i<n;i++){
                int sum=0;
                for(int j=i;j<n;j++){
                    sum+=arr[j];
                    if(sum==0){
                        arr.erase(arr.begin() + i, arr.begin() + j + 1);
                        found=true;
                        break;
                    }
                }
                if(found) break;
            }        
        }                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                            
        ListNode* n1=new ListNode(0);
        head=n1;
        for(auto x:arr){
            head->next=new ListNode(x);
            head=head->next;
        }
        return n1->next; 
    }
};


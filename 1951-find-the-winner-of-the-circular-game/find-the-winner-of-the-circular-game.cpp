class Solution {
public:
    int findTheWinner(int n, int k) {
        queue<int> q;
        int backup=k;
        for(int i=1;i<=n;i++){
            q.push(i);
        }
        while(q.size()>1){
            if(k==1){
                k=backup;
                q.pop();
            }
            else{
                k--;
                int ele=q.front();
                q.pop();
                q.push(ele);
            }
        }
        return q.front();
    }
};
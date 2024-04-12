class Solution {
public:
    int trap(vector<int>& arr) {
        int n=arr.size();
        vector<int> prev(n),next(n);
        prev[0]=0;
        next[n-1]=0;
        for(int i=1;i<n;i++){
            prev[i]=max(prev[i-1],arr[i-1]);
        }
        for(int i=n-2;i>=0;i--){
            next[i]=max(next[i+1],arr[i+1]);
        }
        int ans=0;
        for(int i=0;i<n;i++){
            if(arr[i]<prev[i] && arr[i]<next[i]){
                ans+=(min(prev[i],next[i])-arr[i]);
            }
        }
        return ans;
    }
};
class Solution {
public:
    int maxScore(string s) {
        int n=s.length();
        int arr[n];
        if(s[0]=='0') arr[0]=1;
        else  arr[0]=-1;
        for(int i=1;i<n;i++){
            if(s[i]=='0') arr[i]=arr[i-1]+1;
            else arr[i]=arr[i-1]-1;
        }

        int maxi=INT_MIN,loc=0;
        for(int i=0;i<n;i++){
            if(maxi<arr[i]){
                maxi=arr[i];
                loc=i;
            }
        }
        int ans=0;
        for(int i=0;i<n;i++){
            if(i<=loc && s[i]=='0' && i<(n-1)) ans++;
            else if(i>loc && s[i]=='1' && i>0) ans++;
        }
        return ans;
    }
};
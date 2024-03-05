class Solution {
public:
    int minimumLength(string s) {
        int n=s.length();
        int start=0,end=n-1;
        while(start<end) {
            char startChar=s[start],endChar=s[end];
            if(startChar==endChar) {
                while(s[start]==startChar && start<=end){
                    n--;
                    start++;
                }
                while(s[end]==endChar && start<=end) {
                    n--;
                    end--;
                }
            }
            if(s[start]!=s[end]){ cout<<"Yes"; break;}
        }
        return n;
    }
};
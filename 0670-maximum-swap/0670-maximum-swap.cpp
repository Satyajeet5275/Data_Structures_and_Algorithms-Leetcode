class Solution {
public:
    int maximumSwap(int num) {
        string  s2 = to_string(num),s1=s2;
        int n = s1.size();
        sort(s2.rbegin(),s2.rend());
        int i=0;
        while(i<n && s1[i]==s2[i]){
            i++;
        }
        if(i==n)  return num;
        char ch=s2[i];
        int j=n-1;
        while(j>i && s1[j]!=s2[i]){
            j--;
        }
        swap(s1[i],s1[j]);
        return stoi(s1);
    }
};
class Solution {
public:
    int maximumLength(string s) {
        int n=s.length();
        if(n<3) return 0;
        unordered_map<string,int> mp;
        for(int i=0;i<n;){
            string str;
            int j=i;
            while(s[i]==s[j]){
                str+=s[j];
                j++;
            }
            i=j;
            mp[str]++;
        }
        int maxi=-1;
        for(auto x:mp){
            string str=x.first;
            int occur=x.second;
            int len=str.length();

            if(occur>=3) maxi=max(maxi,len);
            else if(len>=2){
                str.pop_back();
                if(occur==2) maxi=max(maxi,len-1);
                else if(occur==1 && mp.count(str)>=1) maxi=max(maxi,len-1);
                else if(len>2) maxi=max(maxi,len-2);
            }
        }
        return maxi;
    }
};
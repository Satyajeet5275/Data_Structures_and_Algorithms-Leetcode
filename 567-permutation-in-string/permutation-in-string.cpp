class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        // do{
        //     if(s1==s2 || s2.find(s1)!=string::npos) return true;
        // }while(next_permutation(s1.begin(),s1.end()));
        int n1=s1.size(),n2=s2.size();
        if(n1>n2) return false;
        map<char,int> mp,win;
        for(auto x: s1)  mp[x]++;

        for(int i=0;i<n2;++i){
            win[s2[i]]++;
            if(i>=n1){
                win[s2[i-n1]]--;
                if(win[s2[i-n1]]==0) win.erase(s2[i-n1]);
            } 
            if(win==mp) return true;
        }
        return false;
    }
};
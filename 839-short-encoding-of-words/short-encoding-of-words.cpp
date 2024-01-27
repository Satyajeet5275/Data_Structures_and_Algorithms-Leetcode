class Solution {
public:
    static bool compair(string s1,string s2){
        if(s1.size()==s2.size()) return s1<s2;
        return s1.size()<s2.size();
    }
    int minimumLengthEncoding(vector<string>& wd) {
        sort(wd.begin(),wd.end(),compair);
        int n=wd.size();
        for(int i=0;i<n-1;i++){
            string small=wd[i];
            for(int j=i+1;j<n;j++){
                // cout<<small<<" = "<<small.length()<<endl;
                // cout<<wd[j]<<" = "<<wd[j].length()<<"->"<<j<<endl;
                // cout<<wd[j].length()-small.length()<<" "<<wd[j][wd[j].length()-small.length()]<<endl<<endl;
                string big=wd[j];
                string sub=big.substr(big.size()-small.length(),small.length());
                if(sub==small) {
                    wd.erase(wd.begin()+i);
                    i--;
                    n--;
                    break;
                }
            }
        }
        int ans=wd.size();
        for(auto x:wd){
            ans+=x.length();
        }
        return ans;
    }
};
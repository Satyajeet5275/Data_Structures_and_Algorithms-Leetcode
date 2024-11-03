class Solution {
public:
    bool rotateString(string s, string goal) {
        string tmp=s;
        for(int i=0;i<s.size();i++){
            if(tmp==goal) return true;
            tmp=tmp[s.size()-1]+tmp.substr(0,s.size()-1);
            // cout<<tmp<<endl;
        }
        return false;
    }
};
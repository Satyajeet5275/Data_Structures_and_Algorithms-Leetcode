class Solution {
public:
    bool makeEqual(vector<string>& words) {
        int n=words.size(),totalChars=0;
        if(n<=1) return true;
        for(string str:words){
            totalChars+=str.length();
        }
        if(totalChars%n!=0) return false;
        map<char,int> mp;
        for(string str:words){
            for(char ch:str){
                mp[ch]++;
            }
        }
        for(pair<char,int> x:mp){
            if(x.second%n!=0) return false;
        }
        return true;
    }
};
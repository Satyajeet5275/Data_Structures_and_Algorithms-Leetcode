class Solution {
public:
    bool makeEqual(vector<string>& words) {
        int n=words.size(),totalChars=0;
        if(n<=1) return true;
        map<char,int> mp;
        for(string str:words){
            totalChars+=str.length();
            for(char ch:str){
                mp[ch]++;
            }
        }
        if(totalChars%n!=0) return false;
        // for(string str:words){
            
        // }
        for(pair<char,int> x:mp){
            if(x.second%n!=0) return false;
        }
        return true;
    }
};
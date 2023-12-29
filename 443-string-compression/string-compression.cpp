class Solution {
public:
    int compress(vector<char>& chars) {
        int ind=0,occur=1;
        char curr=chars[0];
        for(int i=1;i<=chars.size();i++){
           if(i==chars.size() || curr!=chars[i]){
                if(occur==1)    chars[ind++]=curr;
                else{
                    chars[ind++]=curr;
                    string dig=to_string(occur);
                    for(char ch:dig)    chars[ind++]=ch;
                }
                occur=1;
                if(i!=chars.size()) curr=chars[i];
           }
           else occur++;
        }  
        return ind;
    }
};
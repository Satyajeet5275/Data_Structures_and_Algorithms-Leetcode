class Solution {
public:
    int countSeniors(vector<string>& det) {
        int count=0;
        for(auto x:det){
           if((x[11]=='6' && x[12]>'0') || x[11]>'6'){
             count++;
             cout<<x<<endl;
           }
        }
        return count;
    }
};
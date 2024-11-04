class Solution {
public:
    string compressedString(string wd) {
        int n=wd.length();
        string s="";
        
        for(int i=0;i<n;i++){
            int c=1,j=i+1;
            while(j<n && wd[i]==wd[j]){
                j++;
                c++;
            }
            while(c>9){
                s.push_back('9');
                s.push_back(wd[i]);
                c-=9;
            }
            if(c>0) { s+=to_string(c);
                      s.push_back(wd[i]);        }
            i=j-1;
        }
        return s;
    }
};
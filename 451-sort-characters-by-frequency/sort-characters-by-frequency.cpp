class Solution {
public:
    static bool compair(pair<int,char> a,pair<int,char> b) {
        if(a.first==b.first) return a.second<b.second;
        return a.first>b.first;
    }
    string frequencySort(string s) {
        vector<pair<int,char>> arr(62,{0,'a'});
        for(auto x:s){
            if(x>='a'){
                arr[x-'a'].first++;
                arr[x-'a'].second=x;
            }
            else if(x>='A'){
                arr[26+x-'A'].first++;
                arr[26+x-'A'].second=x;
            }
            else{
                arr[52+x-'0'].first++;
                arr[52+x-'0'].second=x;
            }
        }
        sort(arr.begin(),arr.end(),compair);
        string ans;
        for(auto x:arr){
            if(x.first>0){
                string tmp=string(x.first,x.second);
                ans+=tmp;
            }
        }
        return ans;
    }
};
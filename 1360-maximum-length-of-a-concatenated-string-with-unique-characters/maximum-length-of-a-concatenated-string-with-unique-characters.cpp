class Solution {
public:
    int solve(int i,string& ans,vector<string>& arr, map<char,int> mp){
        if(i>=arr.size()) return ans.size();

        int pick=0,nonPick=solve(i+1,ans,arr,mp);
        bool flag=true;
        for(int j=0;j<arr[i].size();j++){
            if(mp[arr[i][j]]>=1) flag=false;
            else mp[arr[i][j]]++;
        }
        if(flag){
            string tmp=ans;
            ans+=arr[i];
            pick=solve(i+1,ans,arr,mp);
            ans=tmp;
        }
        return max(pick,nonPick);
    }
    int maxLength(vector<string>& arr) {
        map<char,int> mp;
        string ans="";
        return solve(0,ans,arr,mp);
    }
};
class Solution {
public:
    int minDeletions(string s) {
        map<int,int> mp;
        for(int i=0;i<s.length();i++)
        {
            mp[s[i]]++;
        }
        vector<int> occ;
        for(pair x:mp)
        {
            occ.push_back(x.second);
        }
        sort(occ.rbegin(),occ.rend());
        
        int change=0;
        for(int i=0;i<occ.size()-1;i++)
        {
            int j=i+1;
            while(j<occ.size() && occ[i]==occ[j] && occ[i]!=0)
            {
                occ[j]--;
                change++;
                j++;
            }
        }
        return change;
    }
};
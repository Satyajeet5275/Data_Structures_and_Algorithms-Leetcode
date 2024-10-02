class Solution {
public:
    vector<int> arrayRankTransform(vector<int>& arr) {
        vector<pair<int,int>> tmp;
        for(int i=0;i<arr.size();i++){
            tmp.push_back({arr[i],i});
        }
        vector<int> ans(arr.size());
        sort(tmp.begin(),tmp.end());
        for(int i=0;i<tmp.size();i++){
            int ele=tmp[i].first;
            int rank=tmp[i].second;
            if(i!=0 && tmp[i-1].first==ele){
                ans[rank]=ans[tmp[i-1].second];
            }
            else if(i!=0) ans[rank]=ans[tmp[i-1].second]+1;
            else ans[rank]=i+1;
        }
        return ans;
    }
};
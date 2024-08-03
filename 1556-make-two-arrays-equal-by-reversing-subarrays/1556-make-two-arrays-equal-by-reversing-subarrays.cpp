class Solution {
public:
    bool canBeEqual(vector<int>& target, vector<int>& arr) {
        sort(target.begin(),target.end());
        sort(arr.begin(),arr.end());
        int n1=target.size(),n2=arr.size();
        if(n1!=n2) return 0;
        int i=0;
        for(auto x:target){
            int y=arr[i++];
            if(x!=y) return 0;
        }
        return 1;
    }
};
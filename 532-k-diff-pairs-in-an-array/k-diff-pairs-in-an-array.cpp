class Solution {
public:
    int findPairs(vector<int>& arr, int k) {
        // sort(arr.begin(),arr.end());
        set<pair<int,int>> st;
        map<int,int> mp;
        for(int x:arr) mp[x]++;
        int n=arr.size();
        for(int i=0;i<n;i++){
                int num=arr[i]-(-k);
                if((num==arr[i] && mp[num]>=2) || (num!=arr[i] && mp[num]>=1)) {
                        st.insert({arr[i],num});
                        cout<<arr[i]<<" "<<num<<endl;           
                }
                // num=arr[i]-(k);
                // if(mp[num]>=1) st.insert({arr[i],num});
        }
        return st.size();
    }
};
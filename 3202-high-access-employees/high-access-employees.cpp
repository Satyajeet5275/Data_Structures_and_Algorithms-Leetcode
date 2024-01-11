class Solution {
public:
    vector<string> findHighAccessEmployees(vector<vector<string>>& at) {
        map<string,vector<int>> mp;
        vector<string> ans;
        int n=at.size();
        for(int i=0;i<n;i++){
            int time=stoi(at[i][1]);
            mp[at[i][0]].push_back(time);
        }
        for(auto emp:mp){
            vector<int> arr=emp.second;
            sort(arr.begin(),arr.end());
            int n1=arr.size();
            if(n1>=3){
                for(int i=0;i<n1-2;i++){
                    if((arr[i]+99)>=arr[i+2]){
                        ans.push_back(emp.first);
                        break;
                    }
                }
            }
        }
        return ans;
    }
};
class Solution {
public:
    int minimumArrayLength(vector<int>& arr) {
        sort(arr.begin(),arr.end());
        int n=arr.size();
        int freq=1;
        int i=0;
        while(i<n-1 && arr[i]==arr[i+1]){
            i++;
            freq++;
        }
        int mini=INT_MAX;
        for(int i=freq;i<n;i++){
            int res=arr[i]%arr[0];
            if(res==0) continue;
            mini=min(mini,res);
        }        
        if(mini<arr[i]) return 1;
        return ceil((double)freq/(double)2);
    }
};
// int minimumArrayLength(vector<int>& arr) {
//         sort(arr.begin(),arr.end());
//         int z=0;
//         int no=arr[0],reps=0;
//         while(arr.size()>1){
//             int last=arr.size()-1;
//             int last1=arr.size()-2;
//             bool flag=false;
//             while(last1>0 && arr[last]==arr[last1]){
//                 last1--;
//                 flag=true;
//             }
//             if(last1==0){
//                 no=arr[0];
//                 reps=arr.size();
//             }
//             int res=arr[last1]%arr[last];
//             // cout<<arr[arr.size()-2]<<" "<<arr[arr.size()-1]<<endl;
//             if(res==0) {
//                 z++;
//                 arr.pop_back();
//                 arr.pop_back();
//                 continue;
//             }
//             if(flag){
//                 arr.pop_back();
//                 arr[last1]=res;
//                 continue;
//             }
//             arr.pop_back();
//             arr.pop_back();
//             arr.push_back(res);
//         }
//         int mini=INT_MAX;
//         for(int i=reps;i<arr.size();i++){
//             if(arr[i]%no==0) continue;
//             mini=min(mini,arr[i]%no);
//         }
//         if(mini<arr[0]) return 1;
//         return arr.size()+z;
//     }
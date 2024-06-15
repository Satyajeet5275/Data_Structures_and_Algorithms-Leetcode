class Solution {
public:
    int findMaximizedCapital(int k, int w, vector<int>& pro, vector<int>& cap) {
        //  priority_queue<pair<int,int>> pq;
         int n=pro.size();
         priority_queue<int> pq;
         vector<vector<int>> arr;
         for(int i=0;i<n;i++){
            // pq.push({pro[i],cap[i]});
            arr.push_back({cap[i],pro[i]});
         }
         sort(arr.begin(),arr.end());
         int i=0;
         while(k>0){
            while(i<n && w>=arr[i][0]){
                pq.push(arr[i][1]);
                i++;
            }
            if(!pq.empty()){ w+=pq.top();
            pq.pop();}
            k--;
         }
        //  int income=w;
        //  priority_queue<pair<int,int>> tmp;
        //  while(k>0 && !pq.empty() ){
        //      auto x=pq.top();
        //      pq.pop();
        //      int req=x.second;
        //      int op=x.first;
        //      while(req>income && !pq.empty()){
        //         tmp.push({op,req});
        //         x=pq.top();
        //         pq.pop();
        //         req=x.second;
        //         op=x.first;
        //      }
        //     cout<<endl;
        //     if(income>=req){
        //      income+=op;
        //     }
        //     k--;
        //      while(!tmp.empty()){
        //         x=tmp.top();
        //         tmp.pop();
        //         req=x.second;
        //         op=x.first;
        //         cout<<op<<" "<<req;
        //         pq.push({op,req});
        //      }
        //  }
         return w;
    }
};
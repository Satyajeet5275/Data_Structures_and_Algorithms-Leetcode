class DataStream {
public:
    queue<int> q;
    map<int,int> mp;
    int val,n;
    DataStream(int value, int k) {
        val=value;
        n=k;
    }
    
    bool consec(int num) {
        if(q.size()==n){
            if(mp[q.front()]==1) mp.erase(q.front());
            else mp[q.front()]--;
            q.pop();
            q.push(num);
            mp[num]++;
            if(mp.size()==1 && mp[val]!=0) return true;
        }
        else{
            q.push(num);
            mp[num]++;
            if(q.size()==n && mp.size()==1 && mp[val]!=0) return true;
        }
        return false;
    }
};

/**
 * Your DataStream object will be instantiated and called as such:
 * DataStream* obj = new DataStream(value, k);
 * bool param_1 = obj->consec(num);
 */
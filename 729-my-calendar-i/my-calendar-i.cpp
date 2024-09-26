class MyCalendar {
public:
    // unordered_set<int> st;
    vector<pair<int,int>> arr;
    MyCalendar() {
        arr.clear();
    }
    bool book(int start, int end) {
        // for(int i=start;i<end;i++){
        //     if(st.find(i)!=st.end()) return false;
        // }
        // for(int i=start;i<end;i++){
        //     st.insert(i);
        // }
        // return true;
        for(auto x:arr){
            if(start<x.second && end>x.first) return false;
        }
        arr.push_back({start,end});
        return true;
    }
};

/**
 * Your MyCalendar object will be instantiated and called as such:
 * MyCalendar* obj = new MyCalendar();
 * bool param_1 = obj->book(start,end);
 */
class Solution {
public:
    set<pair<int,int>> st;
    int r,c;
  
    Solution(int m, int n) {
        r=m;
        c=n;
    }
    
    vector<int> flip() {
        if(st.size()==(r*c)) return {-1,-1};
        while(true){
            int x=rand()%r+0;
            int y=rand()%c+0;
            if(st.find({x,y})==st.end()){
                st.insert({x,y});
                return {x,y};
            }
        }
        return {-1,-1};
    }
    
    void reset() {
        st.clear();
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(m, n);
 * vector<int> param_1 = obj->flip();
 * obj->reset();
 */
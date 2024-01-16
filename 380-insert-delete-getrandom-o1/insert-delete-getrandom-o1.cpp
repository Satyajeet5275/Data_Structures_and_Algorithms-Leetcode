class RandomizedSet {
public:
    vector<int> st;
    int n=0;
    RandomizedSet() {
        n=0;
    }
    
    bool insert(int val) {
        if(find(st.begin(),st.end(),val)!=st.end()) return false;
        st.push_back(val);
        n++;
        return true;
    }
    
    bool remove(int val) {
        if(find(st.begin(),st.end(),val)==st.end()) return false;
        st.erase(find(st.begin(),st.end(),val));
        n--;
        return true;
    }
    
    int getRandom() {
        int range = (n-1)-0+1;
        int loc=rand()%range+0;
        return st[loc];
    }
};

/**
 * Your RandomizedSet object will be instantiated and called as such:
 * RandomizedSet* obj = new RandomizedSet();
 * bool param_1 = obj->insert(val);
 * bool param_2 = obj->remove(val);
 * int param_3 = obj->getRandom();
 */
class RLEIterator {
public:
    vector<int> arr;
    int ind,size;
    RLEIterator(vector<int>& encoding) {
        arr=encoding;
        ind=0;
        size=encoding.size();
    }
    
    int next(int n) {
        if(ind>=size) return -1;
        if(n<=arr[ind]){
            arr[ind]-=n;
            cout<<arr[ind]<<" "<<arr[ind+1]<<" "<<n<<endl;
            return arr[ind+1];
        }
        else{
            while(ind+2<size && n>arr[ind] && n>0){
                int nn=n;
                n-=arr[ind];
                arr[ind]-=nn;
                if(arr[ind]<=0) ind+=2;
            } 
            if(n>arr[ind]){
                ind+=2;
                return -1;
            }
            if(n!=0) arr[ind]-=n;
            int i=ind;
            if(arr[ind]==0) ind+=2;
            // cout<<arr[ind]<<" "<<arr[ind+1]<<" "<<n<<endl;
            return arr[i+1];
        }
    }
};

/**
 * Your RLEIterator object will be instantiated and called as such:
 * RLEIterator* obj = new RLEIterator(encoding);
 * int param_1 = obj->next(n);
 */
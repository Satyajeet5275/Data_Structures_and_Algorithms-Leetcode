class Solution {
public:
    void moveZeroes(vector<int>& arr) {
        int ind=0;
        int n=arr.size();
	    for(int i=0;i<n;i++){
	        if(arr[i]!=0){
	            arr[ind]=arr[i];
	            ind++;
	        }
	    }
	    for(int i=ind;i<n;i++)    arr[i]=0;
    }
};
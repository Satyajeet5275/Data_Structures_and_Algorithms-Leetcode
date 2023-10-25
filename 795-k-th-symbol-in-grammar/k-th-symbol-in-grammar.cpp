//replace each occurrence of 0 with 01, and each occurrence of 1 with 10.
//see the pattern
// | is used as mid point
//N=1 [0]
//N=2 [0 | 1]  //first half is copy of N-1 and second half is complement of N-1
//N=3 [0 1 | 1 0]
//N=4 [0 1 1 0 | 1 0 0 1]
//...
class Solution {
public:
    int kthGrammar(int N, int K) {
	
        if(N==1 && K==1) return 0;
        
        int mid=pow(2,N-1)/2;
        
        if(K<=mid){
            return kthGrammar(N-1, K);
        }else{
            return !(kthGrammar(N-1, K-mid));
        }
		
    }
};
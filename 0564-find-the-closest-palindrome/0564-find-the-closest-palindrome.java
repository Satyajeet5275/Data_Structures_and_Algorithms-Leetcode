class Solution {
    public String nearestPalindromic(String n) {
        int len=n.length()/2;
        boolean even=(n.length()%2==0);
        if(even) len--;
        long left=Long.parseLong(n.substring(0,len+1));
        List<Long> arr=new ArrayList<>();
        arr.add(getPalindrome(left,even));
        arr.add(getPalindrome(left-1,even));
        arr.add(getPalindrome(left+1,even));
        arr.add((long)Math.pow(10,n.length()-1)-1);
        arr.add((long)Math.pow(10,n.length())+1);

        long diff=Integer.MAX_VALUE,num=Long.parseLong(n),ans=0;
        for(long x:arr){
            if(x==num) continue;
            long curr=Math.abs(num-x);
            if(diff>curr){
                diff=curr;
                ans=x;
            }
            else if(diff==curr){
                ans=Math.min(ans,x);
            }
        }
        return String.valueOf(ans);
    }
    private long getPalindrome(long left,boolean even){
        long res=left;
        if(!even) left/=10;
        while(left>0){
            res=(res*10)+(left%10);
            left/=10;
        }
        return res;
    }
}
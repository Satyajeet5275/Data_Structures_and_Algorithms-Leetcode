class Solution {
public:
    //Brute Force
    // int candy(vector<int>& rating) {
    //     int n=rating.size();
    //     vector<int> distrib(n,1);
    //     int totalCandies=n;
    //     for(int i=1;i<n;i++)
    //     {
    //       while(rating[i]>rating[i-1] && distrib[i]<=distrib[i-1]) {
    //         distrib[i]=distrib[i]+1;
    //         totalCandies++;
    //       } 
    //     }
    //     for(int i=n-2;i>=0;i--)
    //     {
    //       while(rating[i]>rating[i+1] && distrib[i]<=distrib[i+1])         {
    //         distrib[i]=distrib[i]+1;
    //         totalCandies++;
    //       }
    //     }
    //     for(int x:distrib) cout<<x<<"  ";
    //     return totalCandies;
    // }
     int candy(vector<int>& rating) {
        int n=rating.size();
        vector<int> left(n,1);
        vector<int> right(n,1);

        for(int i=1;i<n;i++)
        {
          if(rating[i]>rating[i-1] && left[i]<=left[i-1]) {
            left[i]=left[i-1]+1;
          } 
        }
        for(int i=n-2;i>=0;i--)
        {
          if(rating[i]>rating[i+1] && right[i]<=right[i+1])         {
            right[i]=right[i+1]+1;
          }
        }
        int totalCandies=0;
        for(int i=0;i<left.size();i++)
        {
          totalCandies+=max(left[i],right[i]);
        }
        return totalCandies;
    }
};

// 87 1 2 3
// 1 1 2 3
// 2 1 1 1


// 1,2,87,87,87,2,1
// 1 2 3 1 1 1 1
// 1 1 1 1 3 2 1
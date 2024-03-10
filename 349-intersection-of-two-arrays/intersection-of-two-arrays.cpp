class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        int n1=nums1.size(),n2=nums2.size();
        map<int,bool> m;
        vector<int> v;
        
        for(int i=0;i<n1;i++)
        {
            m[nums1[i]]=true;
        }
        
        for(int i=0;i<n2;i++)
        {
            if(m[nums2[i]])
            {
                v.push_back(nums2[i]);
                m[nums2[i]]=false;
            }
        }
        return v;
    }
};
//    nums1         nums2
// [1,2,3,4]     [2,3,7,8,2]

// m[]=  1-true,2-false,3-true,4-true;
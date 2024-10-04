class Solution {
public:
    long long dividePlayers(vector<int>& skill) {
        int n=skill.size();
        sort(skill.begin(),skill.end());
        int prevSum=skill[0]+skill[n-1];
        long long ans=skill[0]*skill[n-1];
        int i=1,j=n-2;
        while(i<j){
            if(skill[i]+skill[j]!=prevSum) return -1;
            else{
                ans+=skill[i]*skill[j];
                i++;
                j--;
            }
        }
        return ans;
    }
};

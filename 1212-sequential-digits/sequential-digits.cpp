class Solution {
public:
    vector<int> sequentialDigits(int low, int high) {
        vector<int> ans;
        string s = "123456789";
        int n = s.size();
        for(int len = 2; len <= n; len++){
            for(int si = 0; si <= n - len; si++){
                string temp = s.substr(si, len);
                int possi = stoi(temp);

                if(possi >= low && possi <= high)
                    ans.push_back(possi);            
            }
        }  
        return ans;    
    }
};
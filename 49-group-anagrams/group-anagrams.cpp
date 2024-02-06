class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        int n = strs.size();
        vector<vector<string>> ans;
        unordered_map<string, vector<string>> mp; 

        for (auto& it : strs) {
            string sortedStr = it;
            sort(sortedStr.begin(), sortedStr.end());
            mp[sortedStr].push_back(it); 
        }

        for (auto& pair : mp) {
            ans.push_back
            
            (pair.second);  
        }

        return ans;
    }
};
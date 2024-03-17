class Solution {
public:
    int minimumDeletions(string word, int k) {
    vector<int> freq(26, 0);
    int minFreq = INT_MAX, deleted = 0, ans = word.size();
    for(auto c: word) freq[c-'a']++;
    sort(freq.begin(), freq.end());
    for(int i = 0; i < freq.size(); ++i){
        minFreq = freq[i];
        int res = deleted;
        for(int j = freq.size()-1; j > i; --j){
            if(freq[j] - minFreq <= k) break;
            res += freq[j] - minFreq - k;
        }
        ans = min(ans, res);
        deleted += freq[i];
    }
    return ans;
}
};
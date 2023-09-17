class Solution {
public:
    int sumIndicesWithKSetBits(vector<int>& numbers, int k) {
        
        vector<int> bitCounts;
        int result = 0;
        for(int i = 0; i < numbers.size(); i++)
        {
            int temp = i;
            int count = 0;
            while(temp > 0)
            {
                count += temp & 1;
                temp >>= 1;        
            }
            bitCounts.push_back(count);
        }
        
        for(int i = 0; i < bitCounts.size(); i++)
        {
            if(bitCounts[i] == k)
                result += numbers[i];
        }
        
        return result;
    }
};

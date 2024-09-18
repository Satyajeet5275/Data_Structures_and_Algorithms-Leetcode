#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

class Solution {
public:
    static bool compare(const string& s1, const string& s2) {
        return s1 + s2 > s2 + s1;
    }

    string largestNumber(vector<int>& nums) {
        vector<string> arr;
        for (int x : nums) {
            arr.push_back(to_string(x));
        }

        sort(arr.begin(), arr.end(), compare);

        if (arr[0] == "0") {
            return "0";
        }
        string result;
        for (const string& s : arr) {
            result += s;
        }

        return result;
    }
};

#include <string>
#include <algorithm>

using namespace std;

class Solution {
public:
    string reverseStr(string s, int k) {
        for (int start = 0, len = s.length(); start < len; start += (2 * k)){
            int end = min(start + k, len);
            reverse(s.begin() + start, s.begin() + end);
        }
        return s;
    }
};
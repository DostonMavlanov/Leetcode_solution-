#include <vector>
#include <string>

using namespace std;

class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        int numberOfStrings = strs.size(); 
    
        for (int charIndex = 0; charIndex < strs[0].size(); ++charIndex) {
            for (int strIndex = 1; strIndex < numberOfStrings; ++strIndex) {
                if (strs[strIndex].size() <= charIndex || strs[strIndex][charIndex] != strs[0][charIndex]) {
                    return strs[0].substr(0, charIndex);
                }
            }
        }
        return strs[0];
    }
};


#include <vector>
#include <string>
#include <cstring>
#include <functional>

using namespace std;

class Solution {
public:
    vector<vector<string>> partition(string s) {
        int length = s.size();
        bool palindromeTable[length][length];
        memset(palindromeTable, true, sizeof(palindromeTable));

        for (int i = length - 1; i >= 0; --i){
            for (int j = i + 1; j < length; ++j){
                palindromeTable[i][j] = (s[i] == s[j]) && palindromeTable[i + 1][j - 1];
            }
        }

        vector<vector<string>> result;
        vector<string> tmpPartition;
        
        function<void(int)> depthFirstSearch = [&](int start) {
            if (start == length) {
                result.push_back(tmpPartition);
                return;
            }

            for (int end = start; end < length; ++end){
                if (palindromeTable[start][end]){
                    tmpPartition.push_back(s.substr(start, end - start + 1));
                    depthFirstSearch(end + 1);
                    tmpPartition.pop_back();
                }
            }
        };
        depthFirstSearch(0);
        return result;
    }
};
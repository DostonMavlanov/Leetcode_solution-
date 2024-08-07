#include <string>

using namespace std;

class Solution {
public:
    int strStr(string haystack, string needle) {
       int haystack_len = haystack.size();
       int needle_len = needle.size();

        for (int i = 0; i < (haystack_len - needle_len + 1); ++i){
            if (haystack.substr(i, needle_len) == needle){
                return i;
            }
        }
        return -1;
    }
};


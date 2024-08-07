#include <string>
#include <stack>

using namespace std;

class Solution {
public:
    bool isValid(string s) {
        stack<char> res;
        for (char c: s){
            if (c == '('){
                res.push(')');
            }
            else if (c == '['){
                res.push(']');
            }
            else if (c == '{'){
                res.push('}');
            }
            else{
                if (res.empty()){
                    return false;
                }
                if (res.top() != c){
                    return false;
                }
                res.pop();
            }
        }
        return res.empty();
    }
};
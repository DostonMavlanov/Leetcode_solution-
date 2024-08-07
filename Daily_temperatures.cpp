#include <vector>
#include <stack>

using namespace std;

class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        int n = temperatures.size();
        vector<int> daysToWait(n);
        stack<int> indexStack; 

        for (int i = 0; i < n; ++i) {
            while (!indexStack.empty() && temperatures[indexStack.top()] < temperatures[i]) {
                int previousDayIndex = indexStack.top(); 
                daysToWait[previousDayIndex] = i - previousDayIndex; 
                indexStack.pop(); 
            }
            indexStack.push(i);
        }
        return daysToWait;
    }
};
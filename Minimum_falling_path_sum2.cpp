#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& a) {
        int m = a.size();
        int n = a[0].size();
        vector<int> dp(a[0].begin(), a[0].end());
        for (int i = 1; i < m; ++i){
            vector<int> t(n, 0);
            for (int j = 0; j < n; j++){
                t[j] = min({dp[max(0, j - 1)], dp[j], dp[min(n - 1, j + 1)]}) + a[i][j]; 
            }
            dp = t;
        }
        return *min_element(dp.begin(), dp.end());
    }
};
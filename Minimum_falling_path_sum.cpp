#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& a) {
        const int n = a.size();
        vector<vector<int>> minSum(n, vector<int>(n));
        for (int j = 0; j < n; j++) {
            minSum[0][j] = a[0][j];
        }
        for (int i = 1; i < n; i++) {
            for (int j = 0; j < n; j++) {
                int minPrev = minSum[i - 1][j];
                if (j - 1 >= 0) {
                    minPrev = min(minPrev, minSum[i - 1][j - 1]);
                }
                if (j + 1 < n) {
                    minPrev = min(minPrev, minSum[i - 1][j + 1]);
                }
                minSum[i][j] = minPrev + a[i][j];
            }
        }
        int ans = minSum[n - 1][0];
        for (int v : minSum[n - 1]) {
            ans = min(ans, v);
        }
        return ans;
    }
};
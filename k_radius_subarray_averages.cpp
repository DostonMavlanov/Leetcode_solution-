#include <vector>

using namespace std;

class Solution {
public:
    vector<int> getAverages(vector<int>& nums, int k) {
        int n = nums.size();
        long int sum = 0;
        vector<int> ans(n, -1);

        for (int i = 0; i < n; ++i){
            sum += nums[i];
            if (i >= 2 * k){
                ans[i - k] = sum / (2 *k + 1);
                sum -= nums[i - k * 2];
            }
        }
        return ans;
    }
};
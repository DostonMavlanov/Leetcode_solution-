#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    vector<int> answerQueries(vector<int>& nums, vector<int>& queries) {
        vector<int> result;
        sort(nums.begin(), nums.end());
        for (int i = 1; i < nums.size(); ++i){
            nums[i] += nums[i - 1];
        }

        for (int tmp: queries){
            result.push_back(upper_bound(nums.begin(), nums.end(), tmp) - nums.begin());
        }
        return result;
    }
};
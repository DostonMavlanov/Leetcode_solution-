#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        vector<int> ans;
        ans.push_back(nums[0]);
        int len = nums.size();      
        
        for (int i = 1; i < len; ++i){
            if (nums[i] > ans.back()){
                ans.push_back(nums[i]);
            }else{
                int low = lower_bound(ans.begin(), ans.end(), nums[i]) - ans.begin();
                ans[low] = nums[i];
            }

        }
        return static_cast<int>(ans.size());
    }
};
#include <vector>
#include <stack>

using namespace std;

class Solution {
public:
    vector<int> asteroidCollision(vector<int>& nums) {
        vector<int> stack;
        for (int asteroid : nums){
            if (asteroid > 0){
                stack.push_back(asteroid);
            }else{
                while (!stack.empty() && stack.back() > 0 && stack.back() < -asteroid){
                    stack.pop_back();                   
                }
                if (!stack.empty() && stack.back() == -asteroid){
                    stack.pop_back();
                }else if (stack.empty() || stack.back() < 0){
                    stack.push_back(asteroid);
                }
            }
        }
        return stack;
    }
};

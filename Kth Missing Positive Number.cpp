#include <vector>

using namespace std;

class Solution {
public:
    int findKthPositive(vector<int>& arr, int k) {
        if (arr[0] > k){
            return k;
        }

        int left = 0;
        int right = arr.size();

        while (left < right){
            int mid = left + (right - left) / 2;
            if (arr[mid] - mid - 1 >= k){
                right = mid;
            }else{
                left = mid + 1;
            }
        }

        return arr[left - 1] + k - (arr[left - 1] - (left - 1) - 1);
    }
};
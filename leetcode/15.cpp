#include <algorithm>
#include <vector>

using namespace std;

class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int> > ans{};
        sort(nums.begin(), nums.end());
        for ( size_t idx{}; idx < nums.size() && nums[idx] <= 0; ++idx ) {
            int sum{-nums[idx]};
            size_t left{idx + 1}, right{nums.size() - 1};
            for ( ; left < right; ) {
                int curSum{nums[left] + nums[right]};
                if ( curSum == sum ) {
                    ans.push_back({nums[idx], nums[left], nums[right]});
                    for ( int origInt{nums[left]}; left < right && nums[++left] == origInt; );
                    for ( int origInt{nums[right]}; right > left && nums[--right] == origInt; );
                } else if ( curSum > sum ) {
                    --right;
                } else {
                    ++left;
                }
            }
        }
        return ans;
    }
};

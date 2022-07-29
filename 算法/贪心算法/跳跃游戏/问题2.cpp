#include <vector>

using namespace std;

class Solution {
public:
    int jump(vector<int> &nums) {
        int curDistance = 0;  // 当前覆盖的最远距离下标
        int ans = 0;          // 记录走的最大步数
        int nextDistance = 0; // 下一步覆盖的最远距离下标
        for (int i = 0; i < nums.size() -
                            1; i++) {                                                  // 注意这里是小于nums.size() - 1，这是关键所在
            nextDistance = max(nums[i] + i, nextDistance); // 更新下一步覆盖的最远距离下标
            if (i == curDistance) {                               // 遇到当前覆盖的最远距离下标
                curDistance = nextDistance; // 更新当前覆盖的最远距离下标
                ans++;
            }
        }
        return ans;
    }
};
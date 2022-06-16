#include <vector>
#include <algorithm>
using namespace std;

//含重复元素

class Solution
{
private:
    vector<vector<int>> result;
    vector<int> path;
    void backtracking(vector<int> &nums, int startIndex, vector<bool> &used);

public:
    vector<vector<int>> subsetsWithDup(vector<int> &nums);
};

void Solution::backtracking(vector<int> &nums, int startIndex, vector<bool> &used)
{
    result.push_back(path);
    for (int i = startIndex; i < nums.size(); i++)
    {
        // used[i - 1] == true，说明同一树枝candidates[i - 1]使用过
        // used[i - 1] == false，说明同一树层candidates[i - 1]使用过
        // 而我们要对同一树层使用过的元素进行跳过
        if (i > 0 && nums[i] == nums[i - 1] && used[i - 1] == false)
        {
            continue;
        }
        path.push_back(nums[i]);
        used[i] = true;
        backtracking(nums, i + 1, used);
        used[i] = false;
        path.pop_back();
    }
}

vector<vector<int>> Solution::subsetsWithDup(vector<int> &nums)
{
    result.clear();
    path.clear();
    vector<bool> used(nums.size(), false);
    sort(nums.begin(), nums.end()); // 去重需要排序
    backtracking(nums, 0, used);
    return result;
}

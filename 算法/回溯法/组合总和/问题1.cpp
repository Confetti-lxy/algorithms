#include <vector>
#include <algorithm>
using namespace std;

//给定一个无重复元素的数组 candidates 和一个目标数 target,找出 candidates 中所有可以使数字和为 target 的组合
// candidates 中的数字可以无限制重复被选取

class Solution
{
private:
    vector<vector<int>> result;
    vector<int> path;
    void backtracking(vector<int> &candidates, int target, int sum, int startIndex);

public:
    vector<vector<int>> combinationSum(vector<int> &candidates, int target);
};

void Solution::backtracking(vector<int> &candidates, int target, int sum, int startIndex)
{
    if (sum == target)
    {
        result.push_back(path);
        return;
    }

    // 如果 sum + candidates[i] > target 就终止遍历
    for (int i = startIndex; i < candidates.size() && sum + candidates[i] <= target; i++)
    {
        sum += candidates[i];
        path.push_back(candidates[i]);
        backtracking(candidates, target, sum, i);
        sum -= candidates[i];
        path.pop_back();
    }
}

vector<vector<int>> Solution::combinationSum(vector<int> &candidates, int target)
{
    result.clear();
    path.clear();
    sort(candidates.begin(), candidates.end()); // 需要排序
    backtracking(candidates, target, 0, 0);
    return result;
}
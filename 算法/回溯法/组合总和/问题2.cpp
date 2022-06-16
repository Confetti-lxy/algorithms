#include <vector>
#include <algorithm>
using namespace std;

//给定一个数组 candidates 和一个目标数 target,找出 candidates 中所有可以使数字和为 target 的组合
// candidates 中的每个数字在每个组合中只能使用一次

class Solution
{
private:
    vector<vector<int>> result;
    vector<int> path;
    void backtracking(vector<int> &candidates, int target, int sum, int startIndex, vector<bool> &used);

public:
    vector<vector<int>> combinationSum2(vector<int> &candidates, int target);
};

void Solution::backtracking(vector<int> &candidates, int target, int sum, int startIndex, vector<bool> &used)
{
    if (sum == target)
    {
        result.push_back(path);
        return;
    }
    for (int i = startIndex; i < candidates.size() && sum + candidates[i] <= target; i++)
    {
        // used[i - 1] == true，说明同一树枝candidates[i - 1]使用过
        // used[i - 1] == false，说明同一树层candidates[i - 1]使用过
        // 要对同一树层使用过的元素进行跳过
        if (i > 0 && candidates[i] == candidates[i - 1] && used[i - 1] == false)
        {
            continue;
        }
        sum += candidates[i];
        path.push_back(candidates[i]);
        used[i] = true;
        backtracking(candidates, target, sum, i + 1, used); // 和39.组合总和的区别1，这里是i+1，每个数字在每个组合中只能使用一次
        used[i] = false;
        sum -= candidates[i];
        path.pop_back();
    }
}

vector<vector<int>> Solution::combinationSum2(vector<int> &candidates, int target)
{
    vector<bool> used(candidates.size(), false);
    path.clear();
    result.clear();
    // 首先把给candidates排序，让其相同的元素都挨在一起。
    sort(candidates.begin(), candidates.end());
    backtracking(candidates, target, 0, 0, used);
    return result;
}
#include <vector>
#include <algorithm>

using namespace std;

//有重复数字

class Solution {
private:
    vector <vector<int>> result;
    vector<int> path;

    void backtracking(vector<int> &nums, vector<bool> &used);

public:
    vector <vector<int>> permuteUnique(vector<int> &nums);
};

void Solution::backtracking(vector<int> &nums, vector<bool> &used) {
    // 此时说明找到了一组
    if (path.size() == nums.size()) {
        result.push_back(path);
        return;
    }
    for (int i = 0; i < nums.size(); i++) {
        // used[i - 1] == true，说明同一树枝nums[i - 1]使用过
        // used[i - 1] == false，说明同一树层nums[i - 1]使用过
        // 如果同一树层nums[i - 1]使用过则直接跳过
        if (i > 0 && nums[i] == nums[i - 1] && used[i - 1] == false) {
            continue;
        }
        if (used[i] == false) {
            used[i] = true;
            path.push_back(nums[i]);
            backtracking(nums, used);
            path.pop_back();
            used[i] = false;
        }
    }
}

vector <vector<int>> Solution::permuteUnique(vector<int> &nums) {
    result.clear();
    path.clear();
    sort(nums.begin(), nums.end()); // 排序
    vector<bool> used(nums.size(), false);
    backtracking(nums, used);
    return result;
}
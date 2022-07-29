#include <vector>

using namespace std;

//没有重复数字

class Solution {
private:
    vector <vector<int>> result;
    vector<int> path;

    void backtracking(vector<int> &nums, vector<bool> &used);

public:
    vector <vector<int>> permute(vector<int> &nums);
};

void Solution::backtracking(vector<int> &nums, vector<bool> &used) {
    // 此时说明找到了一组
    if (path.size() == nums.size()) {
        result.push_back(path);
        return;
    }
    for (int i = 0; i < nums.size(); i++) {
        if (used[i] == true)
            continue; // path里已经收录的元素，直接跳过
        used[i] = true;
        path.push_back(nums[i]);
        backtracking(nums, used);
        path.pop_back();
        used[i] = false;
    }
}

vector <vector<int>> Solution::permute(vector<int> &nums) {
    result.clear();
    path.clear();
    vector<bool> used(nums.size(), false);
    backtracking(nums, used);
    return result;
}
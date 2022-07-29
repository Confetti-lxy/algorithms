#include <vector>

using namespace std;

//不含重复元素

class Solution {
private:
    vector <vector<int>> result;
    vector<int> path;

    void backtracking(vector<int> &nums, int startIndex);

public:
    vector <vector<int>> subsets(vector<int> &nums);
};

void Solution::backtracking(vector<int> &nums, int startIndex) {
    result.push_back(path); // 收集子集，要放在终止添加的上面，否则会漏掉自己
    if (startIndex >= nums.size()) { // 终止条件可以不加
        return;
    }
    for (int i = startIndex; i < nums.size(); i++) {
        path.push_back(nums[i]);
        backtracking(nums, i + 1);
        path.pop_back();
    }
}

vector <vector<int>> Solution::subsets(vector<int> &nums) {
    result.clear();
    path.clear();
    backtracking(nums, 0);
    return result;
}
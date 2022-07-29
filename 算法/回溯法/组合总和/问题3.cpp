#include <vector>

using namespace std;

//找出所有相加之和为 n 的 k 个数的组合.组合中只允许含有 1 - 9 的正整数,并且每种组合中不存在重复的数字

class Solution {
private:
    vector <vector<int>> result; // 存放结果集
    vector<int> path;           // 符合条件的结果
    void backtracking(int targetSum, int k, int sum, int startIndex);

public:
    vector <vector<int>> combinationSum3(int k, int n);
};

void Solution::backtracking(int targetSum, int k, int sum, int startIndex) {
    // targetSum：目标和，也就是题目中的n。
    // k：题目中要求k个数的集合。
    // sum：已经收集的元素的总和，也就是path里元素的总和。
    // startIndex：下一层for循环搜索的起始位置。
    if (path.size() == k) {
        if (sum == targetSum)
            result.push_back(path);
        return; // 如果path.size() == k 但sum != targetSum 直接返回
    }
    for (int i = startIndex; i <= 9; i++) {
        sum += i;                               // 处理
        path.push_back(i);                      // 处理
        backtracking(targetSum, k, sum, i + 1); // 注意i+1调整startIndex
        sum -= i;                               // 回溯
        path.pop_back();                        // 回溯
    }
}

vector <vector<int>> Solution::combinationSum3(int k, int n) {
    result.clear(); // 可以不加
    path.clear();   // 可以不加
    backtracking(n, k, 0, 1);
    return result;
}
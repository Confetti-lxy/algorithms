#include <vector>
using namespace std;

// 记住我们的index只能从1开始
// 树状数组 Binary Indexed Tree
// 实现单点修改&区间查询

class Binary_Indexed_Tree
{
private:
    vector<int> bit, values;    // bit:和数组, values:原数组
    int lowbit(int x);          //求二进制位
    void add(int loc, int val); // loc是指树状数组中的位置

public:
    Binary_Indexed_Tree(vector<int> &nums);
    int getSum(int loc);               // loc是指树状数组中的位置
    void update(int loc, int val);     // loc是指树状数组中的位置
    int sumRange(int left, int right); // left, right均是指树状数组中的位置
};

int Binary_Indexed_Tree::lowbit(int x)
{
    return x & -x;
}

void Binary_Indexed_Tree::add(int loc, int val)
{
    while (loc < bit.size())
    {
        bit[loc] += val;
        loc += lowbit(loc);
    }
}

Binary_Indexed_Tree::Binary_Indexed_Tree(vector<int> &nums)
{
    bit.resize(nums.size() + 1);
    values.resize(0);
    for (int i = 0; i < nums.size(); i++)
    {
        add(i + 1, nums[i]);
        values.push_back(nums[i]);
    }
}

int Binary_Indexed_Tree::getSum(int loc)
{
    int ans = 0;
    while (loc >= 1)
    {
        ans += bit[loc];
        loc -= lowbit(loc);
    }
    return ans;
}

void Binary_Indexed_Tree::update(int loc, int val)
{
    add(loc, val - values[loc - 1]);
    values[loc - 1] = val;
}

int Binary_Indexed_Tree::sumRange(int left, int right)
{
    return getSum(right) - getSum(left - 1);
}

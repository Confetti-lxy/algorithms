#include <vector>
using namespace std;

//记住我们的index只能从1开始
// 树状数组 Binary Indexed Tree

class Binary_Indexed_Tree
{
private:
    vector<int> bit, values; // bit:和数组, values:原数组
    int lowbit(int x);
    void add(int loc, int val);

public:
    Binary_Indexed_Tree(vector<int> &nums);
    int getSum(int loc);
    void update(int loc, int val);
    int sumRange(int left, int right);
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
    add(loc + 1, val - values[loc]);
    values[loc] = val;
}

int Binary_Indexed_Tree::sumRange(int left, int right)
{
    return getSum(right + 1) - getSum(left);
}

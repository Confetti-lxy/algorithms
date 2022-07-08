#include <vector>
using namespace std;

// 记住我们的index只能从1开始
// 树状数组 Binary Indexed Tree
// 实现区间修改&单点查询

class Binary_Indexed_Tree
{
private:
    vector<int> delta, values;  // delta:差分数组, values:原数组
    int lowbit(int x);          //求二进制位
    void add(int loc, int val); // loc是指树状数组中的位置

public:
    Binary_Indexed_Tree(vector<int> &nums);
    void update(int left, int right, int val); // left,right是指树状数组中的位置
    int ask(int loc);                          // loc是指树状数组中的位置
};

int Binary_Indexed_Tree::lowbit(int x)
{
    return x & -x;
}

void Binary_Indexed_Tree::add(int loc, int val)
{
    while (loc < delta.size())
    {
        delta[loc] += val;
        loc += lowbit(loc);
    }
}

Binary_Indexed_Tree::Binary_Indexed_Tree(vector<int> &nums)
{
    delta.resize(nums.size() + 1, 0);
    values = nums;
}

void Binary_Indexed_Tree::update(int left, int right, int val)
{
    add(left, val);
    add(right + 1, -val);
}

int Binary_Indexed_Tree::ask(int loc)
{
    int ans = values[loc - 1];
    while (loc >= 1)
    {
        ans += delta[loc];
        loc -= lowbit(loc);
    }
    return ans;
}
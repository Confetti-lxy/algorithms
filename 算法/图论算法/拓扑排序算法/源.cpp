#include <vector>
#include <iostream>
#include <algorithm>
#include <climits>
#include <queue>
using namespace std;

class Solution
{
private:
    vector<vector<int>> distances;
    vector<int> ans, in_degree;

public:
    void initialize(int n, int m);
    void Topological_sorting();
    void print();
};

int main()
{
    int n, m;
    cin >> n >> m;
    Solution solution;
    solution.initialize(n, m);
    solution.Topological_sorting();
    solution.print();
}

void Solution::initialize(int n, int m)
{
    distances.clear();
    distances.resize(n + 1);
    ans.clear();
    in_degree.clear();
    in_degree.resize(n + 1, 0);
    int x = 0, y = 0;
    for (int i = 0; i < m; i++)
    {
        cin >> x >> y;
        distances[x].push_back(y);
        in_degree[y]++;
    }
    return;
}

void Solution::Topological_sorting()
{
    int count = 0, n = distances.size();
    queue<int> que;
    for (int i = 1; i < n; i++)
    {
        if (in_degree[i] == 0)
        {
            que.push(i);
        }
    }
    while (!que.empty())
    {
        auto it = que.front();
        que.pop();
        ans.push_back(it);
        int size = distances[it].size();
        for (int i = 0; i < size; i++)
        {
            int x = distances[it][i];
            in_degree[x]--;
            if (in_degree[x] == 0)
            {
                que.push(x);
            }
        }
        distances[it].clear();
        count++;
    }
    if (count != n - 1)
    {
        ans.clear();
    }
}

void Solution::print()
{
    if (ans.size() == 0)
    {
        cout << "该图无法进行拓扑排序" << endl;
    }
    else
    {
        for (int i = 0; i < ans.size(); i++)
        {
            cout << ans[i] << " ";
        }
        cout << endl;
    }
    return;
}
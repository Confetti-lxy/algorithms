#include <string.h>
#include <iostream>
#include <queue>
#include <climits>
using namespace std;

class Solution
{
private:
    vector<vector<int>> distances;
    vector<int> flow, pre;
    int BFS(int src, int des);

public:
    void initialize(int n, int m);
    int maxflow(int src, int des);
};

int main()
{
    int n = 0, m = 0;
    cin >> n >> m;
    int a, b;
    cin >> a >> b;
    Solution solution;
    solution.initialize(n, m);
    cout << "-----------------------------------------------------" << endl;
    int ans = solution.maxflow(a, b);
    cout << "-----------------------------------------------------" << endl;
    cout << ans << endl;
}

void Solution::initialize(int n, int m)
{
    distances.clear();
    distances.resize(n + 1, vector<int>(n + 1, 0));
    flow.clear();
    flow.resize(n + 1, INT_MAX);
    int x = 0, y = 0, z = 0;
    for (int i = 0; i < m; i++)
    {
        cin >> x >> y >> z;
        distances[x][y] = z;
    }
}

int Solution::BFS(int src, int des)
{
    int n = distances.size();
    queue<int> que;
    pre.clear();
    pre.resize(n, -1);
    pre[src] = 0;
    flow[src] = INT_MAX;
    que.push(src);
    while (!que.empty())
    {
        auto index = que.front();
        que.pop();
        if (index == des)
        {
            break;
        }
        for (int i = 1; i < n; i++)
        {
            if (i != src && distances[index][i] > 0 && pre[i] == -1)
            {
                pre[i] = index;
                flow[i] = min(distances[index][i], flow[index]);
                que.push(i);
            }
        }
    }
    return (pre[des] == -1) ? -1 : flow[des];
}

int Solution::maxflow(int src, int des)
{
    int sumflow = 0;
    int increasement = BFS(src, des);
    cout << increasement << " ";
    while (increasement != -1)
    {
        int k = des;
        while (k != src)
        {
            int last = pre[k];
            distances[last][k] -= increasement;
            distances[k][last] += increasement;
            k = last;
        }
        sumflow += increasement;
        increasement = BFS(src, des);
        cout << increasement << " "; //查看每次增广路的值
    }
    cout << endl;
    return sumflow;
}

//一些可用的实验数据：

/*
8 12
1 8
1 2 5
1 3 6
2 3 2
2 5 4
2 4 3
3 5 3
4 5 1
4 6 4
4 7 5
5 7 4
7 8 5
6 8 3


7 11
1 2 22
1 4 10
1 5 56
2 3 6
2 4 34
2 7 68
3 4 9
4 6 11
5 6 100
4 7 15
6 7 45
 */
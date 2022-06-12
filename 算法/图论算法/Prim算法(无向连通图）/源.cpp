#include <vector>
#include <iostream>
#include <algorithm>
#include <climits>
#include <queue>
using namespace std;

struct edge
{
    int to, length;
    edge(int to, int length) : to(to), length(length) {}
    bool operator<(edge const &other) const
    {
        return length > other.length;
    }
};

struct point //储存答案的变量，可不用
{
    int number, distance;
    point(int number, int distance) : number(number), distance(distance) {}
};

class Solution
{
private:
    vector<vector<edge>> distances; //邻接表
    vector<int> book;               //判断数组
    vector<point> points;           //储存答案的数组

public:
    void initialize(int n, int m);
    void Prim();
    void print();
};

int main()
{
    int n = 0, m = 0;
    cin >> n >> m;
    Solution solution;
    solution.initialize(n, m);
    solution.Prim();
    solution.print();
}

void Solution::initialize(int n, int m)
{
    distances.clear();
    distances.resize(n + 1);
    book.clear();
    book.resize(n + 1, 0);
    points.clear();
    points.resize(n + 1, point(0, INT_MAX));
    points[1] = point(1, 0);
    int x = 0, y = 0, z = 0;
    for (int i = 0; i < m; i++)
    {
        cin >> x >> y >> z;
        distances[x].push_back(edge(y, z));
        distances[y].push_back(edge(x, z));
    }
    return;
}

void Solution::Prim()
{
    int count = 1, n = points.size() - 1;
    priority_queue<edge> que;
    que.push(edge(1, 0));
    while (count != n && !que.empty())
    {
        auto it = que.top();
        que.pop();
        if (book[it.to] == 1)
        {
            continue;
        }
        book[it.to] = 1;
        count++;
        int size = distances[it.to].size();
        for (int i = 0; i < size; i++)
        {
            int x = distances[it.to][i].length, y = distances[it.to][i].to;
            if (book[y] == 0)
            {
                if (x < points[y].distance)
                {
                    points[y].distance = x;
                    points[y].number = it.to;
                }
                que.push(distances[it.to][i]);
            }
        }
    }
    return;
}

void Solution::print()
{
    for (int i = 1; i < points.size(); i++)
    {
        cout << i << " " << points[i].number << " " << points[i].distance << endl;
    }
    return;
}
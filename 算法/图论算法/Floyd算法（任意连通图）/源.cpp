#include <iostream>
#include <vector>
#include <climits>
#include <algorithm>
using namespace std;

class Solution
{
private:
    vector<vector<int>> distances;
    vector<vector<int>> paths;

public:
    void initialize(int n, int m);
    void Floyd();
    void distance();
    void path();
};

int main()
{
    int n = 0, m = 0;
    cin >> n >> m;
    Solution solution;
    solution.initialize(n, m);
    solution.Floyd();
    cout << "------------------------------------------------------------------------" << endl;
    solution.distance();
    cout << "------------------------------------------------------------------------" << endl;
    solution.path();
}

void Solution::initialize(int n, int m)
{
    distances.clear();
    distances.resize(n + 1, vector<int>(n + 1, INT_MAX));
    paths.clear();
    paths.resize(n + 1, vector<int>(n + 1, 0));
    for (int i = 1; i <= n; i++)
    {
        distances[i][i] = 0;
    }
    int x = 0, y = 0, z = 0;
    for (int i = 0; i < m; i++)
    {
        cin >> x >> y >> z;
        distances[x][y] = z;
        distances[y][x] = z;
    }
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            if (i != j && distances[i][j] < INT_MAX)
            {
                paths[i][j] = j;
            }
            else
            {
                paths[i][j] = -1;
            }
        }
    }
    return;
}

void Solution::Floyd()
{
    int n = distances.size() - 1;
    for (int k = 1; k <= n; k++)
    {
        for (int i = 1; i <= n; i++)
        {
            for (int j = 1; j <= n; j++)
            {
                int select = (distances[i][k] == INT_MAX || distances[k][j] == INT_MAX) ? INT_MAX : distances[i][k] + distances[k][j];
                if (distances[i][j] > select)
                {
                    distances[i][j] = select;
                    paths[i][j] = paths[i][k];
                }
            }
        }
    }
    return;
}

void Solution::distance()
{
    for (int i = 1; i < distances.size(); i++)
    {
        for (int j = 1; j < distances[i].size(); j++)
        {
            cout << distances[i][j] << " ";
        }
        cout << endl;
    }
    return;
}

void Solution::path()
{
    for (int i = 1; i < paths.size(); i++)
    {
        for (int j = 1; j < paths[i].size(); j++)
        {
            cout << paths[i][j] << " ";
        }
        cout << endl;
    }
    return;
}

//一组可用的实验数据：

/*

7 12
1 2 12
1 6 16
1 7 14
2 3 10
2 6 7
3 4 3
3 5 5
3 6 6
4 5 4
5 6 2
5 7 8
6 7 9

*/
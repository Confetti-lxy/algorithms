#include <iostream>
#include <queue>
#include <vector>
#include <stdio.h>
using namespace std;

class Solution
{
private:
    vector<vector<int>> distances;
    vector<int> paths, book;
    int max_matches;
    bool FindAugPath(int loc);

public:
    void initialize(int row, int col, int m);
    void Hungary_match();
    void print();
};

int main()
{
    int row = 0, col = 0, m = 0;
    cin >> row >> col >> m;
    Solution solution;
    solution.initialize(row, col, m);
    solution.Hungary_match();
    solution.print();
}

void Solution::initialize(int row, int col, int m)
{
    distances.clear();
    distances.resize(row + 1, vector<int>(col + 1, 0));
    paths.clear();
    paths.resize(col + 1, -1);
    book.clear();
    book.resize(col + 1, 0);
    max_matches = 0;
    int x = 0, y = 0;
    for (int i = 0; i < m; i++)
    {
        cin >> x >> y;
        distances[x][y] = 1;
    }
    return;
}

bool Solution::FindAugPath(int loc)
{
    for (int i = 1; i < distances[loc].size(); i++)
    {
        if (distances[loc][i] == 1 && book[i] == 0)
        {
            book[i] = 1;
            if (paths[i] == -1 || FindAugPath(paths[i]))
            {
                paths[i] = loc;
                return true;
            }
        }
    }
    return false;
}

void Solution::Hungary_match()
{
    int row = distances.size(), col = distances[0].size();
    for (int i = 1; i < row; i++)
    {
        int ans = FindAugPath(i);
        if (ans == true)
        {
            max_matches++;
        }
        book.clear();
        book.resize(col, 0);
    }
    return;
}

void Solution::print()
{
    cout << "-----------------------------------------------------" << endl;
    cout << max_matches << endl;
    cout << "-----------------------------------------------------" << endl;
    for (int i = 1; i < paths.size(); i++)
    {
        cout << paths[i] << "      " << i << endl;
    }
    return;
}

//一组可用的用例：

/*
4 4 7
1 1
1 2
1 3
2 1
2 3
3 1
4 1
*/
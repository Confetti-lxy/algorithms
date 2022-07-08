#include <iostream>
#include <vector>

using namespace std;

struct edge
{
    int to, weight, pre;
    // to是终点，weight是权值，pre是相同起点的上一个点的位置

    edge() : to(0), weight(0), pre(-1) {}

    edge(int to, int weight, int pre) : to(to), weight(weight), pre(pre) {}
};

class Chained_forward_star
{
private:
    vector<edge> edeges; //边集数组
    vector<int> end;     // end[i]表示以 i 为起点的最后一条边的编号
    int cnt = 0;

    void init(int n);                   // n表示顶点数，从1开始算起
    void add_edge(int x, int y, int w); // x,y,w分别表示起点，终点，权值
public:
    void initialize(int n, int m); // n，m分别表示点数和边数

    void read(); //对链式前向星进行输出，便于调试
};

void Chained_forward_star::init(int n)
{
    cnt = 0;
    end.resize(n + 1, -1);
}

void Chained_forward_star::add_edge(int x, int y, int w)
{
    edeges.push_back(edge(y, w, end[x]));
    end[x] = cnt;
    cnt++;
}

void Chained_forward_star::initialize(int n, int m)
{
    init(n);
    int x = 0, y = 0, w = 0;
    for (int i = 0; i < m; i++)
    {
        cin >> x >> y >> w;
        add_edge(x, y, w);
    }
}

void Chained_forward_star::read()
{
    for (int i = 1; i < end.size(); i++)
    {
        cout << i << endl;
        int loc = end[i];
        while (loc != -1)
        {
            cout << i << " " << edeges[loc].to << " " << edeges[loc].weight << endl;
            loc = edeges[loc].pre;
        }
        cout << endl;
    }
}

/*
一组可用的样例:
5 7
1 2 1
2 3 2
3 4 3
1 3 4
4 1 5
1 5 6
4 5 7
*/
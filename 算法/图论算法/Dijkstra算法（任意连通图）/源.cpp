#include <bit/stdc++.h>

using namespace std;

struct edge {
    int to, length;

    edge(int to, int length) : to(to), length(length) {}
};

struct point {
    int number, distance;

    point(int number, int distance) : number(number), distance(distance) {}

    bool operator<(const point &p) const {
        return distance > p.distance;
    }
};

class Solution {
private:
    vector <vector<edge>> edges;
    vector<int> dis, vis;

public:
    void initialize(int n, int m);

    vector<int> dijkstra(int x);
};

int main() {
    int n = 0, x = 0, m = 0;
    cin >> n >> m >> x;
    Solution solution;
    solution.initialize(n, m);
    vector<int> A = solution.dijkstra(x);
    for (int i = 1; i < A.size(); i++) {
        cout << A[i] << " ";
    }
    cout << endl;
}

void Solution::initialize(int n, int m) {
    edges.clear();
    edges.resize(n + 1);
    int x = 0, y = 0, z = 0;
    for (int i = 0; i < m; i++) {
        cin >> x >> y >> z;
        edges[x].push_back(edge(y, z));
        edges[y].push_back(edge(x, z));
    }
    return;
}

vector<int> Solution::dijkstra(int x) {
    dis.clear();
    dis.resize(edges.size(), INT_MAX);
    dis[x] = 0;
    vis.clear();
    vis.resize(edges.size(), 0);
    priority_queue <point> que;
    que.push(point(x, 0));
    while (!que.empty()) {
        auto it = que.top();
        que.pop();
        int val = it.number;
        if (vis[val] == 1) {
            continue;
        }
        vis[val] = 1;
        for (int i = 0; i < edges[val].size(); i++) {
            int end = edges[val][i].to;
            if (vis[end] == 0) {
                if (dis[end] > dis[val] + edges[val][i].length) {
                    dis[end] = edges[val][i].length + dis[val];
                    que.push(point(end, dis[end]));
                }
            }
        }
    }
    return dis;
}
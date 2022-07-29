#include <bit/stdc++.h>

using namespace std;

struct edge {
    int start, end, length;

    edge(int a, int b, int length) : start(a), end(b), length(length) {}

    bool operator<(edge const &other) const {
        return length > other.length;
    }
};

class unionFinder {
private:
    vector<int> pre;
    vector<int> rank;

public:
    void initialize(int n);

    int find(int x);

    bool isSame(int x, int y);

    bool join(int x, int y);
};

class Solution : public unionFinder {
private:
    vector <vector<int>> distances; //邻接表
    vector <edge> points;           //储存答案的数组
public:
    void init(int n, int m);

    int Kruskal();

    void print();
};

int main() {
    int n = 0, m = 0;
    cin >> n >> m;
    Solution solution;
    solution.initialize(n);
    solution.init(n, m);
    cout << solution.Kruskal() << endl;
    solution.print();
}

void unionFinder::initialize(int n) {
    pre.resize(n + 1);
    rank.resize(n + 1);
    for (int i = 0; i < n; i++) {
        pre[i] = i;
        rank[i] = 1;
    }
}

int unionFinder::find(int x) {
    if (pre[x] == x)
        return x;
    return pre[x] = find(pre[x]);
}

bool unionFinder::isSame(int x, int y) {
    return find(x) == find(y);
}

bool unionFinder::join(int x, int y) {
    x = find(x);
    y = find(y);
    if (x == y)
        return false;
    if (rank[x] > rank[y]) {
        pre[y] = x;
    } else if (rank[x] < rank[y]) {
        pre[x] = y;
    } else {
        pre[x] = y;
        rank[y]++;
    }
    return true;
}

void Solution::init(int n, int m) {
    distances.resize(n + 1, vector<int>(n + 1, -1));
    int x = 0, y = 0, z = 0;
    for (int i = 0; i < m; i++) {
        cin >> x >> y >> z;
        distances[x][y] = z;
        distances[y][x] = z;
    }
    return;
}

int Solution::Kruskal() {
    priority_queue <edge> que;
    for (int i = 1; i < distances.size(); i++) {
        for (int j = i + 1; j < distances[i].size(); j++) {
            if (distances[i][j] != -1) {
                que.push(edge(i, j, distances[i][j]));
            }
        }
    }
    int count = 1, res = 0;
    while (count < distances.size() && !que.empty()) {
        auto it = que.top();
        que.pop();
        int start_loc = it.start, end_loc = it.end, loc_val = it.length;
        if (!isSame(start_loc, end_loc)) {
            join(start_loc, end_loc);
            points.push_back(edge(start_loc, end_loc, loc_val));
            res += loc_val;
            count++;
        }
    }
    return res;
}

void Solution::print() {
    for (int i = 0; i < points.size(); i++) {
        cout << points[i].start << " " << points[i].end << " " << points[i].length << endl;
    }
    return;
}
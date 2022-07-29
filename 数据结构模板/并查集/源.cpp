#include <iostream>
#include <vector>

using namespace std;

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

void unionFinder::initialize(int n) {
    pre.resize(n);
    rank.resize(n);
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
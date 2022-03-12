#include <iostream>
#include <vector>
#include <cmath>
#include <climits>
#include <algorithm>

using namespace std;

struct path {
    int from, to, speed;
    path(int from,int to, int speed) :from(from), to(to), speed(speed) {};
    path() = default;
    bool operator<(const path& rhs) const {
        return speed < rhs.speed;
    }
};

const int maxN = 100001;
vector<pair<int, int>> optimal;
path edgeList[maxN];
int parent[maxN];
int N, M;
int MIN = INT_MAX, MAX = 0;

void init() {
    for (auto i = 0; i < N; i++) {
        parent[i] = i;
    }
}

int Find(int v) {
    if (v == parent[v])
        return v;
    return  parent[v] = Find(parent[v]);
}

void Union(int a, int b) {
    a = Find(a);
    b = Find(b);
    if (a != b)
        parent[b] = a;
}

bool mysort(pair<int,int> a, pair<int, int> b) {
    if (a.second - a.first > b.second - b.first) {
        return false;
    }
    else if (a.second - a.first < b.second - b.first) {
        return true;
    }
    else {
        return a.first < b.first;
    }
    
}

bool kruskal(int i) {
    init();
    int counter = N;
    
    for (auto j = i; j < M; j++) {
        if (counter == 1) {
            optimal.push_back({ MIN, MAX });
            break;
        }
        auto x = edgeList[j];
        int from = edgeList[j].from;
        int to = edgeList[j].to;
        if (Find(from) != Find(to)) {
            Union(from, to);
            MAX = max(MAX, x.speed);
            MIN = min(MIN, x.speed);
            counter--;
        }
    }

    if (counter != 1) return false;
    return true;
}

int main() {
    cin >> N >> M;
    for (auto i = 0; i < M; i++) {
        int  from, to, speed;
        cin >> from >> to >> speed;
        path temp = path(from, to, speed);
        edgeList[i] = temp;
    }

    for (auto i = 0; i < M; i++) {
        if(!kruskal(i)) break;
        MAX = 0;
        MIN = INT_MAX;
    }

    sort(optimal.begin(), optimal.end(), mysort);

    cout << optimal[0].first << " " << optimal[0].second;
    return 0;
}
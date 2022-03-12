/*#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>

using namespace std;

struct path {
    long long  effort;
    long long from, to;
    long long gain;
    long long id;
    path(long long effort, long long from, long long  to, long long gain, long long id) :effort(effort), from(from), to(to), gain(gain), id(id) {};
    path() = default;
};

const int maxN = 100001;
path edgeList[maxN];
long parent[maxN];
long long N, M;

void init() {
    for (auto i = 0; i < N; i++) {
        parent[i] = i;
    }
}

long Find(long long v) {
    if (v == parent[v])
        return v;
    return  parent[v] = Find(parent[v]);
}

void Union(long long a, long long b) {
    a = Find(a);
    b = Find(b);
    if (a != b)
        parent[b] = a;
}

bool mysort(path a, path b) {
    if (a.effort == b.effort) {
        return a.gain > b.gain;
    }
    else {
        return a.effort < b.effort;
    }
}

void kruskal() {
    init();
    vector<long long>ans;
    sort(edgeList, edgeList + M, mysort);
    for (auto i = 0; i < M; i++) {
        if (ans.size() == N - 1) break;
        long long from = edgeList[i].from;
        long long to = edgeList[i].to;
        if (Find(from) != Find(to)) {
            Union(from, to);
            ans.push_back(edgeList[i].id);
        }
    }
    for (auto x : ans) {
        cout << x << endl;
    } 
}

int main() {
    cin >> N >> M;
    for (auto i = 0; i < M; i++) {
        long long  from, to, effort, gain;
        cin >> from >> to >> effort >> gain;
        path temp = path(effort, from, to, gain, i + 1);
        edgeList[i] = temp;
    }
    kruskal();

    return 0;
}*/
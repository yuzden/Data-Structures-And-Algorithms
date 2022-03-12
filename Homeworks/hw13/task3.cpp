#include <iostream>
#include <vector>
#include <queue>
#include <string>


using namespace std;

const int maxN = 100000;
int degree[maxN];
vector<int> Graph[maxN];
bool visited[maxN];

void dfs(int v) {
    visited[v] = true;
    for (auto neighbour : Graph[v]) {
        if (!visited[neighbour]) dfs(neighbour);
    }
}

void createGraph(int N, int M, vector<string>& ans) {
    for (int i = 0; i < maxN; i++) {
        visited[i] = false;
        degree[i] = 0;
        Graph[i].clear();
    }

    int from, to, start = 0;
    int m = M;
    while (m--) {
        cin >> from >> to;
        if (m == M - 1) {
            start = from;
        }
        Graph[from].push_back(to);
        Graph[to].push_back(from);
        degree[from]++;
        degree[to]++;
    }

    dfs(start);
    int count = 0;
    for (int i = 0; i < maxN;i++) {
        if (visited[i]) count++;
    }

    if (count != N) {
        ans.push_back("none");
        return;
    }

    int numberOfOddDegree = 0;
    for (int i = 0; i < N; i++) {
        if (degree[i] % 2 != 0)  numberOfOddDegree++;
    }

    if (numberOfOddDegree == 0) ans.push_back("ecycle");
    else if (numberOfOddDegree == 0 || numberOfOddDegree == 2) ans.push_back("epath");
    else ans.push_back("none");

    
}

int main() {
    int queries;
    cin >> queries;

    vector<string> ans;
    int N, M;
    while (queries--) {
        cin >> N >> M;
        createGraph(N, M, ans);
    }
    for (auto x : ans) {
        cout << x << '\n';
    }

    return 0;
}
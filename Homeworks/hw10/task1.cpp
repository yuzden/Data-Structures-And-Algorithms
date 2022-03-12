/*#include <iostream>
#include <vector>

using namespace std;

bool flag = false;
bool dfs(int v, vector<int>& visited, vector<vector<int>>& Graph) {
    visited[v] = 1;
    for (auto neighbour : Graph[v]) {
        if (visited[neighbour] == 0) {
            if (dfs(neighbour, visited, Graph)) return true;
        }
        else if (visited[neighbour] == 1) {
            flag = true;
            return true;
        }
    }
    visited[v] = 2;
    return false;
}

void isValid(int E) {
    vector<vector<int>> Graph(100000);
    vector<int>visited(100000);
    visited = { 0 };

    while (E--) {
        int from, to;
        cin >> from >> to;
        Graph[from].push_back(to);
    }

    for (auto i = 0; i < 100000; i++) {
        if (visited[i] == 0 && dfs(i, visited, Graph)) {
            break;
        }
    }
    if (flag) cout << "1 ";
    else cout << "0 ";
    flag = false;
}

int main() {
    int Q;
    cin >> Q;

    int E;
    for (auto i = 0; i < Q; i++) {
        cin >> E;
        isValid(E);
    }
    return 0;
}*/
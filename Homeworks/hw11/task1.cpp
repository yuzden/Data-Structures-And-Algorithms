/*#include <iostream>
#include <vector>
#include <queue>
#include <climits>

using namespace std;

void shortestPathsDjikstra(vector<vector<pair<int, long long>>>& Graph, vector<pair<long long, int>>& paths) {
    int begin = 1;
    paths[begin].first = 0;
    paths[begin].second = 1;
    priority_queue<pair<long long, int>, vector<pair<long long, int>>, greater<pair<long long, int>>> pq;
    pq.push({ 0,begin });

    while (!pq.empty()) {
        int curr = pq.top().second;
        long long weightToCurr = pq.top().first;
        pq.pop();

        for (auto neighbour : Graph[curr]) {
            int child = neighbour.first;
            long long weightToChild = neighbour.second;

            if (paths[child].first > weightToCurr + weightToChild) {
                paths[child].first = weightToCurr + weightToChild;
                paths[child].second = paths[curr].second % 1000000007;
                pq.push({ paths[child].first, child });
            }
            else if (paths[child].first == weightToCurr + weightToChild) {
                paths[child].second = (paths[child].second + paths[curr].second) % 1000000007;
            }
        }
    }
}

int main() {
    const int C = 100001;
    int N, M;
    cin >> N >> M;
    vector<vector<pair<int, long long>>> Graph(C);

    while (M--) {
        int from, to;
        long long weight;
        cin >> from >> to >> weight;
        Graph[from].push_back({ to, weight });
    }
    vector<pair<long long, int>> paths(C);
    for (int i = 1; i <= C; i+-+) {
        paths[i].first = LLONG_MAX;
        paths[i].second = 0;
    }
    shortestPathsDjikstra(Graph, paths);
    if (paths[N].second) cout << paths[N].first << " " << paths[N].second << '\n';
    else cout << "-1" << " " << "0" << '\n';
    return 0;
}*/
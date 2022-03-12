/*#include <iostream>
#include <unordered_map>
#include <set>
#include <queue>
#include <climits>
#include <vector>

using namespace std;

vector<int>T;
vector<int>S;
void Djikstra(unordered_map <int, vector<pair<int, int>>>& Graph, unordered_map<int, int>& dist, int v) {
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    dist[v] = 0;
    pq.push({ 0,v });

    while (!pq.empty()) {
        int curr = pq.top().second;
        int weightToCurr = pq.top().first;
        pq.pop();

        for (auto x : Graph[curr]) {
            int child = x.first;
            int weightToChild = x.second;

            if (dist[child] > weightToCurr + weightToChild) {
                dist[child] = weightToCurr + weightToChild;
                pq.push({ dist[child], child });
            }
        }
    }
}

int main() {
    long N, M;
    cin >> N >> M;

    unordered_map <int, vector<pair<int, int>>> Graph;

    while (M--) {
        int from, to, dist;
        cin >> from >> to >> dist;
        Graph[from].push_back({ to,dist });
        Graph[to].push_back({ from,dist });
    }

    int K;
    cin >> K;

    while (K--) {
        int temp;
        cin >> temp;
        Graph[INT_MAX].push_back({ temp,0 });
        Graph[temp].push_back({ INT_MAX,0 });
        T.push_back(temp);
    }

    int Q;
    cin >> Q;
    while (Q--) {
        int temp;
        cin >> temp;
        S.push_back(temp);
    }

    unordered_map<int, int> dist;
    for (auto x : Graph) {
        dist[x.first] = INT_MAX;
    }

    Djikstra(Graph, dist, INT_MAX);

    for (auto x : S) {
        cout << dist[x] << '\n';
    }
 
    return 0;
}*/
/*#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

const int N = 1000000;

int numberOfEdges, V;
vector<int> adjacencyList[N];
int degree[N];

void MinimumHeight() {
    queue<int> q;

    for (int i = 0; i < V; i++) {
        if (degree[i] == 1) q.push(i);
    }

    while (V > 2) {
        int top = q.size();
        V -= top;     

        for (int i = 0; i < top; i++) {
            int t = q.front();
            q.pop();

            for (auto j = adjacencyList[t].begin(); j != adjacencyList[t].end(); j++) {
                degree[*j]--;
                if (degree[*j] == 1) q.push(*j);
            }
        }
    }

    vector<int> result;
    while (!q.empty()) {
        result.push_back(q.front());
        q.pop();
    }

    sort(result.begin(), result.end());
    for (auto x : result) {
        cout << x << " ";
    }
}

int main() {
	cin >> numberOfEdges;
    V = numberOfEdges;

    int from, to;
	numberOfEdges--;
    while (numberOfEdges--) {
        cin >> from >> to;
        adjacencyList[from].push_back(to);
        adjacencyList[to].push_back(from);
		degree[from]++;
		degree[to]++;
    }
    MinimumHeight();
	return 0;
}*/
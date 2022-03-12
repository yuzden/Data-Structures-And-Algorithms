/*#include <iostream>
#include <stack>
#include <string>
#include <map>
#include <vector>
using namespace std;
map<int, bool> visited;
map<int,vector<int>> adjacencyList;
stack<int> s;
void dfs(int v){
    visited[v] = true;
    for (auto neighbour : adjacencyList[v]){
        if (!visited[neighbour]) dfs(neighbour);
    }
    s.push(v);
}

void topologicalSort() {
    for (auto x:adjacencyList) {
        if (!visited[x.first]) dfs(x.first);
    }
}

int min(int x, int y) {
    return (x < y) ? x : y;
}

int main() {

    int N;
    cin >> N;
    vector<string> words;
    string temp;
    for (auto i = 0; i < N; i++) {
        cin >> temp;
        words.push_back(temp);
    }

    for (auto i = 0; i < N - 1; i++) {
        string word1 = words[i];
        string word2 = words[i + 1];
        for (int j = 0; j < min(word1.length(), word2.length()); j++) {
            if (word1[j] != word2[j]) {
                adjacencyList[word1[j] - 'a'].push_back(word2[j] - 'a');
                break;
            }
        }
    }

    topologicalSort();

    while (!s.empty()) {
        cout << (char)(s.top() + 'a') << " ";
        s.pop();
    }
    return 0;
}*/
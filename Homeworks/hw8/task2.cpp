/*#include <iostream>
#include <queue>
#include <algorithm>
using namespace std;

struct Compare {
    bool operator()(const pair<pair<long, long>, long>& a, const pair<pair<long, long>, long>& b) {
        if (a.first.second == b.first.second) return a.second > b.second;
        return a.first.second > b.first.second;
    }
};

int main() {
    long N;
    std::cin >> N;
    vector<pair<pair<long, long>, long>> tasks;

    long temp1, temp2;
    for (auto i = 0; i < N; i++) {
        cin >> temp1 >> temp2;
        pair <long, long> temp3 = { temp1, temp2 };
        pair<pair<long, long>, long> temp = { temp3,i };
        tasks.push_back(temp);
    }

    priority_queue<pair<pair<long, long>, long>, vector<pair<pair<long, long>, long>>, Compare> temp;
    vector<long>ready_tasks;

    sort(tasks.begin(), tasks.end());
    long time = 0;
    int i = 0;
    while (i < N) {
        if (temp.empty()) {
            time = time > tasks[i].first.first ? time : tasks[i].first.first;
        }

        while (i < N && time >= tasks[i].first.first) {
            temp.emplace(tasks[i]);
            i++;
        }

        time += temp.top().first.second;
        ready_tasks.push_back(temp.top().second);
        temp.pop();
    }

    while (!temp.empty()) {
        ready_tasks.push_back(temp.top().second);
        temp.pop();
    }

    for (auto x : ready_tasks) {
        cout << x << " ";
    }

    return 0;
}*/
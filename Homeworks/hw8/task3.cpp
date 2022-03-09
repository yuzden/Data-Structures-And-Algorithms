#include <iostream>
#include <queue>
#include <algorithm>

using namespace std;

struct Compare {
    bool operator()(const pair<pair<long, long>, long>& a, const pair<pair<long, long>, long>& b) {
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

    priority_queue<pair<pair<long, long>, long>, vector<pair<pair<long, long>, long>>, Compare> ready_tasks;
   // vector<long>ready_tasks;

    sort(tasks.begin(), tasks.end());
    long time = 0;
    long waiting_time = 0;
    int i = 0;
    while (i < N) {
        while (!ready_tasks.empty() && time < tasks[i].first.first) {
            time += ready_tasks.top().first.second;
            waiting_time += time - ready_tasks.top().first.first;
            ready_tasks.pop();
        }

        if (time<tasks[i].first.first) {
            time = tasks[i].first.first;
        }

        ready_tasks.push(tasks[i]);
        i++;
    }

    while (!ready_tasks.empty()) {
        time += ready_tasks.top().first.second;
        waiting_time += time - ready_tasks.top().first.first;
        ready_tasks.pop();
    }

    cout << waiting_time / N;
    return 0;
}
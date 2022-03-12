/*#include <iostream>
#include <queue>
#include <vector>
using namespace std;

int N, M, kg , time_, K;
const int maxN = 100001;
int times[maxN];
vector<pair<int, pair<int, int> >>Graph[maxN];

int Dijkstra(int currKg){
    for (int i = 0; i < maxN; i++) {
        times[i] = INT_MAX;
    }

    pair<int, pair<int, int> > x;
    times[1] = 0;
    priority_queue <pair<int, pair<int, int>>, vector <pair<int, pair<int, int>>>, greater<pair<int, pair<int, int>>>>pq;
    pq.push({ 0,{1,0} });

    while (!pq.empty()){
        int current = pq.top().second.first;
        pq.pop();

        for (auto x : Graph[current]){
            int child = x.first;
            int cost = x.second.first;
            int currK = x.second.second;

            if (currK <= currKg && times[child] > times[current] + cost){
                times[x.first] = times[current] + cost;
                pq.push({ times[x.first],{x.first,currK} });
            }
        }
    }
    return times[M];
}

int main(){
    cin >> M >> N >> K;

    int result = INT_MAX;
    int MIN = INT_MAX;
    int MAX = 0;
   
    int mid, m;
    int from, to;
    while (N--) {
        cin >> from >> to >> kg >> time_;
        Graph[from].push_back({ to,{time_,kg} });
    }

    while (MIN <= MAX){
        mid = MIN + (MAX - MIN) / 2;
        int m = Dijkstra(mid);

        if (m > K) MIN = mid + 1;
        else {
            MAX = mid - 1;
            result = min(result, mid);
        }
    }

    if (result == INT_MAX) cout << "-1";
    else cout << result;
    return 0;
}*/
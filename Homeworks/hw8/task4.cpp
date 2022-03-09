/*#include <iostream>
#include <set>
#include <queue>

using namespace std;

long available(set<long>&available_operators, long i) {
	if (available_operators.empty()) return -1; 

	auto temp = available_operators.lower_bound(i);
	if (temp != available_operators.end()) return *temp; 
	return *available_operators.begin();
}

void print_busiest(vector<long>& num_serviced) {
	long max = -1;
	for (auto x : num_serviced) {
		max = max > x ? max : x;
	}

	for (auto i = 0; i < num_serviced.size(); i++) {
		if (num_serviced[i] == max) cout << i << " ";
	}
}

void make_calls(vector<pair<long, long>>& calls, set<long>&available_operators, long K, long N) {
	vector<long>num_serviced(K);
	priority_queue <pair<long, long>, vector<pair<long, long>>, greater < pair<long, long>> > busy_operators;

	for (int i = 0; i < N; i++) {
		long temp_call = calls[i].first;
		long temp_time = calls[i].second;
		while (!busy_operators.empty() && busy_operators.top().first <= temp_call) {
			available_operators.insert(busy_operators.top().second);
			busy_operators.pop();
		}
		long available_operator = available(available_operators, (i % K));
		if (available_operator != -1) {
			available_operators.erase(available_operator);
			num_serviced[available_operator]++;
			pair<long, long>temp = { temp_call + temp_time,available_operator };
			busy_operators.push(temp);
		}
	}
	print_busiest(num_serviced);
}

int main() {
	long N, K;
	std::cin >> N >> K;

	vector<pair<long,long>>calls;
	long temp1, temp2;
	for (auto i = 0; i < N; i++) {
		cin >> temp1 >> temp2;
		pair<long, long> temp = { temp1,temp2 };
		calls.push_back(temp);
	}

	set<long>available_operators;
	for (auto i = 0; i < K; i++) {
		available_operators.insert(i);
	}

	make_calls(calls, available_operators, K, N);

	return 0;
}*/




/*#include <iostream>
#include <queue>
#include <algorithm>
using namespace std;

struct Compare {
	bool operator()(const pair<pair<long, long>, long>& a, const pair<pair<long, long>, long>& b) {
		// if (a.first.first > b.first.first) return a.first.second > b.first.second;
		return a.first.first > b.first.first;
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
	long waiting_time = tasks[0].first.first;
	int i = 0;
	while (i < N || ready_tasks.size()) {
		while (i < N && time >= tasks[i].first.first) {
			ready_tasks.push(tasks[i]);
			i++;
		}
		if (ready_tasks.empty()) {
			time = tasks[i].first.first;
		}
		else {
			time += ready_tasks.top().first.second;
			waiting_time += time - ready_tasks.top().first.first;
			ready_tasks.pop();
		}
	}
	cout << waiting_time / N;
	return 0;
}
*/
/*/#include <iostream>
#include <queue>
#include <cstdio>
#include <iomanip>

void find_med(std::priority_queue<long double>& lower, std::priority_queue<long double, std::vector<long double>, std::greater<long double>>& higher,
	long double& med, long double temp) {
	
	if (lower.size() > higher.size()) {
		if (lower.size() - higher.size() >= 2) {
			higher.push(lower.top());
			lower.pop();
		}
	}
	else {
		if (higher.size() - lower.size() >= 2) {
			lower.push(higher.top());
			higher.pop();
		}
	}

	if (lower.size() == higher.size()) {
		med = (double)(lower.top() + higher.top()) / 2;
	}
	else {
		if (lower.size() > higher.size()) med = lower.top();
		else med = higher.top();
	}
}

void add_number(std::priority_queue<long double>& lower,std::priority_queue<long double,
	std::vector<long double>, std::greater<long double>>&higher,  long double temp) {

	if (lower.size() == 0 || temp < lower.top()) {
		lower.push(temp);
	}
	else {
		higher.push(temp);
	}
}

int main() {
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(nullptr);
	
	long N;
	std::cin >> N;
	std::priority_queue<long double> lower;
	std::priority_queue<long double, std::vector<long double>, std::greater<long double>>higher;
	
	long double med = 0;
	long double temp;
	for (auto i = 0; i < N; i++) {
		std::cin >> temp;
		add_number(lower, higher, temp);
		find_med(lower, higher, med, temp);
		std::cout <<  std::fixed << std::setprecision(1) << med  << '\n';
	}
	return 0;
}*/
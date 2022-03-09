#include <iostream>
#include <vector>
#include <queue>
#include <map>

void print_top_view(std::vector <std::pair<int, int>>& index) {
	std::queue<std::pair<int, std::pair<int, int>>>q;
	q.push({ 0,{0,0} });

	std::map<int, int> m;
	while (!q.empty()) {
		auto temp = q.front();
		q.pop();


		if (!m.count(temp.second.first)) {
			m[temp.second.first] = temp.first;
		}
		if (index[temp.first + 1].first != -1) q.push({ index[temp.first + 1].first , { temp.second.first - 1, temp.second.second - 1 } });
		if (index[temp.first + 1].second != -1) q.push({ index[temp.first + 1].second , { temp.second.first + 1, temp.second.second - 1 } });
	}

	for (auto i = m.begin(); i != m.end(); i++) {
		std::cout << i->second << " ";
	}
}

int main() {
	int N;
	std::cin >> N;
	N++;
	std::vector <std::pair<int, int>> index(N);
	index[0] = { 0,0 };
	for (int i = 1; i < N; i++) {
		int x;
		int y;
		std::cin >> x >> y;
		std::pair<int, int> temp;
		temp.first = x;
		temp.second = y;
		index[i] = temp;
	}

	print_top_view(index);
	
	return 0;
}
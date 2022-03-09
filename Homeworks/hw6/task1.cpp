/**#include <iostream>
#include <vector>

const int max = 1000001;
std::vector<int> tree[max];

void gift_number(int s, int e, std::vector<int>&count){
    std::vector<int>::iterator u;
    count[s] = 1;
    for (u = tree[s].begin(); u != tree[s].end(); u++) {
        if (*u == e) continue;
        gift_number(*u, s, count);
        count[s] += count[*u];
    }
}

int main() {
	int N;
	std::cin >> N;
	int n = N;
	N--;
	int x;
	int y;

	while (N > 0) {
		std::cin >> x >> y;
		tree[x].push_back(y);
		N--;
	}
	std::vector<int>count(n);

	gift_number(0, 0, count);

	for (auto x : count) {
		std::cout << x-1 << " ";
	}
	
	return 0;
}**/
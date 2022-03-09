#include <iostream>
#include <vector>
#include <algorithm>

long find_numbers(std::pair<long, long>& S_P, std::vector<long>& elements) {
	int ind = std::upper_bound(elements.begin(), elements.end(), S_P.second) - elements.begin() - 1;
//	if (elements[ind] != S_P.second) ind--;
	if (elements[ind] > S_P.first) return 0;
	long count = 0;
	long num = 0;

	for (int i = ind; i >= 0; i--) {
		if ((num + elements[i]) <= S_P.first) {
			num += elements[i];
			count++;
		}
		else {
			break;
		}
	}
	return count;
}

int main() {
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(nullptr);
	long N, Q;
	std::cin >> N >> Q;

	std::vector<long> elements;
	for (int i = 0; i < N; i++) {
		long temp;
		std::cin >> temp;
		elements.push_back(temp);
	}
	std::sort(elements.begin(), elements.end());

	std::vector<std::pair<long, long>> S_P;

	for (int i = 0; i < Q; i++) {
		long S, P;
		std::cin >> S >> P;
		std::pair<long, long> temp;
		temp.first = S;
		temp.second = P;
		S_P.push_back(temp);
	}

	for (int i = 0; i < Q; i++) {
		long result = find_numbers(S_P[i], elements);
		printf ("%li \n", result);
	}

	return 0;
}
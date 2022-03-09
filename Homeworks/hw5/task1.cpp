/**#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

bool compare(std::pair<int, int>&a, std::pair<int, int>&b) {
	return a.second > b.second;
}

void unique_classes(std::string& S) {
	std::pair<int, int>a_z[26];
	
	std::pair<int, int>A_Z[26];
	
	std::pair<int, int>nums[10];
	
	for (int i = 0; i < S.length(); i++) {
		if (S[i] >= 'a' && S[i] <= 'z') {
			a_z[S[i] - 'a'].first = i;
			a_z[S[i] - 'a'].second++;
		}
		else if (S[i] >= 'A' && S[i] <= 'Z') {
			A_Z[S[i] - 'A'].first = i;
			A_Z[S[i] - 'A'].second++;
		}
		else {
			nums[S[i] - '0'].first = i;
			nums[S[i] - '0'].second++;
		}
	}
	sort(a_z, a_z + 26, compare);
	sort(A_Z, A_Z + 26, compare);
	sort(nums, nums + 10, compare);
	std::vector<int> pos;

	for (int i = 0; i < 26; i++) {
		if (a_z[i].second == 1) pos.push_back(a_z[i].first);
		if (A_Z[i].second == 1) pos.push_back(A_Z[i].first);
	}

	for (int i = 0; i < 10; i++) {
		if(nums[i].second == 1) pos.push_back(nums[i].first);
	}

	sort(pos.begin(), pos.end());

	for (int i = 0; i < pos.size(); i++) {
		std::cout << pos[i] << " ";
	}
}

int main() {
	std::string S;
	std::cin >> S;
	unique_classes(S);

	return 0;
}**/
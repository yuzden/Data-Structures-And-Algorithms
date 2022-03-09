/*#include <iostream>
#include <unordered_map>
#include <unordered_set>
#include <vector>

using namespace std;

void countDoors(vector<long>& keys, vector<long>& doors, long N) {
	long count = 0;
	unordered_map<long, long>keyss;
	for (auto i = 0; i < N; i++) {
		if (!keyss.count(keys[i])) {
			keyss.insert({keys[i],1});
		}
		else {
			keyss.find(keys[i])->second++;
		}
		auto isIn = keyss.count(doors[i]);
		auto it = keyss.find(doors[i]);
		if (isIn && it->second > 0) {
			it->second--;
		}
		else {
			count++;
		}
	}
	cout << count;
}

int main() {
	long N;
	cin >> N;

	long key;
	vector<long> keys(N);
	for (auto i = 0; i < N; i++) {
		cin >> key;
		keys[i] = key;
	}

	long door;
	vector<long> doors(N);
	for (auto i = 0; i < N; i++) {
		cin >> door;
		doors[i] = door;
	}
	
	countDoors(keys, doors, N);

	return 0;
}*/
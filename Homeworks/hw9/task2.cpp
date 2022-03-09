#include <iostream>
#include <unordered_map>
#include <vector>

using namespace std;

int main() {
    long N, K;
    cin >> N >> K;

    long kg;

    vector<long> kgs;
    unordered_map <double, long> before;
    unordered_map <double, long> after;

    for (auto i = 0; i < N; i++) {
        cin >> kg;
        kgs.push_back(kg);
        after[kg]++;
    }

    long count = 0;
    for (auto i = 0; i < N; i++) {
        after[kgs[i]]--;
        double num_bef = 0;
        double num_after = 0;
        if (kgs[i] % K == 0) {
            num_bef = kgs[i] / K;
        }
        num_after = kgs[i] * K;
        if (before[num_bef] && after[num_after]) {
            count += before[num_bef] * after[num_after];
        }
        before[kgs[i]]++;
    }

    cout << count;

    return 0;
}
#include <iostream>
#include <vector>
#include <algorithm>

int main() {

    long N, K;
    std::cin >> N >> K;
    std::vector<std::pair<long, long>> s;
    for (auto i = 0; i < N; i++) {
        long temp;
        std::cin >> temp;
        std::pair<long, long>temp_pair = { temp , i };
        s.push_back(temp_pair);
    }
    std::vector<long> result(N);

    sort(s.begin(), s.end());

   // result.push_back(-1);
    bool isInd = false;
    for (auto i = s.size()-1; i>=1; i--) {
        for (auto j = i-1; j >= 0; j--) {
            if (s[i].first - s[j].first <= K && s[i] > s[j] && s[i].second > s[j].second) {
                result[s[i].second] = s[j].second;
                isInd = true;
                break;
            }
        }

        if (isInd) {
            isInd = false;
        }
        else {
            result[i] = -1;
        }
    }

    for (auto x : result) {
        std::cout << x << " ";
    }

    return 0;
}
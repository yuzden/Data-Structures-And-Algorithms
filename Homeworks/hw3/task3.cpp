/**#include <iostream>
#include <vector>
#include <algorithm>

bool compare_by_first(const std::pair<long, long>& a, const std::pair<long, long>& b) {
    if (a.first == b.first) {
        return a.second < b.second;
    }
    return a.first < b.first;
}

long dead_demons(std::vector<std::pair<long, long>>& demons) {
    std::vector<long> subsequence;
    subsequence.push_back(demons[0].second);
  
    for (int i = 1; i < demons.size(); i++) {
        if (demons[i].first != demons[i - 1].first) {
            if (subsequence.back() < demons[i].second) {
                subsequence.push_back(demons[i].second);
            }
            else {
                int ind = (std::lower_bound(subsequence.begin(), subsequence.end(), demons[i].second) - subsequence.begin());
                subsequence[ind] = demons[i].second;
            }
        }
    }
    return subsequence.size();
}

int main() {
    int N;
    std::cin >> N;

    std::vector<std::pair<long, long>> demons;
    for (int i = 0; i < N; i++) {
        long temp1;
        long temp2;
        std::cin >> temp1 >> temp2;
        std::pair<long, long> temp_demon;
        temp_demon.first = temp1;
        temp_demon.second = temp2;
        demons.push_back(temp_demon);
    }

    std::sort(demons.begin(), demons.end(), compare_by_first);

    std::cout << dead_demons(demons);

    return 0;
}
**/
/**#include <iostream>
#include <vector>
#include <algorithm>

int find_complexity1(int knowledge, std::vector<int>& complexity) {
    if (knowledge <= complexity[0]) return complexity[0];
    if (knowledge >= complexity[complexity.size() - 1]) return complexity[complexity.size() - 1];
    for (int i = 1; i <= complexity.size() - 1; i++) {
        if (complexity[i] == knowledge) return knowledge;
        if (complexity[i - 1] < knowledge && knowledge < complexity[i]) {
            if ((knowledge - complexity[i - 1]) <= (complexity[i] - knowledge)) {
                return complexity[i - 1];
            }
            else {
                return complexity[i];
            }
        }
    }
    return 0;
}

int find_complexity(int knowledge, std::vector<int>& complexity) {
    if (knowledge <= complexity[0]) return complexity[0];
    if (knowledge >= complexity[complexity.size() - 1]) return complexity[complexity.size() - 1];

    auto num = std::lower_bound(complexity.begin(), complexity.end(),knowledge);
    int num1 = *(num - 1);
    int num2 = *(num);

    if (abs(knowledge - num1) <= abs(knowledge - num2)) {
        return complexity[num - complexity.begin() - 1];
    }

    return complexity[num - complexity.begin()];
}


int main() {
    int n, m;
    std::cin >> n >> m;

    std::vector<int> complexity;
    for (int i = 0; i < n; i++) {
        int temp;
        std::cin >> temp;
        complexity.push_back(temp);
    }

    std::vector<int> knowledge;
    for (int i = 0; i < m; i++) {
        int temp;
        std::cin >> temp;
        knowledge.push_back(temp);
    }

    // std::sort(complexity.begin(), complexity.end());

    for (int i = 0; i < m; i++) {
        std::cout << find_complexity(knowledge[i], complexity) << '\n';
    }
    return 0;
}**/
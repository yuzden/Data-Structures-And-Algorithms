#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

struct boy {
    int ID;
    double di, ti, eff;
};

bool compareByEff(const boy& a, const boy& b)
{
    if (a.eff == b.eff) {
        return a.di > b.di;
    }
    return a.eff > b.eff;
}

int main() {
    int N;
    std::cin >> N;

    if (N < 3 || N > pow(10, 5)) return 0;

    double di, ti;

    std::vector<boy> boys;
    for (int i = 0; i < N; i++) {
        std::cin >> di >> ti;
        if (di < 20 || di > 2000 || ti < 1 || ti > 2000) return 0;

        boy temp;
        temp.ID = i + 1;
        temp.di = di;
        temp.ti = ti;
        temp.eff = di * di / ti;
        boys.push_back(temp);
    }

    std::sort(boys.begin(), boys.end(), compareByEff);

    for (int i = 0; i < N; i++) {
        std::cout << boys[i].ID << " ";
    }

    return 0;
}
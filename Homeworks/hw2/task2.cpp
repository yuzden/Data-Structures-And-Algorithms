/**#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

void change_date(std::string& temp) {
    std::string YY = temp.substr(6);
    std::string MM = temp.substr(3, 2);
    std::string DD = temp.substr(0, 2);
    std::string result = YY + "." + MM + "." + DD;
    temp = result;
}

int main() {
    long long  N;
    std::cin >> N;
    if (N < 1) return 0;

    std::vector<std::pair<std::string,int>> timestamps;
   
    for (int j = 0; j < N; j++) {
        std::string temp_time;
        std::cin >> temp_time;

        std::string temp_date;
        std::cin >> temp_date;

        std::pair<std::string, int > temp;
        temp.second = j + 1;

        change_date(temp_date);
        temp.first = temp_date + " " + temp_time;

        timestamps.push_back(temp);
    }

    std::sort(timestamps.begin(), timestamps.end());

    for (int j = 0; j < N; j++) {
        std::cout << timestamps[j].second << '\n';
    }

    return 0;
}**/
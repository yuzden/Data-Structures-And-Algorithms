/**#include <iostream>
#include <vector>
#include <algorithm>

int main() {
    int N;
    std::cin >> N;

    if (N < 0) return 0;

    std::vector<char> numbers;
    std::vector<char> capitals;
    std::vector<char> lowercase;

    char temp;
    for (int i = 0; i < N; i++) {
        std::cin >> temp;
        if (temp >= 48 && temp <= 57) {
            numbers.push_back(temp);
        }
        else if (temp >= 65 && temp <= 90) {
            capitals.push_back(temp);
        }
        else if (temp >= 97 && temp <= 122) {
            lowercase.push_back(temp);
        }
        else {
            return 0;
        }
    }

    std::sort(numbers.begin(), numbers.end());
    std::sort(capitals.begin(), capitals.end());
    std::sort(lowercase.begin(), lowercase.end());

    for (int i = 0; i < numbers.size(); i++) {
        std::cout << numbers[i];
    }

    for (int i = 0; i < lowercase.size(); i++) {
        std::cout << lowercase[i];
    }

    for (int i = 0; i < capitals.size(); i++) {
        std::cout << capitals[i];
    }


    return 0;
}**/
/**#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

int main() {
    int N;
    std::cin >> N;
    std::vector<int> numbers;
    int temp;

    if (N < 1) {
        return 0;
    }

    for (int i = 0; i < N; i++) {
        std::cin >> temp;
        if (temp > 0) {
            numbers.push_back(temp);
        }
    }

    if (numbers.size() == 0) {
        std::cout << "1";
        return 0;
    }

    sort(numbers.begin(), numbers.end());
    numbers.erase(unique(numbers.begin(), numbers.end()), numbers.end());
    size_t size = numbers.size();
   
    if (size == 1 && numbers[0] == 1) {
        std::cout << "2";
        return 0;
    }
  
    if (numbers[0] != 1) {
        std::cout << "1";
        return 0;
    }

    int m = numbers[size - 1] + 1;

    int j = 1;
    for (int i = 0; i < size; i++) {

        if (numbers[i] != j && j < m) {
            std::cout << j;
            return 0;
        }
        j++;
    }
    std::cout << j;
    return 0;
}**/
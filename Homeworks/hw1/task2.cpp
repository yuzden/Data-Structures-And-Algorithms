/**#include <iostream>
#include <string>

int main() {
    std::string word;
    int N;
    char S;

    std::cin >> word;
    std::cin >> N;
    std::cin >> S;
    size_t size = word.length();

    if (size < 1 || size > 100 || N < 1) {
        return 0;
    }
 
    int rest_S = N - size * (N / size);

    int count_S = 0;
    int other_S = 0;
    for (int i = 0; i < size; i++) {
        if (word[i] == S) count_S++;
        if (word[i] == S && i < rest_S) other_S++;
    }

    int counter = ((N / size) * count_S) + other_S;
    std::cout << counter;
  
    return 0;
}**/
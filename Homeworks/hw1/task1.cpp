#include <iostream>
#include <string>
#include <vector>
#include <cmath>

int main() {
    std::string word;
    char S;

    std::cin >> word;
    std::cin >> S;

    int size = word.length();

    if (size == 0 || size > pow(10,6)) return 0;
   
    std::vector < int > position, distance;

    for (int i = 0; i < size; i++) {
        if (word[i] == S)
            position.push_back(i);
    }
    for (int i = 0; i < size; i++) {
        int temp = pow(10,6);
        for (int j = 0; j < position.size(); j++) {
           temp = std::min(temp, abs(position[j] - i));  
        }
        distance.push_back(temp);
    }

    for (int i = 0; i < size; i++) {
        std::cout << distance[i] << " ";
    }

    return 0;
}
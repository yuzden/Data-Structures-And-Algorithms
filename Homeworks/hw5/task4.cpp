#include <iostream>
#include <vector>

int main() {
	std::vector<long>numbers;
	long N;
	std::cin >> N;
	long temp;
	
	for (auto i = 0; i < N; i++) {
		std::cin >> temp;
		numbers.push_back(temp);
	}
	
    long top = 0;
    long counter = 0;
    long min;

    std::vector<long>stack(numbers.size());
    std::vector<long>days(numbers.size());
    
    min = numbers[0];

    for (long i = 1; i < numbers.size(); i++) {
        if (numbers[i] <= min) {
            min = numbers[i];
            top = 0;
        }
        else {
            if (numbers[i - 1] < numbers[i])
                days[i] = 1;
            else {
                while (top != 0 && numbers[i] <= numbers[stack[top - 1]]) {
                    if (days[i] < days[stack[top - 1]] + 1) days[i] = days[stack[top - 1]] + 1;
                    top--;
                }
            }
            if (counter < days[i]) counter = days[i];
        }
        stack[top++] = i;
    }
 
	std::cout << counter;

	return 0;
}
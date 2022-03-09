/**#include <iostream>
#include <cmath>

long cube_root(long num) {
    long i = 0;
    while (i * i * i <= num) {
        if (i * i * i == num) return i;
        i++;
        if (i * i * i > num) return i - 1;
    }
}

long count_presents(long N) {
    static long counter = 0;
    if (N > 0) {
        long result = cube_root(N);
        long price_gift = result * result * result;
        N -= price_gift;
        counter++;
        count_presents(N);
    }
    return counter;
}

int main() {
    long n;
    std::cin >> n;

    long result = count_presents(n);

    std::cout << result;
    return 0;
}**/
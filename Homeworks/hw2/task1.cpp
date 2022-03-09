/**#include <iostream>
#include <vector>

void swap(int* a, int* b) {
    int tmp = *a;
    *a = *b;
    *b = tmp;
}

int Partition(std::vector<int>& v, int start, int end) {
    int pivot = end;
    int j = start;
    for (int i = start; i < end; ++i) {
        if (v[i] < v[pivot]) {
            swap(&v[i], &v[j]);
            ++j;
        }
    }
    swap(&v[j], &v[pivot]);
    return j;

}

void Quicksort(std::vector<int>& v, int start, int end) {

    if (start < end) {
        int p = Partition(v, start, end);
        Quicksort(v, start, p - 1);
        Quicksort(v, p + 1, end);
    }
}

int main() {
    int  N;
    std::vector<int> prices;
    int temp;
    int K;

    std::cin >> N;
    if (N <= 0) return 0;

    for (int i = 0; i < N; i++) {
        std::cin >> temp;
        prices.push_back(temp);
    }

    std::cin >> K;
    if (K <= 0 || K > N) return 0;

    Quicksort(prices, 0, N - 1);

    long long result = 0;
    for (int i = 0; i < K; i++) {
        result += prices[i];
    }

    std::cout << result;

    return 0;
}**/
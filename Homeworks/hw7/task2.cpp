/*#include <iostream>
#include <set>
#include <bitset>
#include <cmath>

void find_min_XOR(std::set<int>& nums, int& min, int temp) {
    auto temp1 = nums.find(temp);
    auto temp_bg = temp1;
    temp_bg++;

    auto temp_sm = temp1;

    if (temp_sm != nums.begin()) {
        temp_sm--;
        if (min > (temp ^ (*temp_sm))) min = (temp ^ (*temp_sm));
    }

    if (temp_bg != nums.end()) {
        if (min > (temp ^ (*temp_bg))) min = (temp ^ (*temp_bg));
    }

    std::cout << min << '\n';
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    int Q;
    std::cin >> Q;

    std::set<int>nums;
    nums.insert(0);
    int min_XOR = pow(10, 9);


    for (int i = 0; i < Q; i++) {
        int temp;
        std::cin >> temp;
        nums.insert(temp);
        find_min_XOR(nums, min_XOR, temp);
    }
    return 0;
}*/
/*#include <iostream>
#include <string>
#include <set>
#include <bitset>

std::string remove_zeros(std::string& s) {
    std::string result;
    for (int i = 0; i < s.length(); i++) {
        if (s[i] == '1') result += s[i];
    }
    return result;
}

void unique_(std::string& s, std::set<std::string>& uni, int j) {
    remove_zeros(s);
    for (int i = j; i < s.length(); i++) {
        if (s[i] == '1') {
            uni.insert(s);
            s[i] = '0';
            uni.insert(s);
            unique_(s, uni, i);
            s[i] = '1';
        }
    }
    if (s == "0") return;
}

int main() {
    int n;
    std::cin >> n;
    std::set<std::string> s;

    for (int i = 0; i < n; i++) {
        long temp;
        std::cin >> temp;
        std::string binary = std::bitset<64>(temp).to_string();
        std::set<std::string> t;
        unique_(binary, t, 0);

        s.insert(t.begin(), t.end());
    }

    std::cout << s.size();

    return 0;
}*/
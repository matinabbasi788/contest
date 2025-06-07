#include <iostream>
#include <vector>
#include <string>
#include <set>

int beauty(const std::string& s) {
    int count = 0;
    for (size_t i = 1; i < s.length(); ++i) {
        if (s[i] != s[i - 1]) {
            count++;
        }
    }
    return count;
}

int main() {
    int t;
    std::cin >> t;
    while (t--) {
        int n;
        std::cin >> n;
        std::string s;
        std::cin >> s;

        for (int i = 1; i <= n; ++i) {
            std::string prefix = s.substr(0, i);
            std::set<int> possible_k;

            for (int k = 1; k <= i; ++k) {
                if (i % k == 0) {
                    int segment_length = i / k;
                    bool possible = true;
                    int expected_beauty = -1;

                    std::vector<int> beauties;
                    for (int j = 0; j < k; ++j) {
                        std::string segment = prefix.substr(j * segment_length, segment_length);
                        beauties.push_back(beauty(segment));
                    }
                    if (std::set<int>(beauties.begin(), beauties.end()).size() == 1) {
                        possible_k.insert(k);
                    }
                }
            }
            std::cout << possible_k.size() << (i == n ? "" : " ");
        }
        std::cout << std::endl;
    }
    return 0;
}

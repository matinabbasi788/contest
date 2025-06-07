#include <iostream>
#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <algorithm>
#include <numeric>

using namespace std;

vector<long long> get_divisors(long long n) {
    vector<long long> divisors;
    for (long long i = 1; i * i <= n; i++) {
        if (n % i == 0) {
            divisors.push_back(i);
            if (i * i != n) {
                divisors.push_back(n / i);
            }
        }
    }
    return divisors;
}

long long solve_case(int n, vector<int>& a, vector<int>& b) {
    // Check if arrays are identical when sorted
    vector<int> sorted_a = a;
    vector<int> sorted_b = b;
    sort(sorted_a.begin(), sorted_a.end());
    sort(sorted_b.begin(), sorted_b.end());
    if (sorted_a == sorted_b) {
        return 31415926LL;
    }
    
    int max_b = *max_element(b.begin(), b.end());
    long long min_k = max_b + 1;
    
    // Compute sums of a and b
    long long sum_a = accumulate(a.begin(), a.end(), 0LL);
    long long sum_b = accumulate(b.begin(), b.end(), 0LL);
    
    if (sum_a != sum_b) {
        long long delta = sum_a - sum_b;
        long long abs_delta = abs(delta);
        
        vector<long long> divisors = get_divisors(abs_delta);
        unordered_set<long long> candidates;
        for (long long d : divisors) {
            if (d >= min_k && d <= 1e9) {
                candidates.insert(d);
            }
            long long other_d = abs_delta / d;
            if (d != other_d && other_d >= min_k && other_d <= 1e9) {
                candidates.insert(other_d);
            }
        }
        
        // Prepare frequency map for b
        unordered_map<int, int> b_freq;
        for (int x : b) {
            b_freq[x]++;
        }
        
        // Check each candidate k in ascending order
        vector<long long> k_values(candidates.begin(), candidates.end());
        sort(k_values.begin(), k_values.end());
        
        for (long long k : k_values) {
            unordered_map<int, int> rem_freq;
            bool valid = true;
            for (int x : a) {
                int rem = x % k;
                if (rem > max_b) {
                    valid = false;
                    break;
                }
                rem_freq[rem]++;
            }
            if (valid && rem_freq == b_freq) {
                return k;
            }
        }
        
        return -1;
    } else {
        // Sum of a and b are equal, proceed with original approach
        unordered_map<int, int> b_freq;
        for (int x : b) {
            b_freq[x]++;
        }
        
        // Generate candidate k values from differences
        unordered_set<long long> candidates;
        for (int ai : a) {
            for (int bj : b) {
                if (ai >= bj) {
                    long long diff = ai - bj;
                    vector<long long> divisors = get_divisors(diff);
                    for (long long k : divisors) {
                        if (k >= min_k && k <= 1e9) {
                            candidates.insert(k);
                        }
                    }
                }
            }
        }
        
        // Check each candidate k in ascending order
        vector<long long> k_values(candidates.begin(), candidates.end());
        sort(k_values.begin(), k_values.end());
        
        for (long long k : k_values) {
            unordered_map<int, int> rem_freq;
            bool valid = true;
            for (int x : a) {
                int rem = x % k;
                if (rem > max_b) {
                    valid = false;
                    break;
                }
                rem_freq[rem]++;
            }
            if (valid && rem_freq == b_freq) {
                return k;
            }
        }
        
        return -1;
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int t;
    cin >> t;
    
    while (t--) {
        int n;
        cin >> n;
        
        vector<int> a(n), b(n);
        for (int i = 0; i < n; i++) {
            cin >> a[i];
        }
        for (int i = 0; i < n; i++) {
            cin >> b[i];
        }
        
        cout << solve_case(n, a, b) << "\n";
    }
    
    return 0;
}

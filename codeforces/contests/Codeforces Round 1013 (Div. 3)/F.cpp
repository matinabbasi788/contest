#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <unordered_map>

using namespace std;

const int MOD = 998244353;

class RockClimber {
    int rows, cols, max_dist;
    vector<string> mountain;
    vector<vector<int>> dp_table;
    vector<vector<int>> hold_positions;

    void read_input() {
        cin >> rows >> cols >> max_dist;
        mountain.resize(rows);
        for (int i = 0; i < rows; ++i) {
            cin >> mountain[i];
        }
    }

    void find_hold_positions() {
        hold_positions.resize(rows);
        for (int i = 0; i < rows; ++i) {
            for (int j = 0; j < cols; ++j) {
                if (mountain[i][j] == 'X') {
                    hold_positions[i].push_back(j);
                }
            }
        }
    }

    bool is_valid_problem() {
        for (const auto& row : hold_positions) {
            if (row.empty()) return false;
        }
        return true;
    }

    void initialize_last_row() {
        int last_row = rows - 1;
        const auto& positions = hold_positions[last_row];
        
        for (int pos : positions) {
            int left_bound = pos - max_dist;
            int right_bound = pos + max_dist;
            
            auto left_it = lower_bound(positions.begin(), positions.end(), left_bound);
            auto right_it = upper_bound(positions.begin(), positions.end(), right_bound);
            
            int count = right_it - left_it;
            dp_table[last_row][pos] = count % MOD;
        }
    }

    void compute_dp() {
        int horizontal_reach = sqrt(max_dist * max_dist - 1);
        
        for (int i = rows - 2; i >= 0; --i) {
            const auto& next_row_dp = dp_table[i + 1];
            vector<int> prefix_sum(cols + 1, 0);
            
            for (int j = 0; j < cols; ++j) {
                prefix_sum[j + 1] = (prefix_sum[j] + next_row_dp[j]) % MOD;
            }
            
            unordered_map<int, int> position_values;
            for (int pos : hold_positions[i]) {
                int left = max(0, pos - horizontal_reach);
                int right = min(cols, pos + horizontal_reach + 1);
                position_values[pos] = (prefix_sum[right] - prefix_sum[left] + MOD) % MOD;
            }
            
            const auto& current_positions = hold_positions[i];
            vector<int> values;
            vector<int> value_prefix(current_positions.size() + 1, 0);
            
            for (int pos : current_positions) {
                values.push_back(position_values[pos]);
            }
            
            for (int j = 0; j < values.size(); ++j) {
                value_prefix[j + 1] = (value_prefix[j] + values[j]) % MOD;
            }
            
            for (int j = 0; j < current_positions.size(); ++j) {
                int pos = current_positions[j];
                int left_bound = pos - max_dist;
                int right_bound = pos + max_dist;
                
                auto left_it = lower_bound(current_positions.begin(), current_positions.end(), left_bound);
                auto right_it = upper_bound(current_positions.begin(), current_positions.end(), right_bound);
                
                int left_idx = left_it - current_positions.begin();
                int right_idx = right_it - current_positions.begin();
                
                dp_table[i][pos] = (value_prefix[right_idx] - value_prefix[left_idx] + MOD) % MOD;
            }
        }
    }

    int calculate_result() {
        int total = 0;
        for (int pos : hold_positions[0]) {
            total = (total + dp_table[0][pos]) % MOD;
        }
        return total;
    }

public:
    int solve() {
        read_input();
        find_hold_positions();
        
        if (!is_valid_problem()) {
            return 0;
        }
        
        dp_table.assign(rows, vector<int>(cols, 0));
        initialize_last_row();
        compute_dp();
        
        return calculate_result();
    }
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int test_cases;
    cin >> test_cases;
    
    while (test_cases--) {
        RockClimber solver;
        cout << solver.solve() << '\n';
    }

    return 0;
}

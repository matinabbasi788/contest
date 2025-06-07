#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int k;
    cin >> k;
    cin.ignore(); // Consume newline after k
    
    vector<string> chunks(k);
    for (int i = 0; i < k; ++i) {
        getline(cin, chunks[i]);
    }
    
    vector<int> t(k);
    for (int i = 0; i < k; ++i) {
        cin >> t[i];
    }
    
    // Compute cumulative lengths
    vector<int> cumsum(k + 1, 0);
    for (int i = 0; i < k; ++i) {
        cumsum[i + 1] = cumsum[i] + chunks[i].size();
    }
    int n = cumsum[k];
    
    // Build time array
    vector<int> time(n);
    for (int i = 0; i < k; ++i) {
        for (int j = cumsum[i]; j < cumsum[i + 1]; ++j) {
            time[j] = t[i];
        }
    }
    
    // Concatenate chunks
    string message;
    for (const auto& chunk : chunks) {
        message += chunk;
    }
    
    // Parse rendered text
    vector<int> rendered_times;
    string state = "normal";
    bool inside_inline_code = false;
    int i = 0;
    while (i < n) {
        if (inside_inline_code) {
            if (message[i] == '`') {
                inside_inline_code = false;
            } else {
                rendered_times.push_back(time[i]);
            }
        } else {
            if (message[i] == '`') {
                inside_inline_code = true;
            } else if (message[i] == '\\' && i + 1 < n) {
                rendered_times.push_back(max(time[i], time[i + 1]));
                i++;
            } else if (message[i] == ':') {
                size_t j = message.find(':', i + 1);
                rendered_times.push_back(time[j]);
                i = j;
            } else if (message[i] == '(' && state == "normal") {
                state = "bold";
            } else if (message[i] == '[' && state == "normal") {
                state = "italic";
            } else if (message[i] == ')' && state == "bold") {
                state = "normal";
            } else if (message[i] == ']' && state == "italic") {
                state = "normal";
            } else {
                rendered_times.push_back(time[i]);
            }
        }
        i++;
    }
    
    // Compute earliest start time
    int m = rendered_times.size();
    int s = INT_MIN;
    for (int i = 0; i < m; ++i) {
        s = max(s, rendered_times[i] - i);
    }
    
    cout << s << endl;
    
    return 0;
}


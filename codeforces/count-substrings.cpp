#include <iostream>
#include <string>
#include <memory>

using namespace std;

// Trie node structure
struct TrieNode {
    TrieNode* children[26];  // For lowercase a-z
    TrieNode() {
        for (int i = 0; i < 26; i++) {
            children[i] = nullptr;
        }
    }
};

// Function to count distinct substrings using Trie
long long count_distinct_substrings(const string& s) {
    int n = s.length();
    
    // Validate input
    if (n < 1 || n > 400000) {
        cout << "Error: String length must be between 1 and 400000" << endl;
        return -1;
    }
    for (char c : s) {
        if (!islower(c) || !isalpha(c)) {
            cout << "Error: String must contain only lowercase English letters" << endl;
            return -1;
        }
    }
    
    // Create Trie root
    unique_ptr<TrieNode> root(new TrieNode());
    long long count = 0;  // Count of distinct substrings
    
    // Insert all substrings into Trie
    for (int i = 0; i < n; i++) {
        TrieNode* current = root.get();
        for (int j = i; j < n; j++) {
            int index = s[j] - 'a';
            if (!current->children[index]) {
                current->children[index] = new TrieNode();
                count++;  // New substring found
            }
            current = current->children[index];
        }
    }
    
    return count;
}

int main() {
    string s;
    getline(cin, s);
    
    long long result = count_distinct_substrings(s);
    if (result != -1) {
        cout << result << endl;
    }
    
    return 0;
}

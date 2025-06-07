#include <bits/stdc++.h>
using namespace std;

const int MAX_NODES = 200000 + 5;

int num_nodes;
vector<int> original_tree[MAX_NODES], modified_tree[MAX_NODES];
pair<int, int> edge_list[MAX_NODES];

int parent[MAX_NODES], subtree_size[MAX_NODES], in_time[MAX_NODES], out_time[MAX_NODES], 
    count_array[MAX_NODES], small_count[MAX_NODES];
int dfs_timer;

int centroid_subtree[MAX_NODES], centroid_parent[MAX_NODES], child_index[MAX_NODES], 
    traversal_order[MAX_NODES], traversal_size, t_prime_nodes, t_prime_root;

bool visited[MAX_NODES];
int group_id[MAX_NODES], node_color[MAX_NODES];
vector<vector<int>> node_groups;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int test_cases;
    cin >> test_cases;
    while (test_cases--) {
        cin >> num_nodes;
        
        // Initialize and read input
        for (int i = 1; i <= num_nodes; i++) {
            original_tree[i].clear();
        }
        
        for (int i = 1; i < num_nodes; i++) {
            int u, v;
            cin >> u >> v;
            edge_list[i] = {u, v};
            original_tree[u].push_back(v);
            original_tree[v].push_back(u);
        }

        // First DFS to compute subtree sizes and small counts
        dfs_timer = 0;
        fill(count_array, count_array + num_nodes + 2, 0);
        
        struct DFSItem { int node, parent, child_idx; };
        vector<DFSItem> dfs_stack;
        dfs_stack.reserve(num_nodes);
        dfs_stack.push_back({1, 0, 0});
        parent[1] = 0;
        
        while (!dfs_stack.empty()) {
            auto &current = dfs_stack.back();
            int v = current.node, p = current.parent;
            
            if (current.child_idx == 0) {
                parent[v] = p;
                subtree_size[v] = 1;
                in_time[v] = ++dfs_timer;
            }
            
            if (current.child_idx < (int)original_tree[v].size()) {
                int u = original_tree[v][current.child_idx++];
                if (u == p) continue;
                dfs_stack.push_back({u, v, 0});
            } else {
                out_time[v] = dfs_timer;
                if (p != 0) {
                    int current_size = subtree_size[v];
                    int other_size = num_nodes - current_size;
                    
                    if (current_size <= other_size) {
                        count_array[in_time[v]]++;
                        count_array[out_time[v] + 1]--;
                    } else {
                        count_array[1]++;
                        count_array[num_nodes + 1]--;
                        count_array[in_time[v]]--;
                        count_array[out_time[v] + 1]++;
                    }
                    subtree_size[p] += subtree_size[v];
                }
                dfs_stack.pop_back();
            }
        }

        // Compute prefix sums and small counts
        for (int i = 1; i <= num_nodes; i++) {
            count_array[i] += count_array[i - 1];
        }
        for (int v = 1; v <= num_nodes; v++) {
            small_count[v] = count_array[in_time[v]];
        }

        // Find the best edge to remove
        long long min_value = LLONG_MAX;
        int node_a = 1, node_b = 2;
        
        for (int i = 1; i < num_nodes; i++) {
            int x = edge_list[i].first;
            int y = edge_list[i].second;
            int a = min(x, y), b = max(x, y);
            
            int component_size;
            if (parent[b] == a) {
                component_size = subtree_size[b];
            } else {
                component_size = num_nodes - subtree_size[a];
            }
            
            int other_size = num_nodes - component_size;
            int current_min = min(component_size, other_size);
            bool is_small = (component_size <= other_size);
            
            long long current_value = (long long)current_min + small_count[b] - (is_small ? 1 : 0);
            
            if (current_value < min_value) {
                min_value = current_value;
                node_a = a;
                node_b = b;
            }
        }

        // Build the modified tree (T')
        t_prime_nodes = num_nodes - 1;
        t_prime_root = node_a;
        
        for (int i = 1; i <= num_nodes; i++) {
            modified_tree[i].clear();
        }
        
        for (int v = 1; v <= num_nodes; v++) {
            if (v == node_b) continue;
            for (int u : original_tree[v]) {
                if (u == node_b) continue;
                modified_tree[v].push_back(u);
            }
        }
        
        for (int u : original_tree[node_b]) {
            if (u == node_a) continue;
            modified_tree[node_a].push_back(u);
            modified_tree[u].push_back(node_a);
        }

        // Second DFS to find the centroid
        traversal_size = 0;
        fill(child_index, child_index + num_nodes + 1, 0);
        fill(centroid_parent, centroid_parent + num_nodes + 1, -1);
        
        centroid_parent[t_prime_root] = 0;
        vector<int> dfs_stack2;
        dfs_stack2.reserve(t_prime_nodes);
        dfs_stack2.push_back(t_prime_root);
        
        while (!dfs_stack2.empty()) {
            int v = dfs_stack2.back();
            if (child_index[v] < (int)modified_tree[v].size()) {
                int u = modified_tree[v][child_index[v]++];
                if (u == centroid_parent[v]) continue;
                centroid_parent[u] = v;
                dfs_stack2.push_back(u);
            } else {
                dfs_stack2.pop_back();
                traversal_order[traversal_size++] = v;
            }
        }

        for (int i = 0; i < traversal_size; i++) {
            int v = traversal_order[i];
            centroid_subtree[v] = 1;
            for (int u : modified_tree[v]) {
                if (u == centroid_parent[v]) continue;
                centroid_subtree[v] += centroid_subtree[u];
            }
        }

        int centroid = t_prime_root, best_heavy = t_prime_nodes;
        for (int idx = 0; idx < traversal_size; idx++) {
            int v = traversal_order[idx];
            int heavy = t_prime_nodes - centroid_subtree[v];
            for (int u : modified_tree[v]) {
                if (u == centroid_parent[v]) continue;
                heavy = max(heavy, centroid_subtree[u]);
            }
            if (heavy < best_heavy) {
                best_heavy = heavy;
                centroid = v;
            }
        }

        // Group nodes for coloring
        fill(visited, visited + num_nodes + 1, false);
        visited[node_b] = true;
        visited[centroid] = true;

        node_groups.clear();
        node_groups.push_back(vector<int>(1, centroid));
        int group_count = 1;
        
        for (int u : modified_tree[centroid]) {
            if (visited[u]) continue;
            node_groups.push_back(vector<int>());
            stack<int> group_stack;
            group_stack.push(u);
            visited[u] = true;
            
            while (!group_stack.empty()) {
                int v = group_stack.top(); 
                group_stack.pop();
                node_groups[group_count].push_back(v);
                
                for (int w : modified_tree[v]) {
                    if (!visited[w]) {
                        visited[w] = true;
                        group_stack.push(w);
                    }
                }
            }
            group_count++;
        }

        // Color the nodes using a priority queue
        priority_queue<pair<int, int>> color_queue;
        for (int i = 0; i < (int)node_groups.size(); i++) {
            if (!node_groups[i].empty()) {
                color_queue.push({(int)node_groups[i].size(), i});
            }
        }

        fill(node_color, node_color + num_nodes + 1, 0);
        node_color[node_b] = 0;

        int current_color = 1;
        while (color_queue.size() > 1) {
            auto group1 = color_queue.top(); color_queue.pop();
            auto group2 = color_queue.top(); color_queue.pop();
            
            int id1 = group1.second, id2 = group2.second;
            int v1 = node_groups[id1].back(); node_groups[id1].pop_back();
            int v2 = node_groups[id2].back(); node_groups[id2].pop_back();
            
            node_color[v1] = current_color;
            node_color[v2] = current_color;
            current_color++;
            
            if (!node_groups[id1].empty()) {
                color_queue.push({(int)node_groups[id1].size(), id1});
            }
            if (!node_groups[id2].empty()) {
                color_queue.push({(int)node_groups[id2].size(), id2});
            }
        }

        // Output results
        int u_result = node_a, v_result = node_b;
        if (max(u_result, v_result) != node_b) {
            swap(u_result, v_result);
        }
        
        cout << u_result << " " << v_result << "\n";
        for (int i = 1; i <= num_nodes; i++) {
            cout << node_color[i] << (i == num_nodes ? '\n' : ' ');
        }
    }

    return 0;
}

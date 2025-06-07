#include <bits/stdc++.h>
 
using namespace std;
using ll = long long;
 
//#define int long long
#define FOR(i, a, b) for (int i = (a); i <= (b); i++)
#define FORD(i, a, b) for (int i = (b); i >= (a); i --)
#define REP(i, a) for (int i = 0; i < (a); ++i)
#define REPD(i, a) for (int i = (a) - 1; i >= 0; --i)
 
#define MASK(i) (1LL << (i))
#define BIT(x, i) (((x) >> (i)) & 1)
 
 
constexpr ll LINF = (1ll << 60);
constexpr int INF = (1ll << 30);
constexpr int Mod = 1e9 + 7;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
 
/*
    Phu Trong from Nguyen Tat Thanh High School for gifted student
*/
 
template <class X, class Y>
    bool minimize(X &x, const Y &y){
        X eps = 1e-9;
        if (x > y + eps) {x = y; return 1;}
        return 0;
    }
 
template <class X, class Y>
    bool maximize(X &x, const Y &y){
        X eps = 1e-9;
        if (x + eps < y) {x = y; return 1;}
        return 0;
    }
#define MAX                 100005
#define LOG                     18
vector<int> G[MAX];
int numNode, numQuery;
int pa[MAX], root;
 
int depth[MAX], paint[MAX], jmp[MAX][LOG];
int min_value[MAX];
void pre_dfs(int u, int p = -1){
    min_value[u] = u;
    for (int&v : G[u]) if(v ^ p){
        depth[v] = depth[u] + 1;
        jmp[v][0] = u;
 
        for (int i = 1; i < LOG; ++i) jmp[v][i] = jmp[jmp[v][i - 1]][i - 1];
        pre_dfs(v, u);
        minimize(min_value[u], min_value[v]);
    }
}
int order[MAX], cnt = 0;
void dfsOrder(int u, int p = -1){
    for (int&v : G[u]) if(v ^ p){
        dfsOrder(v, u);
    }
    order[u] = ++cnt;
}
 
 
void process(void){
    cin >> numNode >> numQuery;
    for (int i = 1; i <= numNode; ++i){
        cin >> pa[i];
        if(pa[i] == 0) {
            root = i; continue;
        }
        G[i].emplace_back(pa[i]);
        G[pa[i]].emplace_back(i);
    }
    pre_dfs(root);
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> q;
    for (int i = 1; i <= numNode; ++i){
        sort(G[i].begin(), G[i].end(), [&](const int u, const int v){
            return min_value[u] < min_value[v];
        });
    }
    dfsOrder(root);
 
 
    for (int i = 1; i <= numNode; ++i){
        q.emplace(order[i], i);
    }
 
    for (int i = 1; i <= numQuery; ++i){
        int c; cin >> c;
        if(c == 1){
            int x; cin >> x;
            int last = -1;
            while(x --){
                int u = q.top().second; q.pop();
                paint[u] = true;
                last = u;
            }
            assert(last != -1);
            cout << last << '\n';
        }
        else{
            int u; cin >> u;
            int prv = u;
            for (int j = LOG - 1; j >= 0; --j) if(jmp[u][j] > 0 && paint[jmp[u][j]]){
                u = jmp[u][j];
            }
            paint[u] = false;
            q.emplace(order[u], u);
            cout << depth[prv] - depth[u] << '\n';
        }
    }
}
signed main(){
    #define name "Whisper"
    cin.tie(nullptr) -> sync_with_stdio(false);
    //freopen(name".inp", "r", stdin);
    //freopen(name".out", "w", stdout);
    process();
    return (0 ^ 0);
}
 
 


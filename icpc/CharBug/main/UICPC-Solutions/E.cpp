#include <bits/stdc++.h>

// #pragma GCC optimize ("Ofast")
 
#define oo (1000'000'000'000'000'000LL)
#define ooo __builtin_inf()
#define cif(i, n) for(int i = 0; i < n; i++)
#define ccif(i, l, r) for(int i = l; i < r; i++)
#define rif(i, n) for(int i = n-1; i >= 0; i--)
#define scan(a, __n) for(int __ = 0; __ < __n; __++)cin >> a[__];
#define print(a, __n) for(int ___ = 0; ___ < __n; ___++)cout << a[___] << ' '; cout << '\n';
#define sz(s) ((int)s.size())
#define dbg(x) cerr << #x << " : " << x << endl;
//  #define int ll

#define fastIO ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);

#define ff first
#define ss second
 
#define all(v) v.begin(), v.end()
#define uni(v) sort(all(v)), v.resize(unique(all(v))-v.begin());
 
// #define c0 (v<<1)
// #define c1 (c0|1)
// #define md ((l+r)/2)
 
using namespace std;

typedef long long ll;
typedef double ld;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef vector<int> vi;
typedef vector<ll> vl;
typedef vector<pii> vii;
typedef vector<pll> vll;



const int mod = 1e9+7;
// const int maxN = 1e6+7;
const string fileName = "";

// const int maxFac = 1e6+7; 
// ll fac[maxFac], _fac[maxFac];

// ll po(ll b, ll p){
//     b %= mod;
//     p %= mod-1;
//     ll r = 1;
//     while(p){
//         if(p&1)r = r*b%mod;
//         p >>= 1;
//         b = b*b%mod;
//     }
//     return r;
// }

// ll choose(ll k, ll n){
//     return fac[n]*_fac[k]%mod*_fac[n-k]%mod;
// }

// ll factorial(ll n, ll k){
//     ll ret = 1;
//     for(ll i = n; i >= n-k+1; i--){
//         ret = ret*i%mod;
//     }
//     return ret;
// }

const int maxN = 5e5+7;
int x[maxN], y[maxN], n, m;
vl dx, dy;
ll pefx[maxN], pefy[maxN];
ll pefx2[maxN], pefy2[maxN];
ll s;

ll sumx(int l, int r){
    return pefx[r] - pefx[l];
}

ll sumx2(int l, int r){
    return pefx2[r] - pefx2[l];
}

ll sumy(int l, int r){
    return pefy[r] - pefy[l];
}

ll sumy2(int l, int r){
    return pefy2[r] - pefy2[l];
}

void slv(){
    cin >> n >> m;
    scan(x, n);
    scan(y, m);
    for(int i = 1; i < n; i++){
        dx.push_back(x[i] - x[i-1]);
    }
    for(int j = 1; j < m; j++){
        dy.push_back(y[j] - y[j-1]);
    }
    sort(all(dx));
    sort(all(dy));
    for(int j = 0; j < sz(dy); j++){
        pefy[j+1] = pefy[j] + dy[j];
        pefy2[j+1] = pefy2[j] + dy[j]*dy[j];
    }
    for(int i = 0; i < sz(dx); i++){
        pefx[i+1] = pefx[i] + dx[i];
        pefx2[i+1] = pefx2[i] + dx[i]*dx[i];
    }
    //print(dy, sz(dy));
    function cal = [] (vl& dx, vl& dy, ll& s, function<ll(int, int)> sumy, function<ll(int, int)> sumy2, bool calEqual) -> void {
        
    for(int i = 0; i < sz(dx); i++){
        ll a = dx[i];
        int gte_2a = lower_bound(all(dy), 2*a) - dy.begin();
        int gte_3_2a = lower_bound(all(dy), 2.999999999*a/2.) - dy.begin();
        int gte_a;
        if(calEqual){
            gte_a = lower_bound(all(dy), a) - dy.begin();
        }
        else{
            gte_a = upper_bound(all(dy), a) - dy.begin();
        }
        // cout << a << ' ' << gte_2a << ' ' << gte_3_2a << ' ' << gte_a << '\n';
        
            // if(a > b)swap(a, b);
            // pair<ll, pll> ans2;
            // ll kk;
            ll ans = 0;

            // if(a*2 <= b){
                // kk = 2*a*a;
                ans += (2*a*a) * (sz(dy) - gte_2a);
                // ans2 = {a*a*2, {a, a}};
            // }
            // cout << ans << ' ';
            // else if(a*3 <= b*2){
                // ll y = b-a;
                // kk = 6*a*a + 2*b*b - 6*a*b;
                ans += (6*a*a) * (gte_2a - gte_3_2a);
                ans += (2*sumy2(gte_3_2a, gte_2a));
                ans -= (6*a*sumy(gte_3_2a, gte_2a));
                // ans2 = {a*a + y*y + (a-y)*(a-y), {a, y}};
            // }
            // cout << ans << ' ';
            // else{
                // ll y = a/2;
                // ll x = b - y;
                // kk = 3*a*a + 2*b*b - 4*a*b;
                ans += (3*a*a) * (gte_3_2a - gte_a);
                ans += (2*sumy2(gte_a, gte_3_2a));
                ans -= (4*a*sumy(gte_a, gte_3_2a));
                // ans2 = {x*x + y*y + (a-x)*(a-x) + (a-y)*(a-y), {x, y}};
            // }
            // cout << ans << '\n';
            
            s += ans;
        // }
    }
    };

    cal(dx, dy, s, sumy, sumy2, 1);
    cal(dy, dx, s, sumx, sumx2, 0);

    cout << s << '\n';
}



signed main(){
    if(fileName.size() > 0){
        freopen("team.in", "r", stdin);
        freopen("team.out", "w", stdout);
    }

    fastIO;
    // cout << fixed << setprecision (15);


    // fac[0] = 1;
    // for(int i = 1; i < maxFac; i++)fac[i] = fac[i-1]*i%mod;
    // _fac[maxFac-1] = po(fac[maxFac-1], mod-2);
    // for(int i = maxFac-2; i >= 0; i--)_fac[i] = _fac[i+1]*(i+1)%mod;

    // w[0] = 1;
    // for(int i = 1; i < maxN; i++)w[i] = w[i-1]*p%mod;
    // _w[maxN-1] = po(w[maxN-1], mod-2);
    // for(int i = maxN-2; i >= 0; i--)_w[i] = _w[i+1]*p%mod;
    
    
    int t = 1;
    // cin >> t;
    while(t--){
        // cout << slv() << '\n';
        slv();
        // string s;
        // cin >> s;
        // bool x = slv();
        // cout << (x?"YES":"NO") << '\n';
    }
}       
/*

*/

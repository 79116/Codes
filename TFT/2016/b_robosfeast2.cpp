#include "bits/stdc++.h"

using namespace std;

#define fori(i, a, b) for(int i = (int) (a); i <= (int) (b); ++i)
#define ford(i, a, b) for(int i = (int) (a); i >= (int) (b); --i)
#define forIT(it, begin, end) for(__typeof(end) it = (begin) + ((begin) > (end)); it != (end) - ((begin) > (end)); it += 1 - 2 * ((begin) > (end)))

#define fi first
#define se second
#define b_e(x) begin(x), end(x)
#define ii pair<int, int>
#define vi vector<int> 
#define vvi vector<vi>

#define pb push_back
#define pf push_front
#define eb emplace_back
#define em emplace
#define ob pop_back
#define om pop
#define of pop_front

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
#define rand rng
#define endl '\n'
#define sp ' '

void solve();

int32_t main() {
	freopen("robosfeast2.inp","r",stdin);
 freopen("b_robosfeast2.out","w",stdout);
   ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
   int test_num = 1;
   fori(test, 1, test_num) {
      solve();
   }
   return 0;
}

#define ld long double
#define int long long
const ld pi = 4 * atan(1.0), eps = 1e-9;
const int maxn = 2e5 + 5; 
int n, q; 
vi g[maxn]; 
int d[maxn]; 
ld ans[maxn]; 
void salt(int u, ld x, int p) { 
	int s = d[u]; 
	for(int v: g[u]) { 
		if(v - p) s += d[v]; 
	}
	ans[u] += x * d[u] / s; 
	for(int v: g[u]) { 
		if(v - p) salt(v, x * d[v] / s, u); 
	}
}
void solve() {
	cin >> n >> q; 
	fori(i, 1, n) cin >>  d[i]; 
	fori(i, 1, n - 1) { 
		int u, v; cin >> u >> v; 
		g[u].eb(v); 
		g[v].eb(u); 
	}
	fori(i, 1, q) { 
		int c; ld x; 
		cin >> c >> x;
		salt(c, x, -1); 
	}
	fori(i, 1, n) cout << fixed << setprecision(10) << ans[i] << endl; 
}


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
 freopen("robosfeast2.out","w",stdout);
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
/* 
the main idea is: we can execute \sum_{i \in [1, n]} share (i, p, val) in O(n). 

so we need to turn \sum_{i \in [1, n]} share (i, i, val) to a bunch of share (i, p, val). 

we have: share(u, u, x)
= share(u, p, x) + share(p, u, x * d_p / s_u) 
= share(u, p, x) + share(p, p, x * d_p / s_u * s_p / (s_p - d_u)) - share(u, p, x * d_p / s_u * d_u / (s_p - d_u))

so we can dp upward to do the transformation. 
*/
int n, q; 
vi g[maxn]; 
ld s[maxn]; 
int d[maxn]; 
ld share[maxn]; 
ld down_share[maxn]; 
ld ans[maxn]; 
ld up[maxn]; 
ld down[maxn]; 
int root; 
void dp_up(int u, int p) { 
	for(int v: g[u]) { 
		if(v - p) { 
			dp_up(v, u); 
			// resolving share(v, v, x)
			ld x = share[v]; 
			share[u] += x * d[u] * s[u] / (s[u] - d[v]) / s[v]; 
			down_share[v] = x * (s[v] - d[u]) / s[v] - x * d[u] * d[v] / (s[u] - d[v]) / s[v] ; 
		}
	}
}
void dp_down(int u, int p) { 
	ld x = down_share[u]; //cout << u << sp << x << endl; 
	ans[u] += x * d[u] / (u == root? s[u]: s[u] - d[p]); 
	for(int v: g[u] ) { 
		if(v - p) { 
			down_share[v] += x * d[v] / (u == root? s[u]: s[u] - d[p]); 
			dp_down(v, u); 
		}
	}
}
void solve() {
	cin >> n >> q; 
	fori(i, 1, n) { 
		cin >> d[i]; 
		s[i] = d[i]; 
	}
	fori(i, 1, n - 1) { 
		int u, v; cin >> u >> v; 
		s[u] += d[v]; 
		s[v] += d[u]; 
		g[u].eb(v); g[v].eb(u); 
	}
	fori(i,1, q) { 
		int u;
		double val; cin >> u >> val; 
		share[u] += val; 
	}
	root = 1; 
	dp_up(root, root); 
	down_share[root] = share[root]; 
//	fori(i, 1, n) { 
//		cout << i << sp << down_share[i] << endl; 
//	}
	dp_down(root, root); 
	fori(i, 1, n) cout << fixed << setprecision(10) << ans[i] << endl; 
}
/*
6 2 
2 1 3 1 2 3 
1 2 
1 3 
3 4 
3 5 
3 6
1 12.00
3 11.00
6 1 
2 1 3 1 2 3 
1 2 
1 3 
3 4 
3 5 
3 6
1 12.00
*/


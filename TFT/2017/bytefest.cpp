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
 freopen("bytefest.inp","r",stdin);
 freopen("bytefest.out","w",stdout);
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
const int maxn = 2005; 
int n, m; 
int h[maxn]; 
int l[maxn]; 
vector<ii> g[maxn]; 
int dep[maxn]; 
int dp[maxn][maxn]; 
int best[maxn]; 
vector<int> subtree[maxn]; 
void get_dp(int u, int p) { 
	subtree[u].eb(u); 
	for(ii e: g[u]) {
		int v = e.fi, id = e.se;  
		if(v - p) { 
			dep[v] =  dep[u] + l[id]; 
			get_dp(v, u); 
			for(int t: subtree[v]) subtree[u].eb(t); 
		}
	}
	int sum = 0; 
	for(ii e: g[u]) { 
		int v = e.fi, id = e.se; 
		if(v - p) { 
			sum += best[v];
		}
	}
	dp[u][0] = dp[u][u] = sum; 
	for(ii e1: g[u]) { 
		for(ii e2: g[u]) { 
			int v1 = e1.fi, id1 = e1.se;
			int v2 = e2.fi, id2 = e2.se; 
			if(v1 - p and v2 - p and v1 - v2) { 
				for(int t1: subtree[v1]) { 
					for(int t2: subtree[v2]) { 
						if(dep[t1] + dep[t2] - 2 * dep[u] <= m) 
							dp[u][0] = max(dp[u][0], sum - best[v1] - best[v2] + h[id1] + dp[v1][t1] + h[id2] + dp[v2][t2]); 
					}
				}
			}
		}
	}
	for(ii e: g[u]) { 
		int v = e.fi, id = e.se; 
		if(v - p) { 
			for(int t: subtree[v]) { 
				if(dep[t] - dep[u] <= m) { 
					dp[u][t] = sum - best[v] + h[id] + dp[v][t]; 
				}
			}
		}
	}
	fori(i, 0, n) best[u] = max(best[u], dp[u][i]); 
}
void solve() {
	cin >> n >> m; 
	fori(i, 1, n - 1) { 
		int u, v; cin >> u >> v >> l[i] >> h[i]; 
		g[u].eb(v, i); 
		g[v].eb(u, i); 
	}
	get_dp(1, 1); 
	cout << best[1]; 
}

